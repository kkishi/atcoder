#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  map<pair<string, string>, int> l, r;
  rep(bits, 1 << n) {
    {
      string x, y;
      rep(i, n)(hasbit(bits, i) ? x : y) += s[i];
      ++l[{x, y}];
    }
    {
      string x, y;
      rrep(i, n)(hasbit(bits, i) ? y : x) += s[n + i];
      ++r[{x, y}];
    }
  }
  int ans = 0;
  for (auto [k, v] : l) ans += v * r[k];
  wt(ans);
}
