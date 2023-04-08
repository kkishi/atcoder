#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(n, k);
  vector a(n, vector(n, int(0)));
  cin >> a;
  each(e, a) each(e, e) if (e == 0) e = big;
  WarshallFloyd(a);
  ints(q);
  rep(q) {
    ints(s, t);
    --s, --t;
    s %= n;
    t %= n;
    int ans = a[s][t];
    if (ans >= big) ans = -1;
    wt(ans);
  }
}
