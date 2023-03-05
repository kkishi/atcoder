#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m);
  V<string> s(n);
  cin >> s;
  vector memo(n + 1, vector(n + 1, vector(m + 1, vector(10, mint(0)))));
  vector seen(n + 1, vector(n + 1, vector(m + 1, vector(10, false))));
  wt(Fix([&](auto rec, int l, int r, int depth, int next_digit) -> mint {
    if (l == r) return 1;
    if (depth == m) return l + 1 == r;
    if (next_digit == 10) return 0;
    if (seen[l][r][depth][next_digit]) return memo[l][r][depth][next_digit];
    seen[l][r][depth][next_digit] = true;
    mint ret = 0;
    rep(mid, l + 1, r + 1) rep(digit, next_digit, 10) {
      bool ok = true;
      rep(i, l, mid) {
        char c = s[i][depth];
        if (c != '?' && (c - '0') != digit) ok = false;
      }
      if (ok) ret += rec(l, mid, depth + 1, 0) * rec(mid, r, depth, digit + 1);
    }
    memo[l][r][depth][next_digit] = ret;
    return ret;
  })(0, n, 0, 0));
}
