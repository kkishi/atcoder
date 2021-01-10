#include <bits/stdc++.h>

#include <atcoder/modint>

#include "atcoder.h"

using namespace atcoder;

using mint = modint;

void Main() {
  ints(n, m);
  mint::set_mod(m * m);
  wt(mint(10).pow(n).val() / m);
}
