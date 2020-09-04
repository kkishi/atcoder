#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(n);
  ints(t, a);
  rep(n - 1) {
    ints(ti, ai);
    int k = max((t + ti - 1) / ti, (a + ai - 1) / ai);
    t = ti * k;
    a = ai * k;
  }
  wt(t + a);
}
