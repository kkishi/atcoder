#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

mint Solve() {
  ints(n);
  V<int> a(n);
  cin >> a;
  if (a[0] != 0) return 0;
  map<int, int> m;
  for (int ai : a) ++m[ai];
  if (m[0] != 1) return 0;
  mint ans = 1;
  for (auto [k, v] : m) {
    if (k == 0) continue;
    int u = m[k - 1];
    if (u == 0) return 0;
    mint sum = 0;
    rep(unused, v + 1) {
      mint x = mint::Comb(v, unused) * mint(2).Pow(u * (v - unused));
      if (unused & 1) x = -x;
      sum += x;
    }
    ans *= sum * mint(2).Pow(v * (v - 1) / 2);
  }
  return ans;
}

void Main() { wt(Solve()); }
