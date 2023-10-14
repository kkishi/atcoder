#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  V<int> cnt(10);
  each(e, s)++ cnt[e - '0'];
  int ans = 0;
  for (int i = 0; i <= 4000000; ++i) {
    int j = i * i;
    V<int> cnt2(10);
    while (j) {
      ++cnt2[j % 10];
      j /= 10;
    }
    bool ok = cnt[0] >= cnt2[0];
    rep(j, 1, 10) if (cnt[j] != cnt2[j]) ok = false;
    if (ok) {
      ++ans;
    }
  }
  wt(ans);
}
