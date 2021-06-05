#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  int g = gcd(a, gcd(b, c));
  wt((a + b + c) / g - 3);
}
