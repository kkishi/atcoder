#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e];
  each(k, v, mp) if (v * 2 > n) {
    wt(k);
    return;
  }
  wt('?');
}
