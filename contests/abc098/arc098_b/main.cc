#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  ll ans = 0;
  ll l = 0;
  ll x = 0;
  for (ll r = 0; r < n; ++r) {
    while (x & a[r]) {
      x ^= a[l];
      ++l;
    }
    x ^= a[r];
    ans += r - l + 1;
  }
  wt(ans);
}
