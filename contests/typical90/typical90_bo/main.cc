#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(n);
  ints(k);
  rep(k) {
    int x = 0;
    each(e, n)(x *= 8) += e - '0';
    if (x == 0) {
      n = "0";
    } else {
      n = "";
      while (x) {
        n += '0' + x % 9;
        x /= 9;
      }
      reverse(n);
    }
    each(e, n) if (e == '8') e = '5';
  }
  wt(n);
}
