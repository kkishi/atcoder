#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b);
  if (a > b) swap(a, b);
  wt(string(b, '0' + a));
}
