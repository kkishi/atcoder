#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, k);
  vector<ll> a(n), f(n);
  cin >> a >> f;
  sort(all(a));
  sort(all(f), greater<ll>());
  auto check = [&](ll x) {
    ll training = 0;
    rep(i, n) {
      if (a[i] * f[i] > x) {
        training += a[i] - x / f[i];
      }
    }
    return training > k;
  };
  ll x = BinarySearch<ll>(0, 1e12L + 1, check);
  if (!check(x)) {
    wt(x);
  } else {
    wt(x + 1);
  }
}
