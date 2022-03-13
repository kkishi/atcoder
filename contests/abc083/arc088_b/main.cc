#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  string r = s;
  reverse(r);
  if (sz(s) & 1) {
    int i = sz(s) / 2;
    char c = s[i];
    while (i + 1 < sz(s) && s[i + 1] == c && r[i + 1] == c) ++i;
    wt(i + 1);
  } else {
    int i = sz(s) / 2;
    char c = s[i];
    if (c != s[i - 1]) {
      wt(sz(s) / 2);
    } else {
      while (i + 1 < sz(s) && s[i + 1] == c && r[i + 1] == c) ++i;
      wt(i + 1);
    }
  }
}
