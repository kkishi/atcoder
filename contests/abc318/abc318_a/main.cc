#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, p);
  if (n < m) {
    wt(0);
  } else {
    wt(1 + (n - m) / p);
  }
}
