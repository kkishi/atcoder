#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  int e = 0, o = 0;
  rep(n) {
    strings(s);
    (even(count(all(s), '1')) ? e : o)++;
  }
  wt(e * o);
}
