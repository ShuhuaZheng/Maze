#Maze Project 

## What is Maze Project about? 
* This project generates a random two-dimensional square maze whose size is specified by the user read in a maze from a given text file 
* Once the program generated a random maze or read in a maze from a file, the program would solve the maze by finding a path from the start position to the goal position in the maze. 
* Because of how the maze is generated or specified in the file, there will always be a path from the starting position to the goal position in the maze 

## The Maze Structure 
The maze is an n×n grid of cells (which we also call rooms), where n is a positive integer specified by the user. Each room in the maze can have at most 4 doors, each of which (if open) can lead to the adjacent room to the north, south, east, or west. There is a passage way between two adjacent rooms if and only if both doors connecting the two adjacent rooms are open. There are two special rooms in the maze called the start room and the goal room. The start room is always the upper-left room in the maze and the goal room is always the bottom-right room in the maze. The start room has its door leading to the north always open while the goal room has its door leading to the south always open. Rooms on the boundary of the maze (except the start and goal rooms) have their doors leading out of the maze always close.

## Maze Generation 
To randomly generate an n×n maze, we use the algorithm below. The algorithm assumes that the rooms are uniquely numbered from left to right, top to bottom. The numbering of rooms starts from 0 and ends with N − 1, where N is the total number of rooms in the maze (i.e., N = n2).

## Reading a Maze from file 
In addition to having the program generate a random maze from scratch, the program should also be able to read in a maze from a file whenever the program is executed with a command line argument representing the name of the text file containing the maze. For example, suppose the name of the executable program is main.exe and the name of the text file containing the maze is maze.txt, whenever the user types “main maze.txt” on the command-line, the program should read in the maze specified in the file maze.txt instead of randomly generating one. Assume that the text file containing the maze has the following format:
<value of n>
<door 0 in room 0> <door 1 in room 0> <door 2 in room 0> <door 3 in room 0>
<door 0 in room 1> <door 1 in room 1> <door 2 in room 1> <door 3 in room 1>
<door 0 in room 2> <door 1 in room 2> <door 2 in room 2> <door 3 in room 2>
.
.
.
where each <door x in room y> in the above is either a 0 or a 1. If <door x in room y> is a 0, it means
that door x in room y is open. If <door x in room y> is a 1, it means that door x in room y is close. As a
convention, we let door 0 in every room be the door leading to the north, door 1 in every room be the door
leading to the south, door 2 in every room be the door leading to the east, and door 3 in every room be the
door leading to the west.For example, the above given maze is represented by the following file contents
(note that only the first 7 rooms are actually shown):
5
0 0 1 1
1 1 0 1
1 0 1 0
1 1 0 1
1 0 1 0
0 0 1 1
1 1 0 1
.
.
.

## Solving the Maze 
* Once the program has generated a random maze from scratch or has read in a maze from a file, the program should then solve the maze by finding a path from the start room to the goal room. To solve the maze, the program would try two algorithms: breadth-first search (BFS) and depth-first search (DFS).
* In both the BFS and DFS algorithms above, we assume that adjacent rooms are considered in the following order: north, south, east, and west.

## How to Run this Program 
Download or clone the file. Open them in a compiler. Compile and run the program. 