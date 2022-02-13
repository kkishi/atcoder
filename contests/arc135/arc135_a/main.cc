#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

map<int, mint> m;

mint rec(int x) {
  if (m.count(x)) return m[x];
  if (x <= 3) return x;
  int y = x / 2;
  m[x] = rec(y) * rec(x - y);
  return m[x];
}

void Main() {
  ints(x);
  wt(rec(x));
}
