#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  multiset<int> e, o;
  each(x, a)(even(x) ? e : o).insert(x);
  int ans = -1;
  if (sz(e) >= 2) {
    int x = 0;
    auto it = e.end();
    --it;
    x += *it;
    --it;
    x += *it;
    chmax(ans, x);
  }
  if (sz(o) >= 2) {
    int x = 0;
    auto it = o.end();
    --it;
    x += *it;
    --it;
    x += *it;
    chmax(ans, x);
  }
  wt(ans);
}
