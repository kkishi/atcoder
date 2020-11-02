#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, s);
  if (n == s) {
    wt(n + 1);
    return;
  }
  int b = 2;
  for (; b * b <= n; ++b) {
    int x = n;
    int f = 0;
    while (x) {
      f += x % b;
      x /= b;
    }
    if (f == s) {
      wt(b);
      return;
    }
  }
  while (b <= n) {
    int c = n / b;
    int d = n % b;
    int e = d / c;
    int base = c + d % c;
    if (base <= s && s <= c + d && (s - base) % c == 0) {
      wt(b + e - (s - base) / c);
      return;
    }
    b += e + 1;
  }
  wt(-1);
}
