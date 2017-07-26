
#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
    int len = observers.size();
    for (int i=0; i<len; ++i) {
        if (observers.at(i)->subType()==t){
            observers.at(i)->notify(*this);
        }
    }
}

Subject::~Subject(){}

