#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  deque<int> Q;
  rep(q) {
    ints(t, x);
    if (t == 1) Q.push_front(x);
    if (t == 2) Q.push_back(x);
    if (t == 3) wt(Q[x - 1]);
  }
}
