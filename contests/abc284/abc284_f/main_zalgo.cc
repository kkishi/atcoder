#include <bits/stdc++.h>

#include "atcoder.h"
#include "z_algorithm.h"

void Main() {
  ints(n);
  strings(t);
  string rt = t;
  reverse(rt);
  V<int> trt = ZAlgorithm(t + rt);
  V<int> rtt = ZAlgorithm(rt + t);
  //  t: ab|cba|c
  // rt: c|abc|ba
  // trt: ab|cba|c+c|abc|ba
  // rtt: c|abc|ba+ab|cba|c
  rep(i, n + 1) {
    if (trt[2 * n + (n - i)] >= i && rtt[2 * n + i] >= n - i) {
      wt(t.substr(0, i) + t.substr(i + n));
      wt(i);
      return;
    }
  }
  wt(-1);
}
