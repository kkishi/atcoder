#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll x0 = 0;
  rep(i, n) x0 += a[i] * ((i & 1) ? -1 : 1);
  x0 /= 2;
  cout << x0 * 2;
  for (int i = 0; i < n - 1; ++i) {
    x0 = (a[i] - x0);
    cout << " " << x0 * 2;
  }
  cout << endl;
}
