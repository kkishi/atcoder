#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  V<ll> a(n);
  cin >> a;
  rep(i, n) a[i] -= i + 1;
  sort(all(a));
  ll ans = 0;
  rep(i, n) ans += abs(a[i] - a[n / 2]);
  wt(ans);
}
