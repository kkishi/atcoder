#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  set<int> s;
  int over = 0;
  for (int ai : a) {
    if (ai >= 3200)
      ++over;
    else
      s.insert(ai / 400);
  }
  wt(max(1, sz(s)), sz(s) + over);
}
