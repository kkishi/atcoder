#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const int kMaxCache = 1 << 11;
const int kMaxL = int(1e5);
int V_[1 << 18];
int W[1 << 18];
int dp[kMaxCache][kMaxL + 1];

int Parent(int node) { return (node - 1) / 2; }

int main() {
  rd(int, n);
  rep(i, n) cin >> V_[i] >> W[i];

  for (int i = W[0]; i <= kMaxL; ++i) dp[0][i] = V_[0];
  for (int node = 1; node < min(kMaxCache, n); ++node) {
    int parent = Parent(node);
    for (int i = 0; i <= kMaxL; ++i) dp[node][i] = dp[parent][i];
    for (int i = kMaxL; i - W[node] >= 0; --i) {
      chmax(dp[node][i], dp[parent][i - W[node]] + V_[node]);
    }
  }

  rd(int, q);
  rep(i, q) {
    rd(int, v, l);
    --v;

    if (v < kMaxCache) {
      wt(dp[v][l]);
    } else {
      vector<int> vs, ws;
      while (v >= kMaxCache) {
        vs.push_back(V_[v]);
        ws.push_back(W[v]);
        v = Parent(v);
      }
      int ans = 0;
      rep(i, 1 << vs.size()) {
        int v_sum = 0;
        int w_sum = 0;
        rep(j, vs.size()) if ((i >> j) & 1) {
          v_sum += vs[j];
          w_sum += ws[j];
        }
        if (w_sum <= l) {
          chmax(ans, v_sum + dp[v][l - w_sum]);
        }
      }
      wt(ans);
    }
  }
}
