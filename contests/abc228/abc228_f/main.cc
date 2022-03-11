#include <bits/stdc++.h>

#include "atcoder.h"
#include "cumulative_sum.h"

void Main() {
  ints(h, w, h1, w1, h2, w2);
  chmin(h2, h1);
  chmin(w2, w1);
  vector a(h, vector(w, int(0)));
  cin >> a;
  CumulativeSum2D s(a);
  vector v(h, vector(w, int(0)));
  rep(i, h2 - 1, h) rep(j, w2 - 1, w) {
    v[i][j] = s.Get(i - h2 + 1, j - w2 + 1, i, j);
  }
  vector v2(h, vector(w, int(0)));
  rep(j, w2 - 1, w) {
    multiset<int> s;
    rep(i, h2 - 1, h) {
      int H = h1 - h2 + 1;
      if (sz(s) == H) s.erase(s.find(v[i - H][j]));
      s.insert(v[i][j]);
      if (sz(s) == H) {
        v2[i][j] = *prev(s.end());
      }
    }
  }
  vector v3(h, vector(w, int(0)));
  rep(i, h1 - 1, h) {
    multiset<int> s;
    rep(j, w2 - 1, w) {
      int W = w1 - w2 + 1;
      if (sz(s) == W) s.erase(s.find(v2[i][j - W]));
      s.insert(v2[i][j]);
      if (sz(s) == W) {
        v3[i][j] = *prev(s.end());
      }
    }
  }
  int ans = -big;
  rep(i, h1 - 1, h) rep(j, w1 - 1, w) {
    chmax(ans, s.Get(i - h1 + 1, j - w1 + 1, i, j) - v3[i][j]);
  }
  wt(ans);
}
