#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  strings(s);
  int x = 0;
  mint ans = 1;
  rep(i, n * 2) {
    int sp = s[i] == 'B';
    if (x == 0) {
      ++x;
      int xp = x % 2;
      if (sp != xp) {
        wt(0);
        return;
      }
    } else {
      int xp = x % 2;
      if (sp == xp) {
        ans *= x;
        --x;
        if (x < 0) {
          wt(0);
          return;
        }
      } else {
        ++x;
      }
    }
  }
  if (x == 0) {
    wt(ans * mint::Fact(n));
  } else {
    wt(0);
  }
}
