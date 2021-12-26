#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(l, r);
  strings(s);
  reverse(s.begin() + l - 1, s.begin() + r);
  wt(s);
}
