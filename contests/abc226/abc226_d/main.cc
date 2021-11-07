#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  set<pair<int, int>> st;
  rep(i, n) rep(j, n) if (i != j) {
    int X = x[j] - x[i];
    int Y = y[j] - y[i];
    int g = gcd(abs(X), abs(Y));
    X /= g;
    Y /= g;
    st.emplace(X, Y);
  }
  wt(sz(st));
}
