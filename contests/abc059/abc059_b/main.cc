#include <bits/stdc++.h>

#include "atcoder.h"
#include "bignum.h"

void Main() {
  rd(bigint, a, b);
  wt(a == b ? "EQUAL" : a < b ? "LESS" : "GREATER");
}
