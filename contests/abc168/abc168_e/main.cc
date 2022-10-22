#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"
#include "rational.h"

using mint = ModInt<>;
using P = pair<int, int>;

void Main() {
  ints(n);

  int zeros = 0;

  int a_zeros = 0;
  int b_zeros = 0;

  map<P, int> s1;
  map<P, int> s2;

  rep(i, n) {
    ints(a, b);

    if (a == 0 && b == 0) {
      ++zeros;
      continue;
    }
    if (a == 0) {
      ++a_zeros;
      continue;
    }
    if (b == 0) {
      ++b_zeros;
      continue;
    }
    s1[Rational(-b, a).ToPair()]++;
    s2[Rational(a, b).ToPair()]++;
  }

  vector<P> groups;
  each(r, c2, s2) {
    int c1 = s1[r];
    if (c1 != 0 && r.first < 0) continue;
    groups.eb(c2, c1);
  }
  groups.eb(a_zeros, b_zeros);

  mint mul = 1;
  each(a, b, groups) {
    mint m;
    if (b == 0) {
      m = mint(2).Pow(a);
    } else {
      m = mint(2).Pow(a) + mint(2).Pow(b) - 1;
    }
    mul *= m;
  }
  wt(mul - 1 + zeros);
}
