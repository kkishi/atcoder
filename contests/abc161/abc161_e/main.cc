#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, K, C);
  strings(S);

  V<int> earliest;
  int d = 0;
  rep(i, K) {
    while (S[d] == 'x') ++d;
    earliest.push_back(d);
    d += C + 1;
  }

  V<int> latest;
  d = N - 1;
  rep(i, K) {
    while (S[d] == 'x') --d;
    latest.push_back(d);
    d -= C + 1;
  }

  rep(i, K) if (earliest[i] == latest[latest.size() - 1 - i])
      wt(earliest[i] + 1);
}
