#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  deque<int> q;
  rep(i, n) {
    char c = s[i];
    if (c == 'L') q.push_front(i);
    if (c == 'R') q.push_back(i);
    auto f = [&](int x) {
      if (sz(q) < x) {
        wt("ERROR");
        return;
      }
      V<int> v;
      rep(x) {
        v.pb(q.front());
        q.pop_front();
      }
      wt(v.back() + 1);
      v.pop_back();
      while (!v.empty()) {
        q.push_front(v.back());
        v.pop_back();
      }
    };
    auto b = [&](int x) {
      if (sz(q) < x) {
        wt("ERROR");
        return;
      }
      V<int> v;
      rep(x) {
        v.pb(q.back());
        q.pop_back();
      }
      wt(v.back() + 1);
      v.pop_back();
      while (!v.empty()) {
        q.push_back(v.back());
        v.pop_back();
      }
    };
    if (c == 'A') f(1);
    if (c == 'B') f(2);
    if (c == 'C') f(3);
    if (c == 'D') b(1);
    if (c == 'E') b(2);
    if (c == 'F') b(3);
  }
}
