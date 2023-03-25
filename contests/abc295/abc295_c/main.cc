#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e];
  int ans = 0;
  each(_, e, mp) ans += e / 2;
  wt(ans);
}
