#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  int sa = a * (a + 1) / 2;
  int sb = b * (b + 1) / 2;
  V<int> v;
  rep(i, a) v.pb(sb * (i + 1));
  rep(i, b) v.pb(-sa * (i + 1));
  wt(v);
}
