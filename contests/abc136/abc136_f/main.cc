#include <bits/stdc++.h>

#include "compress.h"
#include "macros.h"
#include "modint.h"
#include "segment_tree.h"

using namespace std;

using mint = ModInt<998244353>;

struct Point {
  ll x, y, i;
  bool operator<(const Point& p) const { return x < p.x; }
};

int main() {
  rd(ll, n);
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  vector<Point> p(n);
  rep(i, n) p[i] = {x[i], y[i], i};
  sort(all(p));

  vector<ll> cx = Compress(x), cy = Compress(y);
  vector<ll> upper_left(n), lower_left(n), upper_right(n), lower_right(n);
  {
    SegmentTree<ll> tree(n, [](ll a, ll b) { return a + b; });
    for (auto [x, y, i] : p) {
      ll yi = Uncompress(cy, y);
      upper_left[i] = tree.Aggregate(yi + 1, n);
      lower_left[i] = tree.Aggregate(0, yi);
      tree.Set(yi, 1);
    }
  }
  reverse(all(p));
  {
    SegmentTree<ll> tree(n, [](ll a, ll b) { return a + b; });
    for (auto [x, y, i] : p) {
      ll yi = Uncompress(cy, y);
      upper_right[i] = tree.Aggregate(yi + 1, n);
      lower_right[i] = tree.Aggregate(0, yi);
      tree.Set(yi, 1);
    }
  }
  mint ans = 0;
  for (auto [x, y, i] : p) {
    dbg(x, y, i);
    dbg(upper_left[i], lower_right[i], lower_left[i], upper_right[i]);
    auto fun = [&](ll z) { return mint(2).Pow(z) - 1; };
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
