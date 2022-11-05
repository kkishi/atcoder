#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int g = 0;
  each(e, a) g = gcd(g, e);
  int ans = 0;
  each(e, a) {
    int x = e / g;
    while (x % 2 == 0) x /= 2, ++ans;
    while (x % 3 == 0) x /= 3, ++ans;
    if (x != 1) {
      wt(-1);
      return;
    }
  }
  wt(ans);
}
