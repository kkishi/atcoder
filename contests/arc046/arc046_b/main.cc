#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, a, b);
  wt((a == b ? ((n - a) % (a + 1) != 1) : (a > b || n <= a)) ? "Takahashi"
                                                             : "Aoki");
}
