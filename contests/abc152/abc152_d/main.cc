#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int highest(int x) {
  while (x >= 10) x /= 10;
  return x;
}

ll cnt[10][10];

int main() {
  rd(int, N);
  for (int i = 1; i <= N; ++i) {
    ++cnt[i % 10][highest(i)];
  }
  ll ans = 0;
  rep(i, 10) rep(j, 10) ans += cnt[i][j] * cnt[j][i];
  wt(ans);
}
