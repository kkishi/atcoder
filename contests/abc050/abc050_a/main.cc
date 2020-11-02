#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int a, b;
  char op;
  cin >> a >> op >> b;
  wt(a + (op == '+' ? b : -b));
}
