#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  deque<char> q(all(s));
  s = "";
  while (!q.empty()) {
    if (sz(q) >= 3 && q[0] == 'A' && q[1] == 'B' && q[2] == 'C') {
        rep(3) q.pop_front();
        rep(2) if (!s.empty()) {
          q.push_front(s.back());
          s.pop_back();
        }
    } else {
      s += q.front();
      q.pop_front();
    }
  }
  wt(s);
}
