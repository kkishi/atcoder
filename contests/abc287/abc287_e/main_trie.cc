#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  V<int> idx;
  rep(i, n) idx.eb(i);
  V<int> ans(n);
  Fix([&](auto rec, int depth, const V<int>& idx) {
    if (sz(idx) == 0) return;
    if (sz(idx) == 1) {
      ans[idx[0]] = depth - 1;
      return;
    }
    VV<int> nidx(26);
    each(i, idx) {
      if (depth == sz(s[i])) {
        ans[i] = depth;
      } else {
        nidx[s[i][depth] - 'a'].eb(i);
      }
    }
    rep(i, 26) rec(depth + 1, nidx[i]);
  })(0, idx);
  rep(i, n) wt(ans[i]);
}
