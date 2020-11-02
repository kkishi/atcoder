#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  int x = n / k;
  int ans = x * x * x;
  if (!(k & 1)) {
    int y = (n + k / 2) / k;
    ans += y * y * y;
  }
  wt(ans);
}
