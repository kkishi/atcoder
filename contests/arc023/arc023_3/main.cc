#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  mint ans = 1;
  int i = 0;
  while (i < n - 1) {
    int j = i + 1;
    while (a[j] == -1) ++j;
    int x = a[j] - a[i];
    int y = j - i;
    ans *= mint::CombSlow(y - 1 + x, y - 1);
    i = j;
  }
  wt(ans);
}
