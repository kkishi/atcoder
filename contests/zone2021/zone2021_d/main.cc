#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  deque<char> q;
  bool rev = false;
  each(c, s) {
    if (c == 'R') {
      rev = !rev;
    } else {
      if (rev)
        q.push_front(c);
      else
        q.push_back(c);
    }
  }
  string t;
  while (!q.empty()) {
    t += q.front();
    q.pop_front();
  }
  if (rev) reverse(all(t));
  string T;
  rep(i, sz(t)) {
    if (!T.empty() && T.back() == t[i]) {
      T.pop_back();
    } else {
      T += t[i];
    }
  }
  wt(T);
}
