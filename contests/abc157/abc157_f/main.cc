#include <bits/stdc++.h>

#include "geometry.h"
#include "macros.h"

using namespace std;

using Vec = Vector<double>;
using Circ = Circle<double>;

int N, K;
Vec p[60];
double c[60];

bool Ok(double t) {
  dbg(t);
  vector<Vec> vs(p, p + N);
  auto Rad = [t](int i) { return t / c[i]; };
  rep(i, N) rep(j, i) {
    Circ ci = {p[i], Rad(i)}, cj = {p[j], Rad(j)};
    dbg(ci.center, ci.radius, cj.center, cj.radius);
    for (auto& v : ci.Intersections(cj)) {
      dbg(v);
      vs.push_back(v);
    }
  }
  // dbg(t, vs.size());
  rep(i, vs.size()) {
    int contains = 0;
    rep(j, N) {
      // This 1e-10 was important.
      if (Rad(j) + 1e-10 > (vs[i] - p[j]).Norm()) ++contains;
    }
    dbg(t, i, vs[i], contains);
    if (contains >= K) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> N >> K;
  rep(i, N) cin >> p[i].x >> p[i].y >> c[i];

  // Initially lo was 0.1 for some reason, which resulted WA.
  double lo = 0, hi = 10000000;
  const double EPS = 1e-8;
  while (hi - lo > EPS) {
    double mid = (hi + lo) / 2;
    (Ok(mid) ? hi : lo) = mid;
  }
  cout << setprecision(20) << lo << endl;
}
