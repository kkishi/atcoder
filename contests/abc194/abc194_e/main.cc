#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;

  set<int> ex;
  rep(i, n + 1) ex.insert(i);

  map<int, int> cn;
  auto ins = [&](int x) {
    if (cn[x] == 0) {
      assert(ex.count(x));
      ex.erase(x);
    }
    ++cn[x];
  };
  auto del = [&](int x) {
    assert(cn[x]);
    --cn[x];
    if (cn[x] == 0) {
      ex.insert(x);
    }
  };
  rep(i, m) ins(a[i]);
  int i = m - 1;
  int ans = big;
  while (true) {
    chmin(ans, *ex.begin());
    ++i;
    if (i == n) break;
    ins(a[i]);
    del(a[i - m]);
  }
  wt(ans);
}
