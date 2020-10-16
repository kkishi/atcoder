#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(char, b);
  if (b == 'A' || b == 'T') wt((char)('A' + 'T' - b));
  if (b == 'C' || b == 'G') wt((char)('C' + 'G' - b));
}
