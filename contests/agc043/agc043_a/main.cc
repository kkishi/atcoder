#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << #x << ": " << (x) << " (L" << __LINE__ << ")" << endl;
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

void setmin(int& a, int b) {
  if (a > b) a = b;
}

const int INF = 1000000;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> grid(H);
  REP(i, H) cin >> grid[i];

  vector<vector<int>> dp(H + 1, vector<int>(W + 1, INF));
  dp[1][1] = grid[0][0] != '.';

  int dr[] = {-1, 0};
  int dc[] = {0, -1};
  REP(r, H) REP(c, W) REP(dir, 2) {
    int pr = r + dr[dir];
    int pc = c + dc[dir];
    if (dp[pr + 1][pc + 1] == INF) continue;
    int changed = grid[r][c] != grid[pr][pc];
    setmin(dp[r + 1][c + 1], dp[pr + 1][pc + 1] + changed);
  }
  DBG(dp[H][W]);
  cout << (dp[H][W] + 1) / 2 << endl;
}
