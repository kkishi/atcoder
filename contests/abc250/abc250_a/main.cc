#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, r, c);
  int ans = 0;
  each(nr, nc, adjacent(r - 1, c - 1)) if (inside(nr, nc, h, w))++ ans;
  wt(ans);
}
