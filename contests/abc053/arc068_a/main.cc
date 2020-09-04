#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(x);
  int rem = x % 11;
  wt(x / 11 * 2 + (rem == 0 ? 0 : rem <= 6 ? 1 : 2));
}
