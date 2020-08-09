#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int main() {
  rd(int, n, m, k);

  mint ans = 0;
  {
    mint x = 0;
    for (int i = 1; i <= m - 1; ++i) {
      x += i * (m - i);
    }
    ans += x * mint(n).Pow(2);
  }
  {
    mint y = 0;
    for (int i = 1; i <= n - 1; ++i) {
      y += i * (n - i);
    }
    ans += y * mint(m).Pow(2);
  }
  wt(ans * mint::Comb(m * n - 2, k - 2));
}
