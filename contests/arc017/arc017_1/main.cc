#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"

void Main() {
  ints(n);
  wt(sz(Divisors(n)) == 2 ? "YES" : "NO");
}
