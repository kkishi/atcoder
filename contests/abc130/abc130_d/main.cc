#include <bits/stdc++.h>

#include "atcoder.h"
#include "count.h"

void Main() {
  ints(n, k);
  vector<int> a(n);
  cin >> a;
  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];
  int ans = 0;
  rep(i, n) ans += CountLE(s, s[i + 1] - k);
  wt(ans);
}
