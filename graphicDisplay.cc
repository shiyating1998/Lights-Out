
#include "graphicsDisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"
#include "window.h"


GraphicsDisplay::GraphicsDisplay(int n, Xwindow *xw){
    gridSize = n;
    w = xw;
    w->fillRectangle(0,0,500,500,Xwindow::White);
}

void GraphicsDisplay::notify(Subject &whoNotified) {
    Info i = whoNotified.getInfo();
    int c = i.col;
    int r = i.row;

    if (i.state)
        w->fillRectangle (gridSize*r, gridSize*c, 500/gridSize, 500/gridSize, Xwindow::White);
    else
        w->fillRectangle (gridSize*r, gridSize*c, 500/gridSize, 500/gridSize, Xwindow::Black);
}


SubscriptionType GraphicsDisplay::subType() const {
  return SubscriptionType::All;
}

