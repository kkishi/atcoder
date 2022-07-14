#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  wt([]() {
    strings(s, t);
    RunLengthQueue S, T;
    each(e, s) S.PushBack(e, 1);
    each(e, t) T.PushBack(e, 1);
    if (sz(S) != sz(T)) return false;
    rep(i, sz(S)) {
      if (S[i].first != T[i].first) return false;
      int a = S[i].second;
      int b = T[i].second;
      if (a != b && (a == 1 || a > b)) return false;
    }
    return true;
  }());
}
