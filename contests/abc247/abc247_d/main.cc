#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  ints(q);
  RunLengthQueue que;
  rep(q) {
    ints(k);
    if (k == 1) {
      ints(x, c);
      que.PushBack(x, c);
    } else {
      ints(c);
      int ans = 0;
      each(val, cnt, que.PopFront(c)) ans += val * cnt;
      wt(ans);
    }
  }
}
