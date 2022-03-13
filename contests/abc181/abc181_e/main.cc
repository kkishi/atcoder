#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> h(n), w(m);
  cin >> h >> w;
  sort(h);
  dbg(h);

  set<int> ws(all(w));

  V<int> l(n);
  l[0] = 0;
  for (int i = 2; i < n; i += 2) {
    l[i] += l[i - 2] + h[i - 1] - h[i - 2];
  }
  V<int> r(n);
  r[n - 1] = 0;
  for (int i = n - 3; i >= 0; i -= 2) {
    r[i] += r[i + 2] + h[i + 2] - h[i + 1];
  }
  dbg(l);
  dbg(r);
  int ans = big;
  for (int i = 0; i < n; i += 2) {
    auto it = ws.lower_bound(h[i]);
    if (it == ws.end()) --it;
    dbg(h[i], *it);
    int x = abs(h[i] - *it);
    if (it != ws.begin()) {
      chmin(x, abs(h[i] - *prev(it)));
    }
    dbg(h[i], x, l[i], r[i]);
    chmin(ans, l[i] + x + r[i]);
  }
  wt(ans);
}
