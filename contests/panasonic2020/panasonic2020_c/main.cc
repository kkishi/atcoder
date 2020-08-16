#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, a, b, c);
  ll d = c - (a + b);
  wt(d > 0 && 4 * a * b < d * d);
}
