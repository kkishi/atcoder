#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e];
  auto c2 = [](int n) -> int { return n * (n - 1) / (2 * 1); };
  auto c3 = [](int n) -> int { return n * (n - 1) * (n - 2) / (3 * 2 * 1); };
  int tot = c3(n);
  int two_same = 0;
  int all_same = 0;
  each(_, v, mp) {
    all_same += c3(v);
    two_same += c2(v) * (n - v);
  }
  wt(tot - two_same - all_same);
}
