#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<int> a(n + 1);
  rep(i, n) cin >> a[i + 1];
  vector<int> b(n + 1);
  for (int i = n; i >= 1; --i) {
    int sum = 0;
    for (int j = i + i; j <= n; j += i) {
      sum += b[j];
    }
    if (sum % 2 != a[i]) {
      b[i] = 1;
    }
  }
  wt(accumulate(all(b), 0));
  rep(i, n) if (b[i + 1] == 1) wt(i + 1);
}
