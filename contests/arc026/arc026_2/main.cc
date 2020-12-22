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
  s.erase(n);
  int sum = accumulate(all(s), int(0));
  wt(sum == n ? "Perfect" : sum < n ? "Deficient" : "Abundant");
}
