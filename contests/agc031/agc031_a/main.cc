#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  strings(s);
  map<char, int> m;
  each(c, s)++ m[c];
  mint ans = 1;
  each(_, v, m) ans *= v + 1;
  wt(ans - 1);
}
