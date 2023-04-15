#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  strings(x);
  mint s1 = 0;
  mint s2 = 1;
  each(e, x) {
    e -= '0';
    mint ns1 = s1 * 10 + s2 * e + s1 * e;
    mint ns2 = s2 + s1;
    s1 = ns1;
    s2 = ns2;
  }
  wt(s1);
}
