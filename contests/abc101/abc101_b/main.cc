#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int sn = 0;
  for (int i = n; i > 0; i /= 10) sn += i % 10;
  wt(n % sn == 0);
}
