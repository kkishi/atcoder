#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  vector a(9, vector(9, int(0)));
  cin >> a;
  rep(i, 9) {
    set<int> st;
    rep(j, 9) st.insert(a[i][j]);
    if (sz(st) != 9) return false;
  }
  rep(i, 9) {
    set<int> st;
    rep(j, 9) st.insert(a[j][i]);
    if (sz(st) != 9) return false;
  }
  rep(i, 3) rep(j, 3) {
    set<int> st;
    rep(k, 3) rep(l, 3) st.insert(a[i * 3 + k][j * 3 + l]);
    if (sz(st) != 9) return false;
  }
  return true;
}
