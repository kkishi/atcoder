#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b, c, d);
  int sign = a + b - (c + d);
  wt(sign > 0 ? "Left" : sign == 0 ? "Balanced" : "Right");
}
