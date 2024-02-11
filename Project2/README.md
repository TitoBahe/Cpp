Project specs: 
The Calculator

Create an application that implements the functionality of a scientific computer.


The computer will have the following functionalities:

can evaluate mathematical expressions containing round and/or square brackets
supports the following operations: addition, subtraction, multiplication, division, power, radical
the computer must be able to process any equation and display the result on the screen
equations will be entered from the keyboard. The user will write the equation on a line, and upon pressing the Enter key, the application will display the result. The calculator will accept new equations until the user types "exit"
for invalid expressions the calculator will display an error message
External libraries may NOT be used for the part of parsing the expression or calculating the result
the solution must be implemented using only standard C++ libraries (such as iostream, string, fstream, etc.) used in courses and labs; STL classes are only supported when explicitly requested (phase 2 only)

Additional requirements for teams:

Phase 1: The computer can solve equations of degree 1 using x as the unknown in the set of real numbers. Example: for input 2*x + (6-x) = 12 x = 6 will be displayed
Phase 2: the calculator can solve equations of degree 2 using x as unknown in the set of real numbers (solutions in the set of complex numbers will be ignored) Example: for the input x^2 - 5x + 6 = 0 it will display x = 2 and x = 3 since both are real solutions of the equation


Examples of equations used as input:


[40+(5-1)]*2 will show 88
5 / 0 will error because dividing by 0 makes no sense
[(2*3)^2]/4-(6+2)#3, where x^y means x to the power of y and x#y radical of order y of x, will display 7
2 * 3.2 will display 6.4
24342343.0002-3 will display 24342340.0002
2 * 3 - 8 will display -2





Step 1:
Deadline: December 3, 2023
At least 3 classes related to the project
Classes must contain (in total, not each) at least one dynamically allocated vector of characters, one dynamically allocated numeric vector, one constant field, one static field, and one static method. Members must be related to the class.
All attributes will be defined in the private area of the class
All attributes will have access methods; setters will contain validations
Each class will contain at least 2 generic methods (other than constructors or accessors) that will be used to perform various processing
Each class will contain at least one default constructor and one with parameters. Classes with pointer members will follow the "rule of 3".
Each class will contain overloads for the << and >> operators
Each class will have at least 2 overloaded operators from the following (the same operator cannot be overloaded in 2 different classes):
indexing operator []
arithmetic operators (+,-,* or /)
++ or -- (both forms)
implicit or explicit cast
negation operator !
relational operators (<.>,=<,>=,==)
Classes will be implemented in their own header and/or cpp file
The main function will be located in another cpp file
This phase is considered implemented if at least 75% of the requirements are implemented


At least Phase 1


1 point - compliance with the loading and structuring requirements of the project
3 points - each class correctly implemented like this:
1 point - the correct implementation of the class (according to the requirements - attributes, constructors, getters, setters, the rule of 3)
1 point - generic methods related to the class
1 point - operators (display and calculation)
-5 points - classes are not functional and cannot solve even simple equations of the type that use operators +,-,*,/ and do not use parentheses (last 3 examples)

* classes not related to the project will not be considered







Phase 2:

Deadline: January 14, 2022
The program can receive the equation as a parameter on the command line (example: if the application is called oop.exe, then it can be launched as follows: oop.exe [4+(5-1)]*2)
The application can process the equations from a text file (one equation per line) and will display the results to the console or to another text file (the user can choose between the two options)
The application will use binary files to save the results of previous equations when the user so desires. For example the user can choose to save the current result in a variable and then use the variable in the next equation)
All entities needed to implement the above functionality will be added to existing classes (or new classes related to the project can be defined)
A menu will be implemented to help the user navigate through the various functionalities (input equation, save current result, read equations from file, etc.)
At least one new class will be created by deriving from an existing class
The application will contain at least one abstract class (can also be interface)