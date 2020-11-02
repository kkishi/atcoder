#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, x, y);
  V<int> a(n), b(m);
  cin >> a >> b;
  auto ai = a.begin(), bi = b.begin();
  int t = 0;
  int airport = 0;
  int ans = 0;
  while (true) {
    if (airport == 0) {
      while (ai != a.end() && *ai < t) ++ai;
      if (ai == a.end()) break;
      t = *ai + x;
      airport = 1;
    } else {
      while (bi != b.end() && *bi < t) ++bi;
      if (bi == b.end()) break;
      t = *bi + y;
      airport = 0;
      ++ans;
    }
  }
  wt(ans);
}
