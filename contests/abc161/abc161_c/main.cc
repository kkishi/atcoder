#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, K);
  N %= K;
  wt(min(abs(N - K), N));
}
