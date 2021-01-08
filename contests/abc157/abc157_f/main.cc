#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "geometry.h"

using Vec = Vector<double>;
using Circ = Circle<double>;

int N, K;
Vec p[60];
double c[60];

bool Ok(double t) {
  vector<Vec> vs(p, p + N);
  auto Rad = [t](int i) { return t / c[i]; };
  rep(i, N) rep(j, i) {
    Circ ci = {p[i], Rad(i)}, cj = {p[j], Rad(j)};
    for (auto& v : ci.Intersections(cj)) {
      vs.pb(v);
    }
  }
  rep(i, vs.size()) {
    int contains = 0;
    rep(j, N) {
      if (Rad(j) + 1e-10 > (vs[i] - p[j]).Norm()) ++contains;
    }
    if (contains >= K) {
      return true;
    }
  }
  return false;
}

void Main() {
  cin >> N >> K;
  rep(i, N) cin >> p[i].x >> p[i].y >> c[i];
  wt(BinarySearch<double>(10000000, 0, Ok));
}
