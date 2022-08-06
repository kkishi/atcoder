#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  map<int, int> mp;
  rep(5) {
    ints(x);
    ++mp[x];
  }
  V<int> v;
  each(_, e, mp) v.eb(e);
  sort(v);
  wt(v == V<int>{2, 3});
}
