#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const int INF = 1 << 30;

int main() {
  ints(x, n);
  set<int> ps;
  rep(i, n) {
    ints(p);
    ps.insert(p);
  }
  rep(i, 200) {
    int ys[] = {x - i, x + i};
    rep(i, 2) if (ps.count(ys[i]) == 0) {
      wt(ys[i]);
      return 0;
    }
  }
}
