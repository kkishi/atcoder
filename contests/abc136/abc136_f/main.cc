#include <bits/stdc++.h>

#include "atcoder.h"
#include "compress.h"
#include "modint.h"
#include "segment_tree.h"

using mint = ModInt<998244353>;

struct Point {
  int x, y, i;
  bool operator<(const Point& p) const { return x < p.x; }
};

void Main() {
  ints(n);
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  vector<Point> p(n);
  rep(i, n) p[i] = {x[i], y[i], i};
  sort(all(p));

  vector<int> cx = Compress(x), cy = Compress(y);
  vector<int> upper_left(n), lower_left(n), upper_right(n), lower_right(n);
  {
    SegmentTree<int> tree(n, [](int a, int b) { return a + b; });
    for (auto [x, y, i] : p) {
      int yi = Uncompress(cy, y);
      upper_left[i] = tree.Aggregate(yi + 1, n);
      lower_left[i] = tree.Aggregate(0, yi);
      tree.Set(yi, 1);
    }
  }
  reverse(all(p));
  {
    SegmentTree<int> tree(n, [](int a, int b) { return a + b; });
    for (auto [x, y, i] : p) {
      int yi = Uncompress(cy, y);
      upper_right[i] = tree.Aggregate(yi + 1, n);
      lower_right[i] = tree.Aggregate(0, yi);
      tree.Set(yi, 1);
    }
  }
  mint ans = 0;
  for (auto [x, y, i] : p) {
    dbg(x, y, i);
    dbg(upper_left[i], lower_right[i], lower_left[i], upper_right[i]);
    auto fun = [&](int z) { return mint(2).Pow(z) - 1; };
    ans += fun(upper_left[i]) * fun(lower_right[i]) *
               mint(2).Pow(lower_left[i] + upper_right[i]) +
           fun(lower_left[i]) * fun(upper_right[i]) *
               mint(2).Pow(upper_left[i] + lower_right[i]) -
           fun(upper_left[i]) * fun(lower_right[i]) * fun(lower_left[i]) *
               fun(upper_right[i]) +
           mint(2).Pow(n - 1);
  }
  wt(ans);
}
