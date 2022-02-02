#include <bits/stdc++.h>

#include "atcoder.h"

int f(int x) { return x * x + 2 * x + 3; }

void Main() {
  ints(t);
  wt(f(f(f(t) + t) + f(f(t))));
}
