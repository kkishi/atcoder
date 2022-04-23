#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int N = 200000;
  V<int> cn(N + 1);
  each(e, a)++ cn[e];
  int ans = 0;
  rep(b, 1, N + 1) {
    for (int c = 1; b * c <= N; ++c) {
      ans += cn[b * c] * cn[b] * cn[c];
    }
  }
  wt(ans);
}
