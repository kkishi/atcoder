#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, r);
  if (r < 1200) {
    wt("ABC");
  } else if (r < 2800) {
    wt("ARC");
  } else {
    wt("AGC");
  }
}
