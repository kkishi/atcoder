// https://atcoder.jp/contests/abc200/editorial/1822
#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  strings(s);
  ints(k);
  if (sz(s) == 1 && k == 1) {
    wt(0);
    return;
  }
  mint e = 0;
  int n = sz(s);
  rep(i, n) {
    char c = s[i], d = s[(i + 1) % n];
    if (c == '?' || d == '?') {
      e += 1 / mint(2);
    } else if (c != d) {
      e += 1;
    }
  }
  wt(e * k / 2 * mint(2).Pow(count(all(s), '?') * k));
}
