#include <bits/stdc++.h>

#include "atcoder.h"
#include "rolling_hash.h"

void Main() {
  ints(n);
  strings(s, t);
  string rgb = "RGB";
  int ans = 0;
  each(e, rgb) {
    string u = t;
    each(f, u) if (f != e) f = 'R' + 'G' + 'B' - e - f;
    {
      RollingHash S, U;
      rep(i, n) {
        S.PushFront(s[n - 1 - i]);
        U.PushBack(u[i]);
        if (S == U) ++ans;
      }
    }
    {
      RollingHash S, U;
      deque<char> SQ, UQ;
      rep(i, n - 1) {
        S.PushBack(s[i]);
        U.PushFront(u[n - 1 - i]);
        if (S == U) ++ans;
      }
    }
  }
  wt(ans);
}
