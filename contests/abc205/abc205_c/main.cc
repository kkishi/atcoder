#include <bits/stdc++.h>

#include "atcoder.h"

char Solve(int a, int b, int c) {
  if (a == 0 && b == 0) return '=';
  bool an = (a < 0) && !even(c);
  bool bn = (b < 0) && !even(c);
  if (an && bn) {
    return Solve(-b, -a, c);
  }
  if (an && !bn) {
    return '<';
  }
  if (!an && bn) {
    return '>';
  }
  a = abs(a);
  b = abs(b);
  if (a == b) {
    assert(a > 0 && b > 0);
    return '=';
  }
  if (a < b) return '<';
  return '>';
}

void Main() {
  ints(a, b, c);
  wt(Solve(a, b, c));
}
