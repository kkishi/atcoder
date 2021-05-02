#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, s);
  vector a(h, vector(w, int(0)));
  cin >> a;
  if ((h <= 10 && w <= 10) || s == 1) {
    int ans = big;
    rep(i, h) for (int j = i; j < h && (j - i + 1) <= s; ++j) {
      rep(k, w) for (int l = k; l < w && (j - i + 1) * (l - k + 1) <= s; ++l) {
        set<int> st;
        rep(I, h) rep(J, w) if (!inside(I - i, J - k, j - i + 1, l - k + 1))
            st.insert(a[I][J]);
        chmin(ans, sz(st));
      }
    }
    wt(ans);
    return;
  }
  V<int> lr(15, big), hr(15, -big);
  V<int> lc(15, big), hc(15, -big);
  int N = -big;
  rep(i, h) rep(j, w) {
    chmax(N, a[i][j]);
    int ai = a[i][j] - 1;
    chmin(lr[ai], i);
    chmax(hr[ai], i);
    chmin(lc[ai], j);
    chmax(hc[ai], j);
  }
  int ans = big;
  rep(mask, 1 << N) {
    int LR = big, HR = -big;
    int LC = big, HC = -big;
    rep(i, N) if (hasbit(mask, i)) {
      chmin(LR, lr[i]);
      chmax(HR, hr[i]);
      chmin(LC, lc[i]);
      chmax(HC, hc[i]);
    }
    if ((HR - LR + 1) * (HC - LC + 1) <= s) chmin(ans, N - popcount(mask));
  }
  wt(ans);
}
