#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  ll ans = 0;
  rrep(i, n) ans += (i + 1) * (n - i);
  rep(i, n - 1) {
    rd(ll, u, v);
    if (u > v) swap(u, v);
    ll x = u * (n - (v - 1));
    ans -= x;
  }
  wt(ans);
}
