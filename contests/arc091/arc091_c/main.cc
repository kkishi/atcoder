#include <bits/stdc++.h>

#include "atcoder.h"

optional<V<int>> Solve(int n, int a, int b) {
  if (a > b) {
    auto res = Solve(n, b, a);
    if (!res) return nullopt;
    reverse(*res);
    return res;
  }
  if (a > (n + 1) / 2) return nullopt;
  if (n > a * b) return nullopt;
  if (a + b > n + 1) return nullopt;
  V<int> ans;
  int idx = 0;
  rep(i, a) {
    V<int> v;
    int c = (n - idx - (a - i) + 1);
    rep(j, min(b, c)) v.pb(++idx);
    copy(v.rbegin(), v.rend(), back_inserter(ans));
  }
  return ans;
}

void Main() {
  ints(n, a, b);
  auto res = Solve(n, a, b);
  if (!res) {
    wt(-1);
  } else {
    wt(*res);
  }
}
