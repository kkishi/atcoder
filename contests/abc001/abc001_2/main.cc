#include <bits/stdc++.h>

#include "atcoder.h"

int vv(int m) {
  if (m < 100) return 0;
  if (m <= 5000) return m * 10 / 1000;
  if (m <= 30000) return m / 1000 + 50;
  if (m <= 70000) return (m / 1000 - 30) / 5 + 80;
  return 89;
}

void Main() {
  ints(m);
  printf("%02ld\n", vv(m));
}
