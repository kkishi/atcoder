#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  auto idx = [&](int r, int c) { return r * w + c; };
  DisjointSet ds(h * w);
  rep(r, h) rep(c, w) if (s[r][c] == '#') {
    each(nr, nc, adjacent(r, c)) {
      if (inside(nr, nc, h, w) && s[nr][nc] == '.') {
        ds.Union(idx(r, c), idx(nr, nc));
      }
    }
  }
  map<int, int> black, white;
  rep(r, h) rep(c, w) {
    (s[r][c] == '#' ? black : white)[ds.Find(idx(r, c))]++;
  }
  int ans = 0;
  for (auto [k, v] : black) {
    ans += v * white[k];
  }
  wt(ans);
}
