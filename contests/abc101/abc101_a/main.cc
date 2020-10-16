#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  wt(count(all(s), '+') - count(all(s), '-'));
}
