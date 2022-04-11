#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> b = a;
  sort(b);
  map<int, int> m;
  for (int i = 0; i < n; i += 2) {
    m[b[i]]++;
    m[a[i]]--;
  }
  int ans = 0;
  each(_, x, m) if (x > 0) ans += x;
  wt(ans);
}
