#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

using ld = long double;
const ld eps = 0.0000000001;

int main() {
  rd(ll, n, k);
  V<ld> a(n);
  cin >> a;
  ld ans = BinarySearch<ld>(*max_element(all(a)), 0, [&](ld mid) {
    ll cuts = 0;
    rep(i, n) cuts += (a[i] / mid) - eps;
    return cuts <= k;
  });
  wt(ll(ceil(ans) + eps));
}
