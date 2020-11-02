#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  while (s.size() >= 2 && s.substr(0, 2) == "hi") s = s.substr(2);
  wt(s.empty());
}
