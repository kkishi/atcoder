#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(t);
  rep(i, t) {
    wt([] {
      V<int> a(6), b(6);
      rep(i, 5) cin >> a[i + 1];
      rep(i, 5) cin >> b[i + 1];
      auto sub = [&](int x, int y) {
        if (b[y] == 0) return false;
        int z = min(a[x], b[y]);
        a[x] -= z;
        b[y] -= z;
        if (y - x > 0) {
          b[y - x] += z;
        }
        return true;
      };
      sub(5, 5);
      sub(4, 4);
      sub(4, 5);
      sub(3, 3);
      sub(3, 5);
      sub(3, 4);
      sub(2, 5);
      sub(2, 4);
      sub(2, 3);
      sub(2, 2);
      sub(1, 5);
      sub(1, 4);
      sub(1, 3);
      sub(1, 2);
      sub(1, 1);
      return accumulate(a) == 0;
    }());
  }
}
