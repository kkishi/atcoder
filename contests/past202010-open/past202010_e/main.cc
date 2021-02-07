#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  string t = s;
  reverse(all(t));
  string u = s;
  sort(all(u));
  do {
    if (u != s && u != t) {
      wt(u);
      return;
    }
  } while (next_permutation(all(u)));
  wt("None");
}
