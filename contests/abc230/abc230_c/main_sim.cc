#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b, p, q, r, s);
  set<pair<int, int>> st;
  rep(k, max(p - a, r - b), min(q - a, s - b) + 1) st.emplace(a + k, b + k);
  rep(k, max(p - a, b - s), min(q - a, b - r) + 1) st.emplace(a + k, b - k);
  rep(i, p, q + 1) {
    rep(j, r, s + 1) { cout << (st.count({i, j}) ? '#' : '.'); }
    cout << endl;
  }
}
