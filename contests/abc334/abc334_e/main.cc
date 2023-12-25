#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set_2d.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(h, w);
  DisjointSet2D ds(h, w);
  V<string> s(h);
  cin >> s;
  rep(i, h) rep(j, w) {
    if (s[i][j] != '#') continue;
    if (i + 1 < h && s[i + 1][j] == '#') ds.Union(i, j, i + 1, j);
    if (j + 1 < w && s[i][j + 1] == '#') ds.Union(i, j, i, j + 1);
  }
  set<int> st;
  rep(i, h) rep(j, w) if (s[i][j] == '#') st.insert(ds.Find(i, j));
  mint base = sz(st);
  mint ans = 0;
  mint cnt = 0;
  rep(i, h) rep(j, w) {
    if (s[i][j] != '.') continue;
    ++cnt;
    set<int> st;
    each(ni, nj, adjacent(i, j)) {
      if (inside(ni, nj, h, w) && s[ni][nj] == '#') st.insert(ds.Find(ni, nj));
    }
    ans += base - sz(st) + 1;
  }
  wt(ans / cnt);
}
