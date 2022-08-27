#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Rand r;
  V<int> v;
  rep(3) v.eb(r.Int(1, 2));
  v.eb(r.Int(0, min(v[0], v[1])));
  wt(v);
}
