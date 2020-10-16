#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c);
  wt(a == b && b != c || b == c && c != a || c == a && a != b);
}
