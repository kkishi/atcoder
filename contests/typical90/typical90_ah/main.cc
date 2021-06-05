#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  int i = 0, j = 0;
  map<int, int> m;
  int ans = 0;
  while (j < n) {
    ++m[a[j]];
    ++j;
    while (sz(m) > k) {
      --m[a[i]];
      if (m[a[i]] == 0) m.erase(a[i]);
      ++i;
    }
    chmax(ans, j - i);
  }
  wt(ans);
}
