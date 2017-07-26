
#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;


TextDisplay::TextDisplay(int n): gridSize{n}  {
    vector<char> temp;
    for (int i=0; i<n; i++) {
        temp.emplace_back('_');
    }
    for (int j=0; j<n; j++) {
        theDisplay.emplace_back(temp);
    }
}

void TextDisplay::notify(Subject &whoNotified) {
    Info i = whoNotified.getInfo();

    if (i.state)
        theDisplay[i.row][i.col] = 'X';
    else
        theDisplay[i.row][i.col] = '_';
}



SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

TextDisplay::~TextDisplay() {}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int i=0; i<td.gridSize; ++i) {
        for (int j=0; j<td.gridSize; ++j){
            char on = td.theDisplay.at(i).at(j);
            out<<on;
        }
        out << endl;
    }
    return out;
}

