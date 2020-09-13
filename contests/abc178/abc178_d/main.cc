#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(s);
  V<optional<mint>> dp(s + 1);
  wt(Fix([&dp](auto rec, int s) -> mint {
    if (s < 3) return 0;
    optional<mint> r = dp[s];
    if (r) {
      return *r;
    }
    mint ret = 1;
    for (int i = 3; i <= s; ++i) ret += rec(s - i);
    dp[s] = ret;
    return ret;
  })(s));
}
