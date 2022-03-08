/*----------------------------
 * MAT 500 PROJECT 1
 * Program by Srey Raychaudhuri
 * ID: 60000721
 * ---------------------------
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct PointPair {
    float x, y;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Function to calculate P(t) using Berntein's Polynomial Summation
    PointPair BBForm(double t);

    // Function to calculate P(t) using Nested Linear Interpolation (NLI)
    PointPair NLI(double t);

    // Function to calculate P(t) using Midpoint Subdivision
    void MidpointSubdivision();

    // Function that prints out the Pascal's Triangle
    void PrintPascalsTriangle();

    // Function that creates a 20 x 20 Pascal's Triangle
    void CreatePascalsTriangle();

    // Function to plot the graphs
    void MakePlot();

    // Function fired when left mouse button is clicked and dragged
    void onPointDrag(QMouseEvent* event);

    // Function fired when the mouse button is double clicked
    void AddPoint(QMouseEvent* event);

    // Clear all shell points
    void ClearShellPointVectors();

    // Need to allocate a new QCPCurve to store a new shell line
    void AddShellCurve();

    // Function fired when slider value is changed. Sets new t value
    void on_horizontalSlider_valueChanged(int value);

    // Function fired on combo box text change.
    // To set claculation method
    void on_comboBox_currentTextChanged(const QString &arg1);

    // Function fired on checking or unchecking checkbox
    // To toggle visibility of shells
    void on_checkBox_toggled(bool checked);

private:
    // A 2D Matrix (conceptually) to store values of a Pascal's Triangle
    QVector<QVector<double>> pascalsTriangle;

    Ui::MainWindow *ui;

    // No. of control points
    int controlPointCount;
    float tValForShellPointDisplay;
    float tTemp;
    bool shellDisplayToggle;

    // The actual curve to be drawn
    QCPCurve* bezierCurve;
    QCPCurve* controlPoints;

    // A vector that stores the curve to be plotted
    QVector<QCPCurveData> bezierCurveData;
    QVector<QCPCurveData> controlPointsData;

    // Store all curves needed to be displayed
    QVector<QCPCurve*> shellPointsLines;

    // Vector of vectors (2D Matrix) to hold shell point data at every stage
    QVector<QVector<QCPCurveData>> shellsData;

    // The points to be plotted after Midpoint Subdivision
    QVector<QCPCurveData> newPoints;

    /* Data to hold the control points and midpoints
     * calculated at each stage of the MSD algorithm */
    QVector<QVector<QCPCurveData>> midpointData;
};
#endif // MAINWINDOW_H
