#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y);
  V<int> a(n);
  cin >> a;
  int i = 0;
  auto bet = [&](int z) { return y <= z && z <= x; };
  auto c2 = [](int x) { return x * (x + 1) / 2; };
  int ans = 0;
  while (i < n) {
    while (i < n && !bet(a[i])) ++i;
    int j = i;
    while (j < n && bet(a[j])) ++j;

    auto cnt = [&](const set<int>& ng) {
      int l = i;
      int ret = 0;
      while (l < j) {
        while (l < j && ng.count(a[l])) ++l;
        int r = l;
        while (r < j && !ng.count(a[r])) ++r;
        int len = r - l;
        ret += c2(len);
        l = r;
      }
      return ret;
    };
    int XY = cnt({x, y});
    int X = cnt({x});
    int Y = cnt({y});
    int ALL = c2(j - i);
    ans += ALL - X - Y + XY;
    i = j;
  }
  wt(ans);
}
