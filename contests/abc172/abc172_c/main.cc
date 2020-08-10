#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m, k);
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  vector<ll> sa(n + 1), sb(m + 1);
  rep(i, n) sa[i + 1] = sa[i] + a[i];
  rep(i, m) sb[i + 1] = sb[i] + b[i];

  ll ans = 0;
  rep(i, n + 1) {
    ll j = BinarySearch<ll>(0, m + 1, [&](ll x) { return k >= sa[i] + sb[x]; });
    if (k < sa[i] + sb[j]) break;
    ans = max(ans, i + j);
  }
  wt(ans);
}
