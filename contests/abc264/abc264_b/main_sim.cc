#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  vector v(15, vector(15, string("")));
  rep(i, 8) rep(r, i, 15 - i) rep(c, i, 15 - i) {
    v[r][c] = even(i) ? "black" : "white";
  }
  ints(r, c);
  wt(v[r - 1][c - 1]);
}
