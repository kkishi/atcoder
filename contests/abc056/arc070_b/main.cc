#include <bits/stdc++.h>

#include "atcoder.h"
#include "bit.h"

void Main() {
  ints(N, K);
  V<int> a(N);
  cin >> a;

  VV<bool> dpl(N + 1, V<bool>(K)), dph(N + 1, V<bool>(K));
  auto update = [](V<bool>& dp, int x) {
    rrep(i, sz(dp)) if (int j = i - x; j >= 0 && dp[j]) dp[i] = true;
  };
  dpl[0][0] = true;
  rep(i, N) {
    dpl[i + 1] = dpl[i];
    update(dpl[i + 1], a[i]);
  }
  dph[N][0] = true;
  rrep(i, N) {
    dph[i] = dph[i + 1];
    update(dph[i], a[i]);
  }

  // Use bit for an efficient lookup over a range.
  // bit[i] corresponds to hi[i] in the code below.
  V<BIT<int>> bit(N, BIT<int>(K));
  rep(i, N) rep(j, K) if (dph[i + 1][j]) bit[i].Add(j, 1);

  set<int> s;
  rep(i, N) {
    V<bool>& lo = dpl[i];

    bool noneed = true;
    rep(j, K) if (lo[j]) {
      int begin = max(0, K - j - a[i]);
      int end = K - j;
      int cnt = bit[i].Sum(end - 1) - bit[i].Sum(begin - 1);
      if (cnt > 0) noneed = false;
    }
    if (noneed) s.insert(a[i]);

#ifdef DEBUG
    V<bool>& hi = dph[i + 1];
    bool noneed_naive = true;
    rep(j, K) rep(k, K) {
      if (lo[j] && hi[k] && (j + k) < K && (j + k + a[i]) >= K) {
        noneed_naive = false;
      }
    }
    assert(noneed_naive == noneed);
#endif
  }

  int ans = 0;
  for (int ai : a) ans += s.count(ai);
  wt(ans);
}
