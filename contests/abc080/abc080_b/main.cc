#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(N);
  int n = N;
  int f = 0;
  while (n) {
    f += n % 10;
    n /= 10;
  }
  wt(N % f == 0);
}
