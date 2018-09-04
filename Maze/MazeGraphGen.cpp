#include "MazeGraphGen.h"
#include <iostream>
#include <stdexcept>

using namespace std;

MazeGraphGen::MazeGraphGen(char * backgroupBmpFile, Maze const & myMaze) : _bitmap(backgroupBmpFile, 0, 0, 0)
{
         // first calculate the
    int w = myMaze.getWidth();
    int h = myMaze.getHeight();
    int W = _bitmap.GetWidth();
    int H =  _bitmap.GetHeight();

    _wPixlePerCell = W/w-1;
    _hPixlePerCell  = H/h-1;

    if (_wPixlePerCell < 2 || _hPixlePerCell < 2) {
        cout << "backgournd bmp file: " << backgroupBmpFile << endl;
        cout << "resolution is " << W << "x" << H << endl;
        cout << "the widith and hight of the maze are " << w << ", " << h <<endl;
        throw std::runtime_error("background bmp figure is not large enough, use a larger one");
    }
    _maze = myMaze;
    }

void MazeGraphGen::genMazeBitmap ()
{
    int nCols = _maze.getWidth();
    int nRows = _maze.getHeight();

    for (int i=0; i<nRows; ++i)
        for (int j=0; j<nCols; ++j)
            putCellToGraph(i, j);
}

void MazeGraphGen::saveMazeToFile(char* mazeFigName)
{
    _bitmap.SaveBitmap(mazeFigName);

}

void MazeGraphGen::putCellToGraph(int row_ind, int col_ind)
{
    int cell_ind = row_ind * _maze.getWidth() + col_ind;
    int ipStart = col_ind * _wPixlePerCell;
    int jpStart =  row_ind * _hPixlePerCell;

    int topVal, botVal, leftVal, rightVal;
    _maze.getCellWallValue(cell_ind, topVal, botVal, leftVal, rightVal);

    // add top wall
    if (topVal != 0)
        for (int i=0; i<_wPixlePerCell; ++i)
            _bitmap.PutPixel(ipStart+i, jpStart, 0, 0, 0, 0);   // put black pixel values

    if (botVal != 0)
        for (int i=0; i<_wPixlePerCell; ++i)
            _bitmap.PutPixel(ipStart+i, jpStart+_hPixlePerCell, 0, 0, 0, 0);   // put black pixel values

    if(leftVal !=0)
        for (int j=0; j<_hPixlePerCell; ++j)
            _bitmap.PutPixel(ipStart, jpStart +j, 0, 0, 0, 0);

    if(rightVal !=0)
        for (int j=0; j<_hPixlePerCell; ++j)
            _bitmap.PutPixel(ipStart+_wPixlePerCell, jpStart +j, 0, 0, 0, 0);

}