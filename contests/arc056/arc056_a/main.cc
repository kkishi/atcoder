#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b, k, l);
  wt(min(k * a, k / l * b + min(k % l * a, b)));
}
