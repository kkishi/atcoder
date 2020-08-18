#include <bits/stdc++.h>

#include "binary_search.h"
#include "geometry.h"
#include "macros.h"

using namespace std;

using Vec = Vector<double>;

int main() {
  ints(N);
  V<Vec> vec(N);
  cin >> vec;
  cout << setprecision(10);
  wt(BinarySearch<double>(10000000000, 0, [&](double mid) {
    rep(i, N) rep(j, i) {
      vector<Vec> vs =
          (Circle<double>{vec[i], mid}).Intersections({vec[j], mid});
      for (const Vec& v : vs) {
        bool ok = true;
        rep(k, N) if ((vec[k] - v).Norm() > mid + 1e-9) ok = false;
        if (ok) return true;
      }
    }
    return false;
  }));
}
