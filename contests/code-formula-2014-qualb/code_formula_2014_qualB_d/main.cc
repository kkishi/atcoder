#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;

  mint ret = Fix([&](auto rec, int depth) -> mint {
    if (depth == n - 1) {
      return a[depth] + 1;
    }
    if (a[depth] >= 10) {
      mint ret = a[depth] % 10 + 1;
      int carry = a[depth] / 10;
      for (int d = depth + 1; d < n; ++d) {
        carry += a[d];
        carry /= 10;
        if (carry == 0 && d + 1 < n) {
          ret *= rec(d + 1);
          break;
        }
      }
      int inc = a[depth] / 10 - 1;
      a[depth + 1] += inc;
      ret += rec(depth + 1) * 10;
      a[depth + 1] -= inc;
      return ret;
    } else {
      return rec(depth + 1) * (a[depth] % 10 + 1);
    }
  })(0);
  wt(ret - 1);
}
