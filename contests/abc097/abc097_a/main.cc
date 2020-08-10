#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  rd(int, a, b, c, d);
  auto close = [&d](int a, int b) { return abs(a - b) <= d; };
  wt((close(a, c) || (close(a, b) && close(b, c))) ? "Yes" : "No");
}
