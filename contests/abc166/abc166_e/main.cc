#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  map<ll, ll> m;
  ll ans = 0;
  rep(i, n) {
    ans += m[i - a[i]];
    m[i + a[i]]++;
  }
  wt(ans);
}
