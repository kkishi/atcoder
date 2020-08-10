#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int n, u, v;

int main() {
  cin >> n >> u >> v;
  vector<vector<int>> edges(n);
  rep(i, n - 1) {
    rd(int, a, b);
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  map<int, int> aoki;
  aoki[v - 1] = 0;
  queue<int> que;
  que.push(v - 1);

  while (!que.empty()) {
    int here = que.front();
    que.pop();
    // dbg(here, aoki[here]);
    for (int there : edges[here]) {
      if (aoki.count(there)) continue;
      aoki[there] = aoki[here] + 1;
      que.push(there);
    }
  }

  map<int, int> takahashi;
  takahashi[u - 1] = 0;
  que.push(u - 1);

  int maxi = -1;
  while (!que.empty()) {
    int here = que.front();
    que.pop();
    maxi = max(maxi, aoki[here]);
    // dbg(here, takahashi[here]);
    for (int there : edges[here]) {
      if (takahashi.count(there)) continue;
      if (aoki[there] <= takahashi[here] + 1) continue;
      takahashi[there] = takahashi[here] + 1;
      que.push(there);
      maxi = max(maxi, aoki[there]);
    }
  }
  dbg(maxi);
  if (maxi == -1) {
    if (aoki[u - 1] == 1) {
      wt(0);
    } else {
      wt(1);
    }
  } else {
    wt(maxi - 1);
  }
}
