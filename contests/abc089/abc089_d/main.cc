#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define R first
#define C second
  using P = pair<int, int>;
  rd(int, h, w, d);
  V<P> v(h * w);
  rep(i, h) rep(j, w) {
    rd(int, a);
    v[a - 1] = {i, j};
  }
  auto dist = [&v](int i, int j) {
    return abs(v[i].R - v[j].R) + abs(v[i].C - v[j].C);
  };
  VV<int> cum;
  rep(i, d) {
    int m = (h * w - 1 - i) / d;
    assert(i + m * d < h * w);
    V<int> v(m + 1);
    rep(j, m) v[j + 1] = v[j] + dist(i + (j + 1) * d, i + j * d);
    cum.push_back(v);
  }
  rd(int, q);
  while (q--) {
    rd(int, l, r);
    --l, --r;
    int i = l % d;
    int j = l / d;
    int k = r / d;
    wt(cum[i][k] - cum[i][j]);
  }
}
