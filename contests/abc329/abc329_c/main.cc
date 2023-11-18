#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  ints(n);
  strings(s);
  RunLengthQueue q;
  each(e, s) q.PushBack(e, 1);
  int ans = 0;
  map<int, int> mp;
  each(k, v, q) chmax(mp[k], v);
  each(_, e, mp) ans += e;
  wt(ans);
}
