#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  strings(name, kit);
  map<char, int> want;
  for (char c : name) ++want[c];
  map<char, int> kitm;
  for (char c : kit) ++kitm[c];
  int ans = 0;
  for (auto [k, v] : want) {
    if (int u = kitm[k]; u == 0) {
      wt(-1);
      return;
    } else {
      chmax(ans, div_ceil(v, u));
    }
  }
  wt(ans);
}
