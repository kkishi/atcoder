#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  ints(l, n1, n2);
  RunLengthQueue a, b;
  rep(n1) {
    ints(v, l);
    a.PushBack(v, l);
  }
  rep(n2) {
    ints(v, l);
    b.PushBack(v, l);
  }
  int ans = 0;
  while (!a.empty()) {
    auto [va, ca] = a.back();
    auto [vb, cb] = b.back();
    int cnt = min(ca, cb);
    if (va == vb) ans += cnt;
    a.PopBack(cnt);
    b.PopBack(cnt);
  }
  wt(ans);
}
