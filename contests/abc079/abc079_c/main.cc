#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(a);
  rep(s, 1 << 3) {
    int sum = a[0] - '0';
    rep(i, 3) {
      if (hasbit(s, i)) {
        sum += a[i + 1] - '0';
      } else {
        sum -= a[i + 1] - '0';
      }
    }
    if (sum == 7) {
      cout << a[0];
      rep(i, 3) {
        cout << (hasbit(s, i) ? '+' : '-');
        cout << a[i + 1];
      }
      cout << "=7" << endl;
      return;
    }
  }
}
