#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(double, w, h, x, y);
  cout << setprecision(20) << (w * h / 2) << " ";
  if (x * 2 == w && y * 2 == h) {
    cout << "1";
  } else {
    cout << "0";
  }
  cout << endl;
}
