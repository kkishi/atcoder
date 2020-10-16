#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  if (n % 2) {
    wt(0);
  } else {
    int ans = 0;
    int fives = 1;
    while (__int128_t(fives) * 5 <= n) {
      fives *= 5;
      ans += n / fives / 2;
    }
    wt(ans);
  }
}
