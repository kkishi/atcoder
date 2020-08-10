#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

ll digits(ll x) { return x == 0 ? 0 : 1 + digits(x / 10); }

int main() {
  rd(ll, a, b, x);
  wt(BinarySearch<ll>(0, 1000000001,
                      [&](ll y) { return a * y + b * digits(y) <= x; }));
}
