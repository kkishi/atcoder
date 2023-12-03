#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e];
  map<int, int> ans;
  int sum = 0;
  for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    auto [k, v] = *it;
    ans[k] = sum;
    sum += k * v;
  }
  V<int> v;
  each(e, a) v.eb(ans[e]);
  wt(v);
}
