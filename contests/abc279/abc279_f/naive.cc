#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<set<int>> box(n);
  map<int, int> mp;
  rep(i, n) {
    box[i].insert(i + 1);
    mp[i + 1] = i;
  }
  int num_balls = n;
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(x, y);
      --x, --y;
      each(e, box[y]) box[x].insert(e);
      box[y].clear();
    } else if (t == 2) {
      ints(x);
      --x;
      int w = ++num_balls;
      box[x].insert(w);
    } else {
      ints(x);
      rep(i, n) if (box[i].count(x)) wt(i + 1);
    }
  }
}
