#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  strings(s);
  V<int> v(n + 1);
  rep(i, n) v[i + 1] = v[i] + (s[i] == '(' ? 1 : -1);
  add_min::segtree t(v);
  rep(q) {
    ints(k, l, r);
    if (k == 1) {
      char L = s[l - 1];
      char R = s[r - 1];
      swap(s[l - 1], s[r - 1]);
      if (L == '(' && R == ')') t.apply(l, r, -2);
      if (L == ')' && R == '(') t.apply(l, r, +2);
    } else {
      int L = t.get(l - 1);
      int R = t.get(r);
      wt(L == R && t.prod(l, r) >= L);
    }
  }
}
