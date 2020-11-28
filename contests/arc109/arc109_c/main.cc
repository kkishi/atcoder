#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  V<int> two(k + 1);
  two[0] = 1;
  rep(i, k) two[i + 1] = (two[i] * 2) % n;
  vector dp(n, vector(k + 1, optional<char>()));
  wt(Fix([&](auto rec, int offset, int power) -> char {
    if (power == 0) return s[offset];
    auto& d = dp[offset][power];
    if (!d) {
      int m = (offset + two[power - 1]) % n;
      char a = rec(offset, power - 1);
      char b = rec(m, power - 1);
      if (a == b || a == 'R' && b == 'S' || a == 'P' && b == 'R' ||
          a == 'S' && b == 'P') {
        d = a;
      } else {
        d = b;
      }
    }
    return *d;
  })(0, k));
}
