#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  V<ll> a(n);
  cin >> a;
  ll c = 1000;
  rep(i, n - 1) {
    if (a[i + 1] > a[i]) {
      ll d = c / a[i];
      c -= d * a[i];
      c += d * a[i + 1];
    }
  }
  wt(c);
}
