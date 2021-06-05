#include <bits/stdc++.h>

#include "atcoder.h"
#include "i128.h"

void Main() {
  ints(a, b);
  i128 l = i128(a) * i128(b) / gcd(a, b);
  if (l > 1000000000000000000LL) {
    wt("Large");
  } else {
    wt(l);
  }
}
