#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(S);
  ints(Q);
  bool flipped = false;
  string head, tail;
  rep(Q) {
    ints(T);
    if (T == 1) {
      flipped = !flipped;
      continue;
    }
    ints(F);
    rd(char, C);
    (((F == 1) ^ flipped) ? head : tail) += C;
  }
  reverse(head);
  string s = head + S + tail;
  if (flipped) {
    reverse(s);
  }
  wt(s);
}
