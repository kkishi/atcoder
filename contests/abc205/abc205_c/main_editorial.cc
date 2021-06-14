#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  if (even(c)) {
    a = abs(a);
    b = abs(b);
  }
  wt(a == b ? '=' : a > b ? '>' : '<');
}
