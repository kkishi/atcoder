#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  vector<int> as;
  int bs = 0;
  while (q--) {
    ints(t);
    if (t == 1) {
      ints(a, b);
      as.push_back(a);
      bs += b;
    } else {
      sort(all(as));
      int mid = as[(as.size() - 1) / 2];
      int sum = bs;
      for (int a : as) sum += abs(mid - a);
      wt(mid, sum);
    }
  }
}
