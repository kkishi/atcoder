#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  set<int> s;
  int sum = 0;
  rep(i, n) {
    if (sum * 2 >= a[i]) {
      s.insert(i);
    } else {
      s = {i};
    }
    sum += a[i];
  }
  wt(sz(s));
}
