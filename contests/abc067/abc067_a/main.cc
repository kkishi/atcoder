#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  wt((a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) ? "Possible"
                                                    : "Impossible");
}
