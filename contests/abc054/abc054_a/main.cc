#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  if (a == 1) a = 14;
  if (b == 1) b = 14;
  wt(a == b ? "Draw" : a > b ? "Alice" : "Bob");
}
