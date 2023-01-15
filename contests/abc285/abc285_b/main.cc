#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, 1, n) {
    int ans = -1;
    rep(l, n) {
      if (l + i == n) break;
      if (s[l] == s[l + i]) break;
      ans = l;
    }
    wt(ans + 1);
  }
}
