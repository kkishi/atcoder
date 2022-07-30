#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> cnt(100001);
  int ans = -big;
  int l = 0, r = 0;
  rep(n) {
    while (r < n && cnt[a[r]] == 0) {
      ++cnt[a[r++]];
    }
    chmax(ans, r - l);
    --cnt[a[l++]];
  }
  wt(ans);
}
