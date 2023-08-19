#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  ints(q);
  V<pair<int, char>> ch;
  rep(i, n) ch.eb(i, s[i]);
  int state = 0;
  rep(q) {
    ints(t, x);
    rd(char, c);
    if (t == 1) {
      ch.eb(x - 1, c);
    } else {
      each(i, c, ch) s[i] = c;
      ch.clear();
      state = t;
    }
  }
  if (state == 2) each(e, s) e = tolower(e);
  if (state == 3) each(e, s) e = toupper(e);
  each(i, c, ch) s[i] = c;
  wt(s);
}
