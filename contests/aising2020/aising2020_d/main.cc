#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll calc(ll x) {
  if (x == 0) return 0;
  return 1 + calc(x % __builtin_popcount(x));
}

int main() {
  rd(ll, n);
  strings(x);
  ll p = count(all(x), '1');

  map<ll, vector<ll>> mods_cache;
  auto getMods = [&](ll mod) -> auto& {
    if (mods_cache.count(mod) == 0) {
      vector<ll> m(n);
      m[0] = 1 % mod;
      rep(i, 1, n) m[i] = (m[i - 1] << 1) % mod;
      mods_cache[mod] = m;
    }
    return mods_cache[mod];
  };

  auto getMod = [&](ll i, ll mod) { return getMods(mod)[n - 1 - i]; };

  map<ll, ll> get_sum_cache;
  auto getSum = [&](ll mod) {
    if (get_sum_cache.count(mod) == 0) {
      ll sum = 0;
      rep(i, n) if (x[i] == '1') sum += getMod(i, mod);
      get_sum_cache[mod] = sum;
    }
    return get_sum_cache[mod];
  };

  rep(i, n) {
    if (x[i] == '1') {
      if (p == 1) {
        wt(0);
      } else {
        ll sum = getSum(p - 1);
        sum -= getMod(i, p - 1);
        sum %= p - 1;
        wt(1 + calc(sum));
      }
    } else {
      ll sum = getSum(p + 1);
      sum += getMod(i, p + 1);
      sum %= p + 1;
      wt(1 + calc(sum));
    }
  }
}
