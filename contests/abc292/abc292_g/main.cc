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
  wt(Fix([&](auto rec, int l, int r, int digit, int next_num) -> mint {
    // If the interval size is 0, we return the identity for multiplication.
    if (l == r) return 1;
    // If there's no more digits left, the interval size has to be 1, otherwise
    // it violates the requirement that elemends need to be strictly increasing.
    if (digit == m) return l + 1 == r;
    // If there's no more numbers left, and the interval size is not 0, there's
    // no valid assignment.
    if (next_num == 10) return 0;
    mint& ret = memo[l][r][digit][next_num];
    if (!seen[l][r][digit][next_num]) {
      seen[l][r][digit][next_num] = true;
      rep(num, next_num, 10) {
        rep(mid, l + 1, r + 1) {
          char c = s[mid - 1][digit];
          // We can no longer advance the mid point using num.
          if (c != '?' && (c - '0') != num) break;
          // We split the interval into two parts where we can count
          // independently:
          //
          // 1) [l, mid) where we chose to use num for digit. The elements in
          // this interval are still all equal, so they need to be ordered using
          // the remaining digits.
          // 2) [mid, r) where we continue to choose how
          // to break up using the remaining numbers.
          //
          // Note that now the elements in 1) are ensured to be smaler than the
          // elements in 2).
          ret += rec(l, mid, digit + 1, 0) * rec(mid, r, digit, num + 1);
        }
      }
    }
    return ret;
  })(0, n, 0, 0));
}
