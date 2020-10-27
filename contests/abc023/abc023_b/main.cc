#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  string a = "b";
  for (int i = 0; sz(a) <= sz(s); ++i) {
    if (a == s) {
      wt(i);
      return;
    }
    if (i % 3 == 0) {
      a = 'a' + a + 'c';
    } else if (i % 3 == 1) {
      a = 'c' + a + 'a';
    } else {
      a = 'b' + a + 'b';
    }
  }
  wt(-1);
}
