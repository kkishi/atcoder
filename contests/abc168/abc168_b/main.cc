#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(K);
  strings(S);

  if (S.size() <= K) {
    wt(S);
  } else {
    wt(S.substr(0, K) + "...");
  }
}
