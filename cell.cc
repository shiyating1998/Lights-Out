
#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }

void Cell::setOn() { isOn = true; notifyObservers(SubscriptionType::All); }

void Cell::toggle() {
    isOn?isOn=false:isOn=true;
    notifyObservers(SubscriptionType::All);
    notifyObservers(SubscriptionType::SwitchOnly);
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }


SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}

void Cell::notify(Subject &neighbour) {
    isOn?isOn=false:isOn=true;
    notifyObservers(SubscriptionType::All);
}


Info Cell::getInfo() const {
    Info i = Info();
    i.row = r;
    i.col = c;
    i.state = isOn;
    return i;
}

