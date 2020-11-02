#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> cnt(n);
  for (int ai : a) {
    if ((n & 1) == (ai & 1)) {
      wt(0);
      return;
    }
    ++cnt[ai];
    if (cnt[ai] > 2 || ((n & 1) && ai == 0 && cnt[ai] > 1)) {
      wt(0);
      return;
    }
  }
  wt(mint(2).Pow(n / 2));
}
