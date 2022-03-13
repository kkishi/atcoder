#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, s);
  vector a(h, vector(w, int(0)));
  cin >> a;
  if (s == 1) {
    map<int, int> m;
    rep(i, h) rep(j, w)++ m[a[i][j]];
    each(_, v, m) if (v == 1) {
      wt(sz(m) - 1);
      return;
    }
    wt(sz(m));
    return;
  }
  if (h <= 10 && w <= 10) {
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

  V<int> as;
  rep(i, h) rep(j, w) as.pb(a[i][j]);
  sort(as);
  as.erase(unique(all(as)), as.end());
  rep(i, h) rep(j, w) {
    auto it = lower_bound(all(as), a[i][j]);
    a[i][j] = it - as.begin();
  }

  int N = sz(as);
  assert(N <= 70);
  V<int> lr(N, big), hr(N, -big);
  V<int> lc(N, big), hc(N, -big);
  rep(i, h) rep(j, w) {
    int ai = a[i][j];
    chmin(lr[ai], i);
    chmax(hr[ai], i);
    chmin(lc[ai], j);
    chmax(hc[ai], j);
  }

  V<int> hcs;
  each(e, hc) hcs.pb(e);
  sort(hcs);
  hcs.erase(unique(all(hcs)), hcs.end());

  int ans = N;
  each(LR, lr) each(HR, hr) each(LC, lc) {
    if (LR > HR) continue;
    int H = (HR - LR + 1);
    int W = s / H;
    auto it = lower_bound(all(hcs), LC + W);
    if (it == hcs.begin()) continue;
    int HC = *prev(it);
    assert((HC - LC + 1) <= W);
    int ins = 0;
    rep(i, N) {
      if (LR <= lr[i] && hr[i] <= HR && LC <= lc[i] && hc[i] <= HC) {
        ++ins;
      }
    }
    chmin(ans, N - ins);
  }
  wt(ans);
}
