#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  int n = 5;
  string s;
  Rand r;
  rep(n) s += (char)r.Int('a', 'z');
  wt(n);
  wt(s);
  int q = 5;
  wt(q);
  rep(i, q) {
    if (i % 2 == 0) {
      wt(1, r.Int(1, n), (char)r.Int('a', 'z'));
    } else {
      int L = r.Int(1, n);
      int R = r.Int(1, n);
      if (L > R) swap(L, R);
      wt(2, L, R);
    }
  }
}
