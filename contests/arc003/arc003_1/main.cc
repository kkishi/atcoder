#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(r);
  double ans = 0;
  each(e, r) if (e != 'F') ans += 4 - (e - 'A');
  wt(ans / n);
}
