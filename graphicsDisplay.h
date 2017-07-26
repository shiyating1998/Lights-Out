

#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include "observer.h"
#include "subject.h"
#include "subscriptions.h"
#include "window.h"
struct Info;

class GraphicsDisplay :public Observer{
    int gridSize;
    Xwindow *w;
    public:
        GraphicsDisplay(int n, Xwindow *w);
        void notify(Subject &whoNotified) override;
        SubscriptionType subType() const override;
        ~GraphicsDisplay();
};
#endif

