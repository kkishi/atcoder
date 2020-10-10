#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> p(n);
  cin >> p;
  set<int> s;
  rep(i, 200001) s.insert(i);
  rep(i, n) {
    s.erase(p[i]);
    wt(*s.begin());
  }
}
