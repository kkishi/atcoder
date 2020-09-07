#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(w, h, n);
  int minx = 0, maxx = w, miny = 0, maxy = h;
  rep(n) {
    ints(x, y, a);
    if (a == 1) chmax(minx, x);
    if (a == 2) chmin(maxx, x);
    if (a == 3) chmax(miny, y);
    if (a == 4) chmin(maxy, y);
  }
  wt(max(0, maxx - minx) * (max(0, maxy - miny)));
}
