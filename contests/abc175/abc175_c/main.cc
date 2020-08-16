#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  rd(int, x, k, d);
  if (x < 0) x = -x;
  if (x / d > k) {
    wt(x - k * d);
    return 0;
  }
  int y = x % d;
  k -= x / d;
  k %= 2;
  if (k == 1) y = d - y;
  wt(y);
#undef int
}
