#include <bits/stdc++.h>

#include "atcoder.h"

bool Check(int a, V<int> b) {
  rep(s, 1 << sz(b)) {
    int c = 0;
    rep(i, sz(b)) if (hasbit(s, i)) c ^= b[i];
    if (a == c) return true;
  }
  return false;
}

int Solve() {
  ints(n);
  V<int> a(n);
  cin >> a;
  strings(s);

  rep(i, n) if (s[i] == '1') {
    V<int> b;
    rep(j, i + 1, n) if (s[j] == '0') b.push_back(a[j]);
    if (!Check(a[i], b)) return 1;
  }
  return 0;
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
