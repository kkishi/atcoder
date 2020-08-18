#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"
#include "rerooting.h"

using mint = ModInt<>;

using namespace std;

struct DP {
  int size;
  mint cnt;
  mint fact;
};

ostream& operator<<(ostream& os, const DP& dp) {
  os << "{" << dp.size << "," << dp.cnt << "," << dp.fact << "}";
  return os;
}

DP Combine(DP a, DP b) {
  return {a.size + b.size, a.cnt * b.cnt, a.fact * b.fact};
}

DP Calc(DP x) {
  return {x.size + 1, x.cnt / x.fact * mint::Fact(x.size),
          mint::Fact(x.size + 1)};
}

int main() {
  ints(N);

  vector<vector<int>> edges(N);
  rep(i, N - 1) {
    ints(a, b);
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  TreeDP<DP> tdp(edges, Combine, Calc, {0, 1, 1});
  tdp.DFS(0);
  tdp.Rerooting(0);
  rep(i, N) wt(tdp.Result()[i].cnt);
}
