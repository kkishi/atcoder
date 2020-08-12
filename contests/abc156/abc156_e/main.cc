#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  mint ans = 0;
  for (int holes = 0; holes <= min(n - 1, k); ++holes) {
    ans += mint::Comb(n, holes) * mint::Comb(n - 1, holes);
  }
  cout << ans << endl;
}
