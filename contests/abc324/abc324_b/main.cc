#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  while (n % 2 == 0) n /= 2;
  while (n % 3 == 0) n /= 3;
  wt(n == 1);
}
