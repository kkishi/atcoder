#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  if (s == t) {
    wt("same");
    return;
  }
  each(x, s) x = tolower(x);
  each(x, t) x = tolower(x);
  if (s == t) {
    wt("case-insensitive");
    return;
  }
  wt("different");
}
