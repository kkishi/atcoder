#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, r, d, x);
  rep(y, 10) {
    x = x * r - d;
    wt(x);
  }
}
