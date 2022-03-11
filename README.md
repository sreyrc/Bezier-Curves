# Bezier-Curves

The second project for our math class, MAT 500: Curves and Surfaces, at 
DigiPen Institute of Technology. We had to create an application that generates 
Bezier Curves based on control points that the user places on the screen.

Curves can be calculated using any of the three methods:
1. De-Casteljau algorithm or Nested Linear Interpolation (NLI)
2. BB-Form
3. Midpoint Subdivision

Made in Qt 5.15.0 using the qcustomplot library

-----------------------

https://user-images.githubusercontent.com/59312045/157783386-0cc7b989-d551-486a-8a05-2a4261858c82.mp4

--------------------




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


