#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  map<string, int> m;
  rep(n) {
    strings(s);
    ++m[s];
  }
  map<int, int> cnts;
  V<pair<int, string>> v;
  each(s, cnt, m) {
    v.eb(cnt, s);
    ++cnts[cnt];
  }
  sort(v, greater{});
  auto [cnt, s] = v[k - 1];
  if (cnts[cnt] != 1) {
    wt("AMBIGUOUS");
  } else {
    wt(s);
  }
}
