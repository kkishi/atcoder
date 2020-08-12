#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << (mint(2).Pow(n) - 1 - mint::CombSlow(n, a) - mint::CombSlow(n, b))
       << endl;
}
