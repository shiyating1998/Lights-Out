#include <iostream>
#include "grid.h"
#include "info.h"
using namespace std;

class Xwindow;
void Grid::clearGrid() {
    theGrid.clear();
    gridSize = 0;
}


Grid::Grid() :gridSize{0},td{nullptr},gd{nullptr} {}

Grid::~Grid() {
    delete td;
    delete gd;
}



bool Grid::isWon() const {
  for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridSize; j++) {
            if (theGrid.at(i).at(j).getState()) {
                return false;
            }
        }
  }
  return true;
}

//add a neighbouring Cell at (r,c) to the observer list
// or the cell at (i,j) if it is a valid cell
void Grid::addValidCoord (int r, int c, int i, int j){
     if (r>=0 && c>=0 && r<gridSize && c<gridSize)
        theGrid[i][j].attach(&theGrid.at(r).at(c));
}

void Grid::init(int n, Xwindow *x) {
    if (gridSize!=0)
        clearGrid();

    gridSize = n;

    td = new TextDisplay {n};

    gd = new GraphicsDisplay{n, x};

    for (int i=0; i<n; ++i) {
        theGrid.emplace_back(vector<Cell>());
        for (int j=0; j<n; ++j){
            theGrid[i].emplace_back(Cell());
            theGrid[i][j].setCoords(i,j);
            theGrid[i][j].attach(td);
            theGrid[i][j].attach(gd);
        }
    }

    // attach observers
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j) {
            addValidCoord(i-1,j,i,j);
            addValidCoord(i+1,j,i,j);
            addValidCoord(i,j-1,i,j);
            addValidCoord(i,j+1,i,j);
        }
    }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}


ostream &operator<<(ostream &out, const Grid &g) {
    out << *(g.td);
    return out;
}


