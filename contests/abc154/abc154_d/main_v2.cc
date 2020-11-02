#include <bits/stdc++.h>

#include "atcoder.h"

int p[200000];

double exp(int i) { return p[i] * (p[i] + 1) / 2 / (double)(p[i]); }

void Main() {
  ints(N, K);
  rep(i, N) cin >> p[i];
  double sum = 0;
  double ans = 0;
  rep(i, N) {
    if (i >= K) sum -= exp(i - K);
    sum += exp(i);
    if (i >= K - 1) ans = max(ans, sum);
  }
  printf("%.12f\n", ans);
}
