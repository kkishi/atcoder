#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int N = 1 << n;
  V<string> ans;
  Fix([&](auto rec, string s, int depth, int cnt) {
    if (depth == N) {
      if (cnt == N / 2) {
        ans.push_back(s);
      }
      return;
    }
    rec(s + 'A', depth + 1, cnt + 1);
    rec(s + 'B', depth + 1, cnt);
  })("A", 1, 1);
  wt(sz(ans));
  each(a, ans) wt(a);

  /*
    mini: 1 (L49)
    ans[i]: AB (L50)

    mini: 3 (L49)
    ans[i]: AABB (L50)
    ans[i]: ABAB (L50)
    ans[i]: ABBA (L50)

    mini: 7 (L49)
    ans[i]: AAAABBBB (L50)
    ans[i]: AABBAABB (L50)
    ans[i]: AABBBBAA (L50)
    ans[i]: ABABABAB (L50)
    ans[i]: ABABBABA (L50)
    ans[i]: ABBAABBA (L50)
    ans[i]: ABBABAAB (L50)
  */
  int mini = big;
  rep(s, 1, 1LL << sz(ans)) {
    vector cnt(N, vector(N, int(0)));
    rep(i, sz(ans)) if (hasbit(s, i)) {
      rep(j, N - 1) rep(k, j + 1, N) if (ans[i][j] == ans[i][k]) {
        ++cnt[j][k];
        if (cnt[j][k] > 4) goto next;
      }
    }
    if (false) {
    next:
      continue;
    }
    bool ok = true;
    rep(j, N - 1) rep(k, j + 1, N) if (cnt[j][k] != cnt[0][1]) ok = false;
    if (ok) {
      if (chmin(mini, popcount(s))) {
        dbg(mini);
        rep(i, sz(ans)) if (hasbit(s, i)) dbg(ans[i]);
      }
    }
  }
}
