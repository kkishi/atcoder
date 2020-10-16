#include <bits/stdc++.h>

#include "atcoder.h"
#include "warshall_floyd.h"

void Main() {
  ints(h, w);
  VV<int> c(10, V<int>(10));
  cin >> c;
  WarshallFloyd(c);
  int ans = 0;
  rep(i, h * w) {
    ints(a);
    if (a != -1) ans += c[a][1];
  }
  wt(ans);
}
