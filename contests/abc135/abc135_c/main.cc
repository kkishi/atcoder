#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  vector<ll> a(n + 1), b(n);
  cin >> a >> b;
  ll sum = accumulate(all(b), 0LL);
  rep(i, n) {
    ll s = min(a[i], b[i]);
    b[i] -= s;
    a[i] -= s;
    s = min(a[i + 1], b[i]);
    b[i] -= s;
    a[i + 1] -= s;
  }
  wt(sum - accumulate(all(b), 0LL));
}
