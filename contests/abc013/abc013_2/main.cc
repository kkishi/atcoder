#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  wt(min({abs(a - b), abs(a - b + 10), abs(a - b - 10)}));
}
