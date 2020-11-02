#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, A, B);
  wt(N / (A + B) * A + min(N % (A + B), A));
}
