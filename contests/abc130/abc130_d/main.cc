#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, k);
  vector<ll> a(n);
  cin >> a;
  vector<ll> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  ll ans = 0;
  rep(i, n) {
    int j = lower_bound(all(s), s[i + 1] - k + 1) - s.begin();
    ans += j;
  }
  wt(ans);
}
