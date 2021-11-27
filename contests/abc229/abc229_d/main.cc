#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(k);
  int n = sz(s);
  int l = 0, r = 0;
  while (r < n) {
    if (s[r] == '.') {
      if (k == 0) break;
      --k;
    }
    ++r;
  }
  int ans = r - l;
  while (r < n) {
    do {
      ++r;
    } while (r < n && s[r] != '.');
    do {
      ++l;
    } while (l < r && s[l - 1] != '.');
    chmax(ans, r - l);
  }
  wt(ans);
}
