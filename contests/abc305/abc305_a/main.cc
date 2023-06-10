#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int rem = n % 5;
  if (rem <= 2) {
    wt(n - rem);
  } else {
    wt(n + 5 - rem);
  }
}
