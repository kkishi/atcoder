#include <bits/stdc++.h>

#include "disjoint_set.h"
#include "macros.h"

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  DisjointSet ds(N);
  vector<set<int>> friends(N);
  vector<set<int>> blocks(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    friends[a].insert(b);
    friends[b].insert(a);
    ds.Union(a, b);
    dbg(a, b, ds.Find(a), ds.Find(b), ds.Size(a), ds.Size(b));
  }
  rep(i, K) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    blocks[a].insert(b);
    blocks[b].insert(a);
  }

  rep(i, N) {
    int cnt = ds.Size(i) - 1 - friends[i].size();
    FOR(b, blocks[i]) if (ds.Same(b, i))-- cnt;
    if (i) cout << " ";
    cout << cnt;
  }
  cout << endl;
}
