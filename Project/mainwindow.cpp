/*-----------------------------
 * MAT 500 PROJECT 2
 * Program by Srey Raychaudhuri
 * ID: 60000721
 * ----------------------------
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Setting up and initializing UI
    ui->setupUi(this);

    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);

    // Adding graphs and styling
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();

    // Intializing curve objects
    bezierCurve = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);
    controlPoints = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);

    // Setting colors for two sets of data
    bezierCurve->setPen(QPen(Qt::red));
    controlPoints->setPen(QPen(Qt::blue));

    controlPoints->setScatterStyle(QCPScatterStyle::ssCircle);

    // White screen - no axes visible
    ui->customPlot->xAxis->setVisible(false);
    ui->customPlot->yAxis->setVisible(false);

    bezierCurveData.resize(101);

    qDebug() << controlPointsData.size();
    controlPointCount = 0;
    tValForShellPointDisplay = 0.5f;
    shellDisplayToggle = true;

    // Setting mouse input signals and slots
    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), SLOT(onPointDrag(QMouseEvent*)));
    connect(ui->customPlot, SIGNAL(mouseDoubleClick(QMouseEvent*)), SLOT(AddPoint(QMouseEvent*)));

    // Set Up Pascal's Triangle
    CreatePascalsTriangle();
    PrintPascalsTriangle();    
}


void MainWindow::PrintPascalsTriangle() {
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            qDebug() << pascalsTriangle[i][j];
        }
    }
}

/* Function that creates a 20 x 20 Pascal's Triangle
 * 1 0 0 ...... 0
 * 1 1 0 ...... 0
 * 1 2 1 ...... 0
 * 1 3 3 1 .... 0
 * .....
*/
void MainWindow::CreatePascalsTriangle() {

    pascalsTriangle.resize(31);

    for (int i = 0; i < 31; i++) {
        pascalsTriangle[i].resize(31);
    }

    pascalsTriangle[0][0] = 1;

    for(int i = 1; i < 31; i++) {
        pascalsTriangle[i][0] = 1;
        for(int j = 1; j < i+1; j++) {
            pascalsTriangle[i][j] = pascalsTriangle[i-1][j-1] + pascalsTriangle[i-1][j];
        }
    }
}


// Destroy all curves
MainWindow::~MainWindow() {
    delete ui;
}

// Function to calculate P(t) using Berntein's Polynomial Summation
PointPair MainWindow::BBForm(double t) {

    PointPair result = {0, 0};

    int degree = controlPointCount - 1;
    for(int i = 0; i < controlPointCount; i++) {
        // dCi is taken from pre-computed Pascal's triangle
        result.x += (controlPointsData[i].key *  pascalsTriangle[degree][i] * pow((1-t), degree - i) * pow(t, i));
        result.y += (controlPointsData[i].value *  pascalsTriangle[degree][i] * pow((1-t), degree - i) * pow(t, i));
    }
    return result;
}


void MainWindow::AddShellCurve() {

    // Creating a new QCPCurve that will store data for displaying
    // a new shell line and adding it to the vector of shell lines
    QCPCurve* newShellPointLine = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);

    // Setting shell line visuals
    newShellPointLine->setPen(QPen(QColor(0, 120, 120)));
    newShellPointLine->setScatterStyle(QCPScatterStyle::ssCircle);

    shellPointsLines.push_back(newShellPointLine);

}


void MainWindow::ClearShellPointVectors() {

    if (shellsData.size() > 0) {

        // Clearing the shell vectors used for prev calcs.
        for (int i = 0; i < controlPointCount - 1; i++) {
            shellsData[i].clear();
        }
    }
    shellsData.clear();
}



PointPair MainWindow::NLI(double t) {

    PointPair result = {0, 0};

    int shellCount = controlPointCount - 1;

    shellsData.resize(1);

    /* Copying all Control point QCPCurveData data to the first
     * row of the shell matrix
     */
    for(int i = 0; i < controlPointsData.size(); i++) {
        shellsData[0].push_back(controlPointsData[i]);
    }


    do {
        // A temp vector to hold shell data for this LI step
        QVector<QCPCurveData> newShells;

        int row = controlPointCount - shellCount - 1;

        /* Calculating a new set of shell data and adding to the list of
         * updated shell points for the next stage */
        for (int i = 0; i < shellCount; i++) {

            float newShellPosX = (1-t) * shellsData[row][i].key + t * shellsData[row][i+1].key;
            float newShellPosY = (1-t) * shellsData[row][i].value + t * shellsData[row][i+1].value;

            newShells.push_back(QCPCurveData(i, newShellPosX, newShellPosY));
        }

        // Adding this vector of calculated data to the original shell matrix
        // Has all shells calculated in this stage
        shellsData.push_back(newShells);

        qDebug() << shellsData.size();
        shellCount--;
    }

    // Until there's only one shell left
    while (shellCount >= 1);

    qDebug() << shellsData.size();

    //Displaying Shell Lines
    if (t == tValForShellPointDisplay) {
        if (shellDisplayToggle) {
            for (int i = 0; i < shellPointsLines.size(); i++) {
                shellPointsLines[i]->data()->set(shellsData[i+1]);
            }
        }
        else {
            QVector<QCPCurveData> emptyVec;
            for (int i = 0; i < shellPointsLines.size(); i++) {
                shellPointsLines[i]->data()->set(emptyVec);
            }
        }
    }


    // Result will be in the first col. and last row of this vec of vecs
    result.x = shellsData[controlPointCount - 1][0].key;
    result.y = shellsData[controlPointCount - 1][0].value;

    return result;
}



/* Function to the calculate the bezier curve using
 * Midpoint subdivision
 */
void MainWindow::MidpointSubdivision()
{
    int numberOfPointsOnLine = controlPointCount;

    // Have one row. This will hold the control points
    midpointData.resize(1);

    // Copy the control points to the first row of the 2D Matrix
    for (int i = 0; i < controlPointCount; i++) {
        midpointData[0].push_back(controlPointsData[i]);
    }

    // first row is for CPs. So the rest are for midpoint levels

    while (true) {

        int midpointLevels = controlPointCount - 1;

        do {
            // A temp vector to hold midpoint data for this step
            QVector<QCPCurveData> newMidpoints;

            int row = controlPointCount - midpointLevels - 1;

            /* Calculating a new set of midpoint data and adding to
             * the list of updated midpoints for the next stage */

            int i = 0;

            while (i < numberOfPointsOnLine) {

                if (i+1 >= numberOfPointsOnLine) {
                    newMidpoints.push_back(QCPCurveData(i, 0, 0));
                }
                else if (midpointData[row][i].key == midpointData[row][i+1].key ||
                    midpointData[row][i+1].key == 0 || i+1 >= numberOfPointsOnLine) {

                    newMidpoints.push_back(QCPCurveData(i, 0, 0));
                }
                else {
                    float newMidpointPosX = 0.5f * midpointData[row][i].key + 0.5f * midpointData[row][i+1].key;
                    float newMidpointPosY = 0.5f * midpointData[row][i].value + 0.5f * midpointData[row][i+1].value;

                    newMidpoints.push_back(QCPCurveData(i, newMidpointPosX, newMidpointPosY));
                }
                i++;
            }

            // Adding this vector of calculated data to the original midpoint matrix
            // Has all midpoints calculated in this stage
            midpointData.push_back(newMidpoints);

            midpointLevels--;
        }
        while (midpointLevels >= 1);

        // QVector<QCPCurveData> newPoints;
        newPoints.clear();

        // Copying the new control points from the 2D matrix
        // to the a new vector - that the curve will be fed
        // after the last iteration

        int i = 0,j = 0, k = 0;
        int col = 0;

        for (i = 1; i <= numberOfPointsOnLine/controlPointCount; i++) {

            for (j = 0; j < controlPointCount; j++) {
                newPoints.push_back(midpointData[j][col]);
            }

            for (k = col, j = j-1; j >= 0; j--, k++) {
                newPoints.push_back(midpointData[j][k]);
            }

            col = k;
        }

        numberOfPointsOnLine *= 2;

        // clearing old vector before use
        for(int i = 0; i < midpointData[0].size(); i++) {
            midpointData[i].clear();
        }

        midpointData.clear();


        // Have one row. This will hold the control points
        midpointData.resize(1);

        // Copy the control points to the first row of the 2D Matrix
        for (int i = 0; i < newPoints.size(); i++) {
            midpointData[0].push_back(newPoints[i]);
        }

        // If enough points are gathered to plot a smooth-looking curve
        if (numberOfPointsOnLine >= 100) {
            break;
        }
    }

    // Removing duplicate points
    for (int i = 0; i+1 < newPoints.size(); i++) {
        if(newPoints[i].key == newPoints[i+1].key) {
            newPoints.removeAt(i);
        }
    }

    // Setting the order correct
    for (int i = 0; i < newPoints.size(); i++) {
        newPoints[i].t = i;
    }

    // Plot the points
    bezierCurve->data()->set(newPoints);

    // Clearing the midpoint data vectors

    newPoints.clear();

    for(int i = 0; i < midpointData[0].size(); i++) {
        midpointData[i].clear();
    }

    midpointData.clear();
}




// Function to plot the graphs
void MainWindow::MakePlot() {

    if (ui->comboBox->currentText() == "MidPtSubDiv") {
        if (controlPointCount > 2) {
            MidpointSubdivision();
        }
    }
    else {
        PointPair polyLinePlot;

        // Plotting the curve
        for (int i=0; i < 101; i++)
        {
          float t = i/100.0f; // x goes from 0 to 1

          // Use NLI method
          if (ui->comboBox->currentText() == "NLI") {

              if (controlPointCount > 1) {

                polyLinePlot = NLI(t);
                ClearShellPointVectors();
              }
          }

          // Use BB-Form Method
          else {
            polyLinePlot = BBForm(t);
          }
          bezierCurveData[i] = QCPCurveData(i, polyLinePlot.x, polyLinePlot.y);
        }

        // Setting bezier curve data
        bezierCurve->data()->set(bezierCurveData, true);
    }

    // Setting control point data
    controlPoints->data()->set(controlPointsData, true);


    // Replotting and updating the graphs
    ui->customPlot->replot();
    ui->customPlot->update();
}



// Function fired when mouse is clicked and dragged
void MainWindow::onPointDrag(QMouseEvent *event) {

    // Finding the point nearest to the point where the mouse is clicked and dragged
    QPoint point = event->pos();
    for (int i = 0; i < controlPointsData.size(); i++) {

        if (fabs(controlPointsData[i].key - ui->customPlot->xAxis->pixelToCoord(point.x())) <= 0.2
         && fabs(controlPointsData[i].value - ui->customPlot->yAxis->pixelToCoord(point.y())) <= 0.2) {

            controlPointsData[i].key = ui->customPlot->xAxis->pixelToCoord(point.x());
            controlPointsData[i].value = ui->customPlot->yAxis->pixelToCoord(point.y());
        }
    }

    // Redraw graphs
    MakePlot();
}



// Funtion to add a point on the screen
void MainWindow::AddPoint(QMouseEvent *event)
{
    QPoint point = event->pos();

    float controlPointX = ui->customPlot->xAxis->pixelToCoord(point.x());
    float controlPointY = ui->customPlot->yAxis->pixelToCoord(point.y());

    controlPointsData.push_back(QCPCurveData(++controlPointCount, controlPointX, controlPointY));

    //ClearShellPointVectors();

    if (controlPointCount > 1) {
        AddShellCurve();
    }

    MakePlot();
}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    tValForShellPointDisplay = value/100.0f;
    MakePlot();
}


void MainWindow::on_comboBox_currentTextChanged(const QString &method)
{
    // If method selected isn't NLI
    // Empty out the shell vector data
    if (method != "NLI") {
        QVector<QCPCurveData> emptyVec;
        for (int i = 0; i < shellPointsLines.size(); i++){
            shellPointsLines[i]->data()->set(emptyVec);
        }
    }

    MakePlot();
}


void MainWindow::on_checkBox_toggled(bool checked)
{
    shellDisplayToggle = checked;
    MakePlot();
}

