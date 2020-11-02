#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  set<int> s;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  for (int si : s) wt(si);
}
