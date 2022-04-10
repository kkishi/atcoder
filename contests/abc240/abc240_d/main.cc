#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  ints(n);
  RunLengthQueue que;
  rep(n) {
    ints(a);
    que.PushBack(a, 1);
    if (que.back().second == a) que.PopBack(a);
    wt(que.Size());
  }
}
