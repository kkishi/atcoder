#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, c, k, s, t);
  wt(s * a + t * b - (s + t < k ? 0 : c * (s + t)));
}
