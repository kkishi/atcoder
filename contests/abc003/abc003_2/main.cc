#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  wt([&] {
    rep(i, sz(s)) if (s[i] != t[i]) {
      char c;
      if (s[i] == '@') {
        c = t[i];
      } else if (t[i] == '@') {
        c = s[i];
      } else {
        return false;
      }
      if (!set{'a', 't', 'c', 'o', 'd', 'e', 'r'}.count(c)) return false;
    }
    return true;
  }()
         ? "You can win"
         : "You will lose");
}
