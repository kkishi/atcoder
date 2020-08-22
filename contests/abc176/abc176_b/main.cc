#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(n);
  int sum = 0;
  rep(i, n.size()) {
    sum += n[i] - '0';
    sum %= 9;
  }
  wt(sum == 0);
}
