#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  string ans;
  rep(i, n) {
    if (i + 1 < n && s[i] == 'n' && s[i + 1] == 'a') {
      ++i;
      ans += "nya";
    } else {
      ans += s[i];
    }
  }
  wt(ans);
}
