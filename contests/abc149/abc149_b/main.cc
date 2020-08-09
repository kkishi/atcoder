#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, a, b, k);
  ll c = min(a, k);
  a -= c;
  k -= c;
  c = min(b, k);
  b -= c;
  k -= c;
  wt(a, b);
}
