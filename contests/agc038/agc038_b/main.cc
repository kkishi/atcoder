#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<int> p(n);
  cin >> p;

  V<bool> all_sorted(n);
  {
    int i = 0;
    while (i < n) {
      int j = i;
      while (j + 1 < n && p[j] < p[j + 1]) ++j;
      for (int l = i; j - l + 1 >= k; ++l) {
        all_sorted[l] = true;
      }
      i = j + 1;
    }
  }

  set<int> s;
  rep(i, k) s.insert(p[i]);
  int ans = 0;
  bool first_all_sorted = true;
  for (int l = 0; l + k <= n;) {
    if (all_sorted[l]) {
      if (first_all_sorted) {
        first_all_sorted = false;
        ++ans;
      }
    } else {
      while (true) {
        int r = l + k;
        if (r == n) break;
        if (p[r] > *prev(s.end()) && p[l] == *s.begin()) {
          s.erase(p[l]);
          s.insert(p[r]);
          ++l;
          continue;
        }
        break;
      }
      ++ans;
    }
    if (l + k <= n) {
      s.erase(p[l]);
      s.insert(p[l + k]);
      ++l;
    }
  }
  wt(ans);
}
