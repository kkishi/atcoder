#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  set<int> s;
  rep(i, n) s.insert(a[i]);
  while (s.size() > 1) {
    int X = *s.rbegin();
    int x = *s.begin();
    s.erase(X);
    s.insert(X - x);
  }
  wt(*s.begin());
}
