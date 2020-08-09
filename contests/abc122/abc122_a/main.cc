#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(char, b);
  if (b == 'A' || b == 'T') wt((char)('A' + 'T' - b));
  if (b == 'C' || b == 'G') wt((char)('C' + 'G' - b));
}
