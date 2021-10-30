#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  strings(s);
  mint sum = 0;
  mint ans = 0;
  int n = sz(s);
  rrep(i, n) {
    mint x = mint(2).Pow(i);
    if (i < n - 1) {
      sum = sum * 2 + mint(10).Pow(n - i - 2);
      x *= sum + mint(10).Pow(n - i - 1);
    }
    ans += x * (s[i] - '0');
  }
  wt(ans);
}
