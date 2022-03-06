#include <bits/stdc++.h>

#include "atcoder.h"
#include "mo.h"
#include "sieve.h"

void Main() {
  ints(n, q);

  VV<pair<int, int>> fs(n);
  const int N = 1000000;
  Sieve s(N);
  rep(i, n) {
    ints(a);
    each(k, v, s.Factors(a)) {
      if (v % 3) fs[i].eb(k, v % 3);
    }
  }

  V<pair<int, int>> qs;
  rep(q) {
    ints(l, r);
    qs.eb(l - 1, r);
  }

  V<int8_t> v(N);
  int nonzero = 0;
  auto update = [&](int a, int b) {
    if (a != 0 && b == 0) --nonzero;
    if (a == 0 && b != 0) ++nonzero;
  };
  auto add = [&](int i) {
    each(f, n, fs[i]) {
      int vf = v[f];
      v[f] += n;
      v[f] %= 3;
      update(vf, v[f]);
    }
  };
  auto del = [&](int i) {
    each(f, n, fs[i]) {
      int vf = v[f];
      v[f] += 3 - n;
      v[f] %= 3;
      update(vf, v[f]);
    }
  };
  auto get = [&] { return nonzero == 0; };

  each(e, Mo(add, del, get, qs)) wt(e == 1);
}
