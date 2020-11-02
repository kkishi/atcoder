#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, n);
  int l = a * b / gcd(a, b);
  wt((n + l - 1) / l * l);
}
