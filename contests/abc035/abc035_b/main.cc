#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  int x = 0, y = 0;
  int q = 0;
  for (char c : s) {
    if (c == 'L') --x;
    if (c == 'R') ++x;
    if (c == 'U') ++y;
    if (c == 'D') --y;
    if (c == '?') ++q;
  }
  int dist = abs(x) + abs(y);
  rd(int, t);
  if (t == 1) {
    wt(dist + q);
  } else if (dist >= q) {
    wt(dist - q);
  } else {
    wt((q - dist) % 2);
  }
}
