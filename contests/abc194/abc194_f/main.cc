#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(n);
  const int N = sz(n);
  V<int> v;
  each(e, n) {
    if (isdigit(e)) {
      v.pb(e - '0');
    } else {
      v.pb(e - 'A' + 10);
    }
  }
  ints(k);
  mint ans = 0;
  set<int> s;
  rep(i, N) {
    int rem = N - i - 1;
    // Calculates the number of ways to fill the remaining slots of the
    // partially constructed hex number, while satisfying the conditions.
    //
    // Parameters:
    // * rem: The number of remaining slots to fill.
    // * used_digits: The unique number of digits in the already filled slots.
    // * k: The unique number of digits needed in the final result.
    auto calc = [&](int used_digits) -> mint {
      if (used_digits > k) return 0;
      if (rem < k - used_digits) return 0;
      mint sum = 0;
      // Inclusion–exclusion principle.
      for (int i = k; i >= used_digits; --i) {
        mint p = mint(i).Pow(rem);
        mint c = mint::Comb(k - used_digits, i - used_digits);
        // x is the number of ways to fill the remaining slots using less than
        // or equal to i unique digits.
        mint x = p * c;
        if (even(k - i)) {
          sum += x;
        } else {
          sum -= x;
        }
      }
      mint c = mint::Comb(16 - used_digits, k - used_digits);
      return c * sum;
    };
    // 1) Slots [0, i) are all 0. Slot i is smaller than the input, if i is 0,
    // otherwise slot i can be any digit. Slots [i+1, N) can be any digit.
    int maxi = i > 0 ? 16 : v[i];
    rep(j, 1, maxi) ans += calc(1);
    // 2) Slots [0, i) are all same as the input. Slot i is smaller than the
    // input. Slots [i+1, N) can be any digit.
    if (i > 0) {
      rep(j, v[i]) {
        set<int> t(s);
        t.insert(j);
        ans += calc(sz(t));
      }
    }
    s.insert(v[i]);
  }
  // 3) If the input satisfies the condition without any change, increment ans.
  if (sz(s) == k) {
    ans += 1;
  }
  wt(ans);
}
