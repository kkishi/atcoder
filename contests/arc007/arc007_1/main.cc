#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(char, x);
  strings(s);
  s.erase(remove(all(s), x), s.end());
  wt(s);
}
