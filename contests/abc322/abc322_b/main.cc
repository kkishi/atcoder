#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  strings(s, t);
  bool a = t.substr(0, n) == s;
  bool b = t.substr(m - n, n) == s;
  if (a && b) wt(0);
  if (a && !b) wt(1);
  if (!a && b) wt(2);
  if (!a && !b) wt(3);
}
