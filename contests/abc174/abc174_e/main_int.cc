#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, k);
  V<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ng = 0, ok = *max_element(all(a));
  while (ok - ng > 1) {
    ll mid = (ng + ok) / 2;
    ll cuts = 0;
    rep(i, n) cuts += (a[i] - 1) / mid;
    if (cuts <= k) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  wt(ok);
}
