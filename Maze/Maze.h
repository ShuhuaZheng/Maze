#ifndef MAZE_H
#define MAZE_H


#include <list>
#include "DisjSet.h"
#include "RandGen.h"

class Maze {
public:
   Maze() { }
   Maze(int sideLength);

   void findPathBFS(std::vector<int> & pathInds); ///< BFS search, return path index
   void findPathDFS(std::vector<int> & pathInds); ///< DFS search, return path index

   void setUpMaze();          // Sets up the maze by setting all outside values to -1
                                          // and destroying the outside walls of the entrance and exit
   void createMaze(int randSeed);         //  Create a maze by randomly picking and destroying walls
   void createMaze(std::string const & filename);  // create a maze from file
   void saveMazeToFile(std::string const & filename);
   bool checkIfMaze();        // Checks whether the first and last cells (entrance and exit) are
                                          // within the same set - thus indicating a maze has been created
   void print();                    // prints out the maze

   bool isConnectedNeighbor(int room_i, int room_j);
   int getHeight() const  { return myHeight; }
   int getWidth() const { return myWidth; }
   void getCellWallValue(int cellInd, int & topVal, int & botVal, int & leftVal, int & rightVal);

private:

   static const int TOP = 0;
   static const int LEFT = 3;
   static const int BOTTOM = 1;
   static const int RIGHT = 2;

   int decideCellIndex(int cellIndex, int wallVal);
   void genRandAdjRooms(int & r1,  int & w1,  int & r2, int & w2);

   int myHeight, myWidth;  // Height and width of the maze respectively
   int mySize;                      // Total number of cells in the maze
   DisjSets mySets;             // Array of the sets that make up the maze
   std::list<int> myList;             // List of all possible cells not already contained within set zero
   RandGen  myRandGen;   /// my randsom generator obj
};

#endif