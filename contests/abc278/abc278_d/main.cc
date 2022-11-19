#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  ints(q);
  int last = -1;
  map<int, int> add;
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(x);
      last = x;
      add.clear();
    } else if (t == 2) {
      ints(i, x);
      add[i - 1] += x;
    } else {
      ints(i);
      --i;
      int v = last == -1 ? a[i] : last;
      wt(v + add[i]);
    }
  }
}
