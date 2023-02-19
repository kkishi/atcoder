#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(s);
  string ans(n, 'x');
  rep(i, n) {
    if (k > 0 && s[i] == 'o') {
      ans[i] = 'o';
      --k;
    }
  }
  wt(ans);
}
