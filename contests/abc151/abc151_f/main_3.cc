#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

complex<double> c[50];

int main() {
  rd(int, n);
  rep(i, n) {
    double x, y;
    cin >> x >> y;
    c[i] = {x, y};
  }
  complex<double> cc = c[0];
  double delta = 1000.0;
  while (delta > 1e-10) {
    double dist = 0;
    complex<double> dc;
    rep(i, n) {
      double d = abs(c[i] - cc);
      if (dist < d) {
        dist = d;
        dc = c[i];
      }
    }
    complex<double> dir = dc - cc;
    cc += dir / abs(dir) * delta;
    delta *= 0.999;
  }
  cout << setprecision(20);
  wt(abs(c[0] - cc));
}
