#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  ints(n);
  RunLengthQueue que;
  rep(n) {
    ints(c);
    que.PushBack(c, 1);
  }
  if (sz(que) == 1) {
    wt(-1);
  } else {
    int ma = -big;
    each(_, v, que) chmax(ma, v);
    auto [a, b] = que.front();
    auto [c, d] = que.back();
    if (a == c) chmax(ma, b + d);
    wt((ma + 1) / 2);
  }
}
