#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(r, g, b);
  wt((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO");
}
