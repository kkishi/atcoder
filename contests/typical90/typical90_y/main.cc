#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, b);
  int ans = 0;
  {
    bool has_zero = false;
    int B = b;
    while (B) {
      if (B % 10 == 0) has_zero = true;
      B /= 10;
    }
    if (has_zero && n >= b) ++ans;
  }
  int digits = 1;
  int ten = 1;
  for (; ten <= n; ++digits, ten *= 10) {
    V<int> used_digits(10);
    Fix([&](auto rec, int digit, int used) -> void {
      if (digit == 10) {
        if (used < digits) return;
        int p = 1;
        rep(i, 10) rep(j, used_digits[i]) p *= i;
        int m = b + p;
        if (m > n) return;
        V<int> m_digits(10);
        while (m) {
          ++m_digits[m % 10];
          m /= 10;
        }
        if (m_digits == used_digits) {
          ++ans;
        }
        return;
      }
      for (int i = (digit == 9 ? digits - used : 0); i + used <= digits; ++i) {
        if (i > 0) used_digits[digit] = i;
        rec(digit + 1, used + i);
      }
      used_digits[digit] = 0;
    })(1, 0);
  }
  wt(ans);
}
