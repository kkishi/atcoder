#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  if (!n) {
    wt(0);
    return;
  }
  string ans;
  int bit = 1;
  while (n) {
    if (abs(n) % 2 == 1) {
      n -= 1;
      ans = '1' + ans;
    } else {
      ans = '0' + ans;
    }
    n /= -2;
    bit <<= 1;
  }
  wt(ans);
}
