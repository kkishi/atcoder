#include <bits/stdc++.h>

#include "atcoder.h"

int highest(int x) {
  while (x >= 10) x /= 10;
  return x;
}

int cnt[10][10];

void Main() {
  ints(N);
  for (int i = 1; i <= N; ++i) {
    ++cnt[i % 10][highest(i)];
  }
  int ans = 0;
  rep(i, 10) rep(j, 10) ans += cnt[i][j] * cnt[j][i];
  wt(ans);
}
