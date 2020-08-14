#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

// 001
// 110
// 011

// 11

int main() {
  rd(ll, n, k);
  vector<ll> a(n);
  cin >> a;

  ll bit = 1, shifts = 0;
  while ((bit << 1) <= k) {
    bit <<= 1;
    ++shifts;
  }

  vector<int> cnt(shifts + 1);
  rep(i, n) rep(j, shifts + 1) if ((a[i] >> j) & 1)++ cnt[j];

  ll x = 0;
  for (int i = shifts; i >= 0; --i) {
    if ((x | (1LL << i)) > k) continue;
    if (cnt[i] < (n - cnt[i])) x |= (1LL << i);
  }
  dbg(x);
  ll ans = 0;
  for (ll ai : a) ans += ai ^ x;
  wt(ans);
}
