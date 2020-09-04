#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(w, a, b);
  if (a + w < b) {
    wt(b - (a + w));
  } else if (b + w < a) {
    wt(a - (b + w));
  } else {
    wt(0);
  }
}
