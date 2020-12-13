#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

void Main() {
  ints(n);
  V<int> h(n);
  cin >> h;

  V<int> sh(n + 1);
  rep(i, n) sh[i + 1] = sh[i] + h[i];

  V<tuple<int, int, int>> v;
  rep(n) {
    ints(m, s, e);
    v.emplace_back(s, e, m);
  }
  sort(all(v));

  SegmentTree<int> t(100001, [](int a, int b) { return max(a, b); });
  rep(i, n) {
    auto [s, e, m] = v[i];
    int l = s;
    int c = 1;
    int maxi = t.Aggregate(0, l + 1) + sh[c];
    rrep(j, i) if (auto [S, E, M] = v[j]; M == m && E <= l) {
      l = S;
      ++c;
      chmax(maxi, t.Aggregate(0, l + 1) + sh[c]);
    }
    t.Set(e, maxi);
  }
  wt(t.Aggregate(0, 100001));
}
