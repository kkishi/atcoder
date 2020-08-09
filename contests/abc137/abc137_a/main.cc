#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b);
  wt(max({a + b, a - b, a * b}));
}
