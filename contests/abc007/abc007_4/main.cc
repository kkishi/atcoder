#include <bits/stdc++.h>

#include "atcoder.h"

int f(int x) {
  if (x == 0) return 0;
  int tens = 1;
  int eights = 1;
  while (__int128_t(tens) * 10 <= x) {
    tens *= 10;
    eights *= 8;
  }
  int y = x / tens;
  if (y == 9 || y == 4) return f(tens * y - 1);
  if (y >= 4) --y;
  return y * eights + f(x % tens);
}

int g(int x) { return x - f(x); }

void Main() {
  ints(a, b);
  wt(g(b) - g(a - 1));
}
