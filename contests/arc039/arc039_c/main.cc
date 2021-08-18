#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(_);
  strings(s);
  map<int, Intervals> X, Y;
  int x = 0, y = 0;
  each(e, s) {
    X[y].Insert(x, x + 1);
    Y[x].Insert(y, y + 1);
    if (e == 'L' || e == 'R') {
      auto i = X[y].Find(x);
      assert(i);
      x = e == 'L' ? i->left - 1 : i->right;
    } else {
      auto i = Y[x].Find(y);
      assert(i);
      y = e == 'D' ? i->left - 1 : i->right;
    }
  }
  wt(x, y);
}
