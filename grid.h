
#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "cell.h"
#include "textdisplay.h"
#include "graphicsDisplay.h"
#include "window.h"
class Xwindow;

class Grid {
  std::vector<std::vector<Cell>> theGrid;  // The actual grid.
  int gridSize=0;    // Size of the grid.
  TextDisplay *td; // The text display.
  // Add private members, if necessary.
  GraphicsDisplay *gd;

  void clearGrid();   // Frees the grid.

 public:
  Grid();
  ~Grid();


  bool isWon() const; // Call to determine if grid is in a winning state.

  // Note: you will need to change the init method below
  // or overload this method so that main can also pass along
  // a reference to an XWindow which is to be forwarded to
  // the GraphicsDisplay in part b
  void init(int n, Xwindow *x); // Sets up an n x n grid.  Clears old grid, if necessary.

  void turnOn(int r, int c);  // Sets cell at row r, col c to On.
  void toggle(int r, int c);  // Switches cell at (r, c) between On and Off.

  void addValidCoord (int r, int c, int i, int j);
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif

