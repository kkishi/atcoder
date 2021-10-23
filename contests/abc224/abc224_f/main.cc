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
    if (i == n - 1) {
      mint x = mint(2).Pow(i);
      ans += (s[i] - '0') * x;
    } else {
      sum = sum * 2 + mint(10).Pow(n - i - 2);
      mint x = sum + mint(10).Pow(n - i - 1);
      x *= mint(2).Pow(i);
      ans += x * (s[i] - '0');
    }
  }
  wt(ans);
}
