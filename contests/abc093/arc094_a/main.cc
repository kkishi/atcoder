#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  int ans = 0;
  while (true) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (a > 0) c -= a, b -= a, a = 0;
    if (c == 0) break;
    if (a == b) {
      ++a, ++b;
    } else {
      a += 2;
    }
    ++ans;
  };
  wt(ans);
}
