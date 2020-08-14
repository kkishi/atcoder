#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m);
  vector<ll> a(n);
  cin >> a;
  vector<ll> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  ll ans = 0;
  map<ll, ll> seen;
  rep(i, n + 1) {
    ans += seen[s[i] % m];
    ++seen[s[i] % m];
  }
  wt(ans);
}
