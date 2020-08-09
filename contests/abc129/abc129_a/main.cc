#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, p, q, r);
  wt(p + q + r - max({p, q, r}));
}
