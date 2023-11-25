#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  Intervals is;
  map<int, int> mp;
  auto add = [&](int x) {
    if (mp[x]++ == 0) is.Insert(x, x + 1);
  };
  auto del = [&](int x) {
    if (--mp[x] == 0) is.Erase(x, x + 1);
  };
  each(e, a) add(e);
  rep(q) {
    ints(i, x);
    --i;
    del(a[i]);
    a[i] = x;
    add(a[i]);
    wt(is.Mex(0));
  }
}
