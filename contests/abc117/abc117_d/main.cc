#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  vector<int> a(n);
  cin >> a;

  int bit = 1, shifts = 0;
  while ((bit << 1) <= k) {
    bit <<= 1;
    ++shifts;
  }

  vector<int> cnt(shifts + 1);
  rep(i, n) rep(j, shifts + 1) if (hasbit(a[i], j))++ cnt[j];

  int x = 0;
  for (int i = shifts; i >= 0; --i) {
    if ((x | (1LL << i)) > k) continue;
    if (cnt[i] < (n - cnt[i])) x |= (1LL << i);
  }
  dbg(x);
  int ans = 0;
  for (int ai : a) ans += ai ^ x;
  wt(ans);
}
