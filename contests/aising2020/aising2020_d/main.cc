#include <bits/stdc++.h>

#include "atcoder.h"

int calc(int x) {
  if (x == 0) return 0;
  return 1 + calc(x % __builtin_popcount(x));
}

void Main() {
  ints(n);
  strings(x);
  int p = count(all(x), '1');

  map<int, vector<int>> mods_cache;
  auto getMods = [&](int mod) -> auto& {
    if (mods_cache.count(mod) == 0) {
      vector<int> m(n);
      m[0] = 1 % mod;
      rep(i, 1, n) m[i] = (m[i - 1] << 1) % mod;
      mods_cache[mod] = m;
    }
    return mods_cache[mod];
  };

  auto getMod = [&](int i, int mod) { return getMods(mod)[n - 1 - i]; };

  map<int, int> get_sum_cache;
  auto getSum = [&](int mod) {
    if (get_sum_cache.count(mod) == 0) {
      int sum = 0;
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
        int sum = getSum(p - 1);
        sum -= getMod(i, p - 1);
        sum %= p - 1;
        wt(1 + calc(sum));
      }
    } else {
      int sum = getSum(p + 1);
      sum += getMod(i, p + 1);
      sum %= p + 1;
      wt(1 + calc(sum));
    }
  }
}
