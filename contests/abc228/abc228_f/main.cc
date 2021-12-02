#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, h1, w1, h2, w2);
  chmin(h2, h1);
  chmin(w2, w1);
  vector a(h, vector(w, int(0)));
  cin >> a;
  vector s(h, vector(w, int(0)));
  rep(i, h) rep(j, w) {
    s[i][j] += a[i][j];
    if (i > 0) s[i][j] += s[i - 1][j];
    if (j > 0) s[i][j] += s[i][j - 1];
    if (i > 0 && j > 0) s[i][j] -= s[i - 1][j - 1];
  }
  vector v(h, vector(w, int(0)));
  rep(i, h2 - 1, h) rep(j, w2 - 1, w) {
    v[i][j] = s[i][j];
    int I = i - h2, J = j - w2;
    if (I >= 0) v[i][j] -= s[I][j];
    if (J >= 0) v[i][j] -= s[i][J];
    if (I >= 0 && J >= 0) v[i][j] += s[I][J];
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
  rep(i, h1 - 1, h) {
    rep(j, w1 - 1, w) {
      int x = s[i][j];
      int I = i - h1, J = j - w1;
      if (I >= 0) x -= s[I][j];
      if (J >= 0) x -= s[i][J];
      if (I >= 0 && J >= 0) x += s[I][J];
      chmax(ans, x - v3[i][j]);
    }
  }
  wt(ans);
}
