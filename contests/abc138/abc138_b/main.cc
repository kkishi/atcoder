#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  double sum = 0;
  rep(i, n) {
    rd(double, a);
    sum += 1 / a;
  }
  cout << setprecision(20);
  wt(1 / sum);
}
