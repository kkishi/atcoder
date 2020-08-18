#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b, c, d);
  auto close = [&d](int a, int b) { return abs(a - b) <= d; };
  wt(close(a, c) || (close(a, b) && close(b, c)));
}
