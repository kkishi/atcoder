#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l, r);
  V<int> a(n);
  cin >> a;
  int G = 0;
  rep(i, n) {
    int N = a[i];
    N %= r + l;
    N /= l;
    G ^= N;
  }
  if (G == 0) {
    wt("Second");
  } else {
    wt("First");
  }
}
