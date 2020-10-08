#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int r = count(all(s), 'R');
  wt(r > n - r);
}
