#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  int x = 1900 * m + 100 * (n - m);
  long double p = pow(0.5, m);
  long double e = 0;
  for (int i = 0; i < 1000000; ++i) {
    e += pow((1 - p), i) * p * (x * (i + 1));
  }
  wt(int(e + 1e-6));
}
