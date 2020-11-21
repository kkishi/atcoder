#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  rd(char, aa, ab, ba, bb);
  auto one = [] { wt(1); };
  auto fib = [&] {
    mint a = 0, b = 1;
    rep(n - 2) {
      mint c = a + b;
      a = b;
      b = c;
    }
    wt(b);
  };
  auto two = [&] {
    mint x = 1;
    rep(n - 3) x *= 2;
    wt(x);
  };
  if (aa == 'A' && ab == 'A' && ba == 'A' && bb == 'A') one();
  if (aa == 'B' && ab == 'A' && ba == 'A' && bb == 'A') fib();
  if (aa == 'A' && ab == 'A' && ba == 'B' && bb == 'A') one();
  if (aa == 'B' && ab == 'A' && ba == 'B' && bb == 'A') two();
  if (aa == 'A' && ab == 'B' && ba == 'A' && bb == 'A') two();
  if (aa == 'B' && ab == 'B' && ba == 'A' && bb == 'A') two();
  if (aa == 'A' && ab == 'B' && ba == 'B' && bb == 'A') fib();
  if (aa == 'B' && ab == 'B' && ba == 'B' && bb == 'A') fib();
  if (aa == 'A' && ab == 'A' && ba == 'A' && bb == 'B') one();
  if (aa == 'B' && ab == 'A' && ba == 'A' && bb == 'B') fib();
  if (aa == 'A' && ab == 'A' && ba == 'B' && bb == 'B') one();
  if (aa == 'B' && ab == 'A' && ba == 'B' && bb == 'B') two();
  if (aa == 'A' && ab == 'B' && ba == 'A' && bb == 'B') one();
  if (aa == 'B' && ab == 'B' && ba == 'A' && bb == 'B') one();
  if (aa == 'A' && ab == 'B' && ba == 'B' && bb == 'B') one();
  if (aa == 'B' && ab == 'B' && ba == 'B' && bb == 'B') one();
}
