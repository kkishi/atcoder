#include <bits/stdc++.h>

#include "atcoder.h"
#include "rerooting.h"

int M;
int Combine(int a, int b) { return a * b % M; }
int Calc(int x) { return (x + 1) % M; }

void Main() {
  ints(n);
  cin >> M;
  vector<vector<int>> to(n);
  rep(n - 1) {
    ints(a, b);
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  TreeDP<int> tdp(to, Combine, Calc, 1);
  tdp.DFS(0);
  tdp.Rerooting(0);
  rep(i, n) wt((tdp.Result()[i] + M - 1) % M);
}
