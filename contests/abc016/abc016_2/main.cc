#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  int e = a + b, d = a - b;
  wt((c == e && c == d) ? '?' : c == e ? '+' : c == d ? '-' : '!');
}
