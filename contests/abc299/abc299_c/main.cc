#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  ints(n);
  strings(s);
  RunLengthQueue que;
  each(e, s) que.PushBack(e, 1);
  int ans = -1;
  rep(i, sz(que)) {
    if (que[i].first == 'o') {
      if (i > 0 || i + 1 < sz(que)) chmax(ans, que[i].second);
    }
  }
  wt(ans);
}
