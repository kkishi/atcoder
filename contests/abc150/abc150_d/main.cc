#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll a[100000];

int main() {
  rd(ll, n, m);
  rep(i, n) cin >> a[i];

  rep(i, n) { a[i] /= 2; }
  ll l = 1;
  rep(i, n) {
    l = l * a[i] / gcd(l, a[i]);
    if (l > m) {
      wt(0);
      return 0;
    }
  }
  dbg(l, m);
  rep(i, n) if (l / a[i] % 2 == 0) {
    wt(0);
    return 0;
  }
  ll ans = 0;
  if (m >= l) {
    ++ans;
    m -= l;
  }
  ans += m / (2 * l);
  wt(ans);
}
