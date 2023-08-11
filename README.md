## Project Name: cub3d

## Summary: 
This project is inspired by the Wolfenstein 3D game. 
The aim is to create a “realistic” 3D graphical representation (by using the Ray-Casting principles) of the inside of a maze from a first-person perspective.

Important sections are: 
+ Parsing
+ Ray-casting 
+ Rendering

As a graphic design project, it enabled us to improve the skills in these areas: windows, colors, events, fill shapes, etc.
We explored the playful practical applications of mathematics based on the documents available, especially ones from : https://lodev.org/cgtutor/.

## Basic Features
+ Different wall textures are displayed, that vary depending on which side the wall is facing (North, South, East, West).
+ The program is be able to set the floor and ceiling colors to two different ones.
+ The mouse && keyboard events are handled
+ It has also a minimap system


## Usage

To compile the program, the provided Makefile can be used. There we defined some rules and they can be run by these basic commands:<br>
**make**: This command compiles the necessary source code files and links them to create the final executable.<br>
**make test**: This command runs valgrind for memory leaks and is used for debugging purposes.<br>
**make clean**: This command will remove any generated files and clean up the project directory.<br>

## Contributors
jpa-rocha<br>
GulenayMer<br>
