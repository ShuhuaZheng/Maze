#ifndef MAZEGRAPHGEN_H
#define MAZEGRAPHGEN_H

#include "Maze.h"
#include "BitMap.h"

class MazeGraphGen
{
public:
     /// load bmp image as background file
    MazeGraphGen(char * backgroupBmpFile, Maze const & myMaze);
   ~ MazeGraphGen() {}

   void genMazeBitmap ();

   void saveMazeToFile(char* mazeFigName);

private:
   void putCellToGraph(int row_ind, int col_ind);
   cBitmap _bitmap;
   Maze _maze;
   int _wPixlePerCell;
   int _hPixlePerCell;
 };
 
 #endif