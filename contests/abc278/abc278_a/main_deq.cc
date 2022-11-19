#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  deque<int> a;
  rep(n) {
    ints(x);
    a.push_back(x);
  }
  rep(k) {
    a.pop_front();
    a.push_back(0);
  }
  wt(a);
}
