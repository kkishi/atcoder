#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<char> s(3), t(3);
  cin >> s >> t;
  V<int> idx(3);
  rep(i, 3) rep(j, 3) if (s[i] == t[j]) idx[i] = j;
  wt(Fix([&](auto rec, int depth) -> bool {
    if (depth == 15) return false;
    if (idx == V<int>{0, 1, 2}) {
      if (even(depth)) return true;
    }
    rep(i, 2) rep(j, i + 1, 3) {
      swap(idx[i], idx[j]);
      if (rec(depth + 1)) return true;
      swap(idx[i], idx[j]);
    }
    return false;
  })(0));
}
