#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

using ld = long double;
const ld eps = 0.0000000001;

int main() {
  rd(ll, n, k);
  V<ld> a(n);
  rep(i, n) cin >> a[i];
  ld lo = 0, hi = *max_element(all(a));
  rep(iter, 400) {
    ld mid = (hi + lo) / 2;
    ll cuts = 0;
    rep(i, n) cuts += (a[i] / mid) - eps;
    if (cuts <= k) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  wt(ll(ceil(lo) + eps));
}
