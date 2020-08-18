#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
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
    char C;
    cin >> C;
    (((F == 1) ^ flipped) ? head : tail) += C;
  }
  reverse(all(head));
  string s = head + S + tail;
  if (flipped) {
    reverse(all(s));
  }
  wt(s);
}
