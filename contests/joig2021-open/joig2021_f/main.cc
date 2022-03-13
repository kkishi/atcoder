#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, s);
  vector a(h, vector(w, int(0)));
  cin >> a;

  V<int> as;
  rep(i, h) rep(j, w) as.pb(a[i][j]);
  sort(as);
  as.erase(unique(all(as)), as.end());
  rep(i, h) rep(j, w) {
    auto it = lower_bound(all(as), a[i][j]);
    a[i][j] = it - as.begin();
  }

  int N = sz(as);
  V<int> lr(N, big), hr(N, -big);
  V<int> lc(N, big), hc(N, -big);
  rep(i, h) rep(j, w) {
    int ai = a[i][j];
    chmin(lr[ai], i);
    chmax(hr[ai], i);
    chmin(lc[ai], j);
    chmax(hc[ai], j);
  }

  int ans = N;
  rep(i, N) rep(j, N) {
    int LR = lr[i], HR = hr[j];
    if (LR > HR) continue;
    int H = HR - LR + 1;
    int W = s / H;
    V<pair<int, int>> v;
    rep(k, N) {
      if (LR <= lr[k] && hr[k] <= HR) {
        if ((hc[k] - lc[k] + 1) <= W) {
          v.eb(hc[k] - W + 1, 0);
          v.eb(lc[k], 1);
        }
      }
    }
    sort(v);
    int cnt = 0;
    for (auto [_, pop] : v) {
      if (pop) {
        --cnt;
      } else {
        ++cnt;
      }
      chmin(ans, N - cnt);
    }
  }
  wt(ans);
}
