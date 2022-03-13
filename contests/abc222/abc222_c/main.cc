#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<string> a(2 * n);
  cin >> a;
  V<int> win(2 * n);
  rep(round, m) {
    V<pair<int, int>> v;
    rep(i, 2 * n) v.eb(-win[i], i);
    sort(v);
    rep(i, n) {
      auto f = [](char c) -> int {
        string h = "GCP";
        rep(i, 3) if (h[i] == c) return i;
        assert(false);
      };
      int x = v[i * 2].second;
      int y = v[i * 2 + 1].second;
      int I = f(a[x][round]);
      int J = f(a[y][round]);
      if (I != J) ++win[((I + 1) % 3 == J ? x : y)];
    }
  }
  V<pair<int, int>> v;
  rep(i, 2 * n) v.eb(-win[i], i);
  sort(v);
  each(e, v) wt(e.second + 1);
}
