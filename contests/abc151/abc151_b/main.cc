#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, K, M);
  int sum = 0;
  rep(i, N - 1) {
    ints(A);
    sum += A;
  }
  int ans = max(0, M * N - sum);
  if (ans > K) ans = -1;
  wt(ans);
}
