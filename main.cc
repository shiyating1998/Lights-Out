
#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"
using namespace std;

class Xwindow;
int main() {
  cin.exceptions(ios::eofbit|ios::failbit|ios::badbit);
  string cmd;
  Grid g;
  Xwindow x{};
  int moves = 0;

  // You will need to make changes to this code.

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
        if (n>=1) {
            g.init(n, &x);
        }
      }
      else if (cmd == "init") {
        int r, c;
        while (true){
            cin >> r;
            cin >> c;
            if (r==-1 || c==-1)
                break;

            g.turnOn(r,c);

        }
        cout << g;
      }
      else if (cmd == "game") {
        cin >> moves;
        cout << moves << " moves left"<< endl;
      }
      else if (cmd == "switch") {
        int r = 0, c = 0;
        cin >> r >> c;
        g.toggle(r,c);

        cout<<g;
        moves--;

        if(moves!=1)
            cout << moves << " moves left"<< endl;
        else
            cout<< "1 move left"<<endl;

        if (g.isWon()) {
            cout << "Won"<<endl;
            return -1;
        }
        else if(moves==0){

            cout<< "Lost"<<endl;
            return -1;
        }
        else{

        }
      }
    }
  }
  catch (ios::failure &) {
  }
}

