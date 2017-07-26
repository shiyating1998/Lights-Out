#include "graphicsDisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"
#include "window.h"
#include <iostream>

GraphicsDisplay::GraphicsDisplay(int n, Xwindow *xw){
    gridSize = n;
    w = xw;
}

void GraphicsDisplay::notify(Subject &whoNotified) {
    Info i = whoNotified.getInfo();
    int c = i.col;
    int r = i.row;
    int len = 500/(gridSize+1);
    if (i.state)
        w->fillRectangle (len*c, len*r, len, len, Xwindow::Black);
       
    else 
        w->fillRectangle (len*c, len*r, len, len, Xwindow::White);
}


SubscriptionType GraphicsDisplay::subType() const {
  return SubscriptionType::All;
}
GraphicsDisplay::~GraphicsDisplay() {}
