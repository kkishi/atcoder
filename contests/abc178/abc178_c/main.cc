#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  wt(mint(10).Pow(n) - mint(9).Pow(n) - mint(9).Pow(n) + mint(8).Pow(n));
}
