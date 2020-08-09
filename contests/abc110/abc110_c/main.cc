#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s, t);
  vector<set<char>> to(26), from(26);
  rep(i, s.size()) {
    to[s[i] - 'a'].insert(t[i]);
    from[t[i] - 'a'].insert(s[i]);
  }
  rep(i, 26) {
    if (to[i].size() > 1 || from[i].size() > 1) {
      wt("No");
      return 0;
    }
  }
  wt("Yes");
}
