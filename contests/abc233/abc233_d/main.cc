#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> a(n);
  cin >> a;
  map<int, int> m;
  m[0] = 1;
  int ans = 0;
  int s = 0;
  each(e, a) {
    s += e;
    ans += m[s - k];
    m[s] += 1;
  }
  wt(ans);
}
