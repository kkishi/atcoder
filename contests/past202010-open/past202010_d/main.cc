#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);

  auto f = [&] { rep(i, 1, n) if (s[i] == '#') s[i - 1] = '#'; };

  int x = 0;
  while (s[0] != '#') {
    ++x;
    f();
  }
  reverse(s);

  int y = 0;
  while (s[0] != '#') {
    ++y;
    f();
  }
  reverse(s);

  rrep(i, 1, n) if (s[i] == '#' && s[i - 1] == '.') {
    ++x;
    f();
  }

  rep(i, n - 1) if (s[i] == '#' && s[i + 1] == '.') {
    ++y;
    f();
  }

  wt(x, y);
}
