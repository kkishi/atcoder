#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  map<char, int> m;
  each(c, s)++ m[c];
  V<pair<int, char>> v;
  each(x, y, m) v.eb(y, x);
  sort(all(v), greater{});
  wt(v[0].second);
}
