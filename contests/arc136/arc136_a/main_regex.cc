#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  s = regex_replace(s, regex("A"), "BB");
  s = regex_replace(s, regex("BB"), "A");
  wt(s);
}
