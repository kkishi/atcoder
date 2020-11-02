#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<string, int> m;
  rep(n) {
    strings(s);
    m[s]++;
  }
  int x = 0;
  string ans;
  for (auto [k, v] : m)
    if (chmax(x, v)) ans = k;
  wt(ans);
}
