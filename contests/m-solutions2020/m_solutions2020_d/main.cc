#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll c = 1000;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i + 1] > a[i]) {
      ll d = c / a[i];
      dbg(c, d, a[i], a[i + 1]);
      c -= d * a[i];
      c += d * a[i + 1];
    }
  }
  wt(c);
}
