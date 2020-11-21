#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  Random r;
  wt(r.Int(2, 10));
  rep(4) wt((char)('A' + r.Int(0, 1)));
}
