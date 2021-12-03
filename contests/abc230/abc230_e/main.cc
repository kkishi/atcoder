#include <bits/stdc++.h>

#include "atcoder.h"
#include "quotients.h"

void Main() {
  ints(n);
  int ans = 0;
  each(k, v, Quotients(n)) ans += k * v;
  wt(ans);
}
