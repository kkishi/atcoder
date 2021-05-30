#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> ma = a;
  rep(i, n - 1) chmax(ma[i + 1], ma[i]);
  V<int> sa = a;
  rep(i, n - 1) sa[i + 1] += sa[i];
  int sum = 0;
  rep(i, n) {
    int x = 0;
    x += sa[i];
    x += ma[i] * (i + 1);
    x += sum;
    wt(x);
    sum += sa[i];
  }
}
