#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> d(n);
  cin >> d;
  int sum = 0;
  rep(i, n - 1) rep(j, i + 1, n) sum += d[i] * d[j];
  wt(sum);
}
