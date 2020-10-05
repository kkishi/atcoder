#include <bits/stdc++.h>

#include "atcoder.h"

int Solve(int n, const V<pair<int, int>>& v) {
  if (v.empty()) return n;
  return Fix([&](auto dfs, int depth, int rem) {
    auto [a, b] = v[depth];
    if (depth == sz(v) - 1) {
      return rem / a * b + rem % a;
    }
    int ret = 0;
    for (int i = 0; i * a <= rem; ++i) {
      chmax(ret, i * b + dfs(depth + 1, rem - i * a));
    }
    return ret;
  })(0, n);
}

void Main() {
  ints(n);
  V<int> a(3), b(3);
  cin >> a >> b;
  rep(2) {
    V<pair<int, int>> v;
    rep(i, 3) if (a[i] < b[i]) v.push_back({a[i], b[i]});
    n = Solve(n, v);
    swap(a, b);
  }
  wt(n);
}
