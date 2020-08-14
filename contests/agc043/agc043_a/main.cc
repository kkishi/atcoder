#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const int INF = 1000000;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> grid(H);
  cin >> grid;

  vector<vector<int>> dp(H + 1, vector<int>(W + 1, INF));
  dp[1][1] = grid[0][0] != '.';

  int dr[] = {-1, 0};
  int dc[] = {0, -1};
  rep(r, H) rep(c, W) rep(dir, 2) {
    int pr = r + dr[dir];
    int pc = c + dc[dir];
    if (dp[pr + 1][pc + 1] == INF) continue;
    int changed = grid[r][c] != grid[pr][pc];
    chmin(dp[r + 1][c + 1], dp[pr + 1][pc + 1] + changed);
  }
  dbg(dp[H][W]);
  cout << (dp[H][W] + 1) / 2 << endl;
}
