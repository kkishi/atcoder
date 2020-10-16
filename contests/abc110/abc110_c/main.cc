#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  vector<set<char>> to(26), from(26);
  rep(i, s.size()) {
    to[s[i] - 'a'].insert(t[i]);
    from[t[i] - 'a'].insert(s[i]);
  }
  bool ok = true;
  rep(i, 26) if (to[i].size() > 1 || from[i].size() > 1) ok = false;
  wt(ok);
}
