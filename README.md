# Bezier-Curves

The second project for our math class, MAT 500: Curves and Surfaces, at 
DigiPen Institute of Technology. We had to create an application that generates 
Bezier Curves based on control points that the user places on the screen.

Curves can be calculated using any of the three methods:
1. De-Casteljau algorithm or Nested Linear Interpolation (NLI)
2. BB-Form
3. Midpoint Subdivision

Made in Qt 5.15.0 using the qcustomplot library

-------------------------------------------

Name: Srey Raychaudhuri
DigiPen ID: 60000721

MAT 500 Project 2

-------------------------------------------

Project file and source code are in 
"Project" Folder

To open project:

Project > MAT500Project2.pro

-------------------------------------------

To run executable: 

Build > release > MAT500Project2.exe

-------------------------------------------

Instructions to use application:

Double-Click to add a new point
Left click on a point and drag to drag a point
Use the Drop-Down menu to select calculation method
Use the Checkbox to toggle display of shell points - only works when "NLI" is selected
Drag the Horizontal Slider to adjust the t value (0-1) - only works when "NLI" is selected


