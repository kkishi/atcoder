#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  vector a(h, vector(w, int(0)));
  cin >> a;
  int ans = 0;
  set<int> seen;
  Fix([&](auto rec, int r, int c) -> void {
    if (!seen.insert(a[r][c]).second) return;
    if (r == h - 1 && c == w - 1) ++ans;
    if (r + 1 < h) rec(r + 1, c);
    if (c + 1 < w) rec(r, c + 1);
    seen.erase(a[r][c]);
  })(0, 0);
  wt(ans);
}
