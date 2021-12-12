#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<string, int> m;
  rep(n) {
    strings(s);
    ++m[s];
  }
  string ans;
  int ma = -big;
  each(k, v, m) if (chmax(ma, v)) ans = k;
  wt(ans);
}
