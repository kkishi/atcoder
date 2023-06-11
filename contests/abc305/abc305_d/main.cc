#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<tuple<int, int, int>> v;
  int wakeup = 0, sleep = 1, query_l = 2, query_r = 3;
  rep(i, n) {
    ints(a);
    if (even(i)) {
      v.eb(a, wakeup, -1);
    } else {
      v.eb(a, sleep, -1);
    }
  }
  ints(q);
  rep(i, q) {
    ints(l, r);
    v.eb(l, query_l, i);
    v.eb(r, query_r, i);
  }
  sort(v);
  V<int> ans(q, -1);
  V<int> query(q, -1);
  int last_wakeup = -1;
  int awake = 0;
  each(e, v) {
    auto [time, kind, query_i] = e;
    if (kind == wakeup) {
      assert(last_wakeup == -1);
      last_wakeup = time;
    } else if (kind == sleep) {
      assert(last_wakeup != -1);
      int d = time - last_wakeup;
      assert(d >= 0);
      last_wakeup = -1;
      awake += d;
    } else if (kind == query_l) {
      if (last_wakeup != -1) {
        awake += time - last_wakeup;
        last_wakeup = time;
      }
      assert(0 <= query_i && query_i < q);
      assert(query[query_i] == -1);
      query[query_i] = time - awake;
    } else {
      assert(kind == query_r);
      assert(ans[query_i] == -1);
      if (last_wakeup != -1) {
        awake += time - last_wakeup;
        last_wakeup = time;
      }
      assert(0 <= query_i && query_i < q);
      assert(query[query_i] != -1);
      ans[query_i] = time - awake - query[query_i];
    }
  }
  each(e, ans) wt(e);
}
