#include <bits/stdc++.h>

#include "geometry.h"
#include "macros.h"

using namespace std;

using Vec = Vector<double>;
Vec vec[50];

int main() {
  rd(int, N);
  rep(i, N) cin >> vec[i].x >> vec[i].y;
  double lo = 0, hi = 10000000000;
  rep(iter, 100) {
    double mid = (hi + lo) / 2;
    bool ok = false;
    rep(i, N) for (int j = i + 1; j < N; ++j) {
      vector<Vec> vs =
          (Circle<double>{vec[i], mid}).Intersections({vec[j], mid});
      for (const Vec& v : vs) {
        bool ok2 = true;
        rep(k, N) if ((vec[k] - v).Norm() > mid + 1e-9) { ok2 = false; }
        if (ok2) {
          ok = true;
        }
      }
    }
    if (ok) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << setprecision(10);
  wt(lo);
}
