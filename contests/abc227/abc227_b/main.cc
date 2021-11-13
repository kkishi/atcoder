#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<int, bool> m;
  for (int a = 1;; ++a) {
    int s = 3 * a;
    if (s > 1000) break;
    for (int b = 1;; ++b) {
      int S = s + 4 * a * b + 3 * b;
      if (S > 1000) break;
      m[S] = true;
    }
  }
  int ans = 0;
  rep(n) {
    ints(s);
    if (!m[s]) ++ans;
  }
  wt(ans);
}
