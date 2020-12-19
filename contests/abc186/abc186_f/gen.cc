#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Random r;
  int h = 5;
  int w = 5;
  int m = 5;
  wt(h, w, m);
  set<pair<int, int>> s{{1, 1}};
  rep(m) {
    while (true) {
      int x = r.Int(1, h);
      int y = r.Int(1, w);
      if (s.insert({x, y}).second) {
        wt(x, y);
        break;
      }
    }
  }
}
