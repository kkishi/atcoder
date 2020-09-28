#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, m);
  int ans = 0;
  V<int> seen(m, -1);
  V<int> prev(m);
  rep(i, 1, n + 1) {
    ans += x;
    prev[x] = ans;
    seen[x] = i;
    if (i == n) break;
    int nx = (x * x) % m;
    if (int s = seen[nx]; s != -1) {
      int ni = i + 1;
      int rem = n - ni;
      int dist = ni - s;
      int loop = rem / dist;
      i += loop * dist;
      ans += (ans - prev[nx] + nx) * loop;
    }
    x = nx;
  }
  wt(ans);
}
