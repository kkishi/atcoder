#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  map<int, int, greater<>> mp;
  each(e, a)++ mp[e];
  V<int> ans(n);
  int cnt = 0;
  each(_, v, mp) {
    ans[cnt] += v;
    ++cnt;
  }
  each(e, ans) wt(e);
}
