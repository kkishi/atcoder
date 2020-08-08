#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, w, h);
  if (w * 3 == h * 4) {
    wt("4:3");
  } else {
    wt("16:9");
  }
}
