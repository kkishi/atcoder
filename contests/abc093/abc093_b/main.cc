#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b, k);
  for (int i = a; i <= b;) {
    wt(i);
    ++i;
    if (i > b) break;
    if (b - i < k) continue;
    if (i - a >= k) i = b - k + 1;
  }
}
