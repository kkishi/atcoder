#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  set<int> called;
  set<int> notcalled;
  rep(i, n) notcalled.insert(i);
  set<int> went;
  rep(q) {
    ints(t);
    if (t == 1) {
      int x = *notcalled.begin();
      called.insert(x);
      notcalled.erase(x);
    } else if (t == 2) {
      ints(x);
      --x;
      went.insert(x);
      called.erase(x);
    } else {
      wt(*called.begin() + 1);
    }
  }
}
