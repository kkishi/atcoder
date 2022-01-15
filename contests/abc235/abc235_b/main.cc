#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> h(n);
  cin >> h;
  int i = 0;
  while (i + 1 < n && h[i] < h[i + 1]) ++i;
  wt(h[i]);
}
