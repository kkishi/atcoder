#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  V<string> v;
  rep(i, sz(s)) v.eb(s.substr(i) + s.substr(0, i));
  sort(all(v));
  wt(v[0]);
  wt(v.back());
}
