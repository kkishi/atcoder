#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"

void Main() {
  ints(n);
  int sum = 0;
  each(_, e, Factors(n)) sum += e;
  int ans = 0;
  int two = 1;
  while (two < sum) {
    ++ans;
    two *= 2;
  }
  wt(ans);
}
