#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<3>;

// Lucas's theorem
mint comb(int n, int k) {
  if (n < 3 && k < 3) {
    return mint::Comb(n, k);
  }
  return comb(n % 3, k % 3) * comb(n / 3, k / 3);
}

void Main() {
  ints(n);
  strings(s);
  mint ans = 0;
  string BWR = "BWR";
  rep(i, n) ans += BWR.find(s[i]) * comb(n - 1, i);
  if (even(n)) ans = -ans;
  wt(BWR[ans.value()]);
}
