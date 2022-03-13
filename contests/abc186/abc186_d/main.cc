#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(a);
  reverse(a);
  int ans = 0;
  int sum = 0;
  rep(i, n) {
    ans += sum - i * a[i];
    sum += a[i];
  }
  wt(ans);
}
