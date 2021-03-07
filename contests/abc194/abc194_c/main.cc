#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<int, int> cnt;
  rep(n) {
    ints(a);
    ++cnt[a];
  }
  int ans = 0;
  rep(i, -200, 201) rep(j, i + 1, 201) {
    ans += (j - i) * (j - i) * cnt[i] * cnt[j];
  }
  wt(ans);
}
