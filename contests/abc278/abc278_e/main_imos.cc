#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(H, W, n, h, w);
  vector a(H, vector(W, int(0)));
  cin >> a;
  VV<pair<int, int>> v(n);
  rep(i, H) rep(j, W) v[a[i][j] - 1].eb(i, j);
  vector imos(H + 1, vector(W + 1, int(0)));
  int cnt = 0;
  each(e, v) {
    if (sz(e) == 0) continue;
    ++cnt;
    int mar = -big, mir = big, mac = -big, mic = big;
    each(r, c, e) {
      chmax(mar, r);
      chmin(mir, r);
      chmax(mac, c);
      chmin(mic, c);
    }
    int dr = h - (mar - mir + 1);
    int dc = w - (mac - mic + 1);
    if (dr >= 0 && dc >= 0) {
      int MIR = max(mir - dr, 0);
      int MAR = min(mir, H - h);
      int MIC = max(mic - dc, 0);
      int MAC = min(mic, W - w);
      --imos[MIR][MIC];
      ++imos[MIR][MAC + 1];
      ++imos[MAR + 1][MIC];
      --imos[MAR + 1][MAC + 1];
    }
  }
  rep(i, H + 1) rep(j, W) imos[i][j + 1] += imos[i][j];
  rep(j, W + 1) rep(i, H) imos[i + 1][j] += imos[i][j];
  rep(i, H - h + 1) {
    rep(j, W - w + 1) {
      if (j) cout << " ";
      cout << (cnt + imos[i][j]);
    }
    cout << endl;
  }
}
