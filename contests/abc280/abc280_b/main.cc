#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> s(n);
  cin >> s;
  int sum = 0;
  V<int> a(n);
  rep(i, n) {
    a[i] = s[i] - sum;
    sum += a[i];
  }
  wt(a);
}
