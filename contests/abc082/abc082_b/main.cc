#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  sort(all(s));
  sort(all(t));
  reverse(all(t));
  wt(s < t);
}
