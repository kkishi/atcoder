#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"

void Main() {
  ints(n);
  VV<int> v(200001);
  rep(i, n) {
    ints(a);
    v[a].eb(i);
  }
  ints(q);
  rep(i, q) {
    ints(l, r, x);
    --l;
    --r;
    wt(CountLE(v[x], r) - CountLT(v[x], l));
  }
}
