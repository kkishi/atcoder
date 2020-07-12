#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

const int INF = 10 * 1000 * 1000;
int H, W, K;
int S[10][1000];
int tot[10][1000];

int dfs(int h, vector<int>& assignments, const vector<vector<int>>& tot) {
  if (h == H) {
    int prev = -1;
    int cuts = 0;
    // cout << "assignments: ";
    // for (auto x : assignments) cout << x << " "; cout << endl;
    // return 0;
    for (int w = 0; w < W; ++w) {
      bool need_cut = false;
      for (int ai = 0; ai < assignments.size(); ++ai) {
        auto cnt = [&tot](int hh, int hw, int lh, int lw) {
          return tot[hh][hw] - tot[lh][hw] - tot[hh][lw] + tot[lh][lw];
        };
        int lh = (ai == 0 ? 0 : assignments[ai - 1]);
        int hh = assignments[ai];
        int before = cnt(hh, w, lh, prev);
        int after = cnt(hh, w + 1, lh, prev);
        // cout << "w:" << w << " ai:" << ai << " lh" << lh << " hh" << hh << "
        // before" << before << " after" << after << endl;
        if (after - before > K) return INF;
        if (after > K) need_cut = true;
      }
      // cout << need_cut << endl;
      if (need_cut) {
        ++cuts;
        prev = w;
      }
    }
    // cout << "cuts:" << cuts << endl;
    return cuts + assignments.size() - 1;
  }
  int ans = INF;
  for (++h; h <= H; ++h) {
    assignments.push_back(h);
    ans = min(ans, dfs(h, assignments, tot));
    assignments.pop_back();
  }
  return ans;
}

vector<vector<int>> cal(const vector<string>& s) {
  vector<vector<int>> tot(H + 1, vector<int>(W + 1));
  REP(i, H) REP(j, W) {
    tot[i + 1][j + 1] =
        tot[i][j + 1] + tot[i + 1][j] - tot[i][j] + (s[i][j] == '1');
  }
  return tot;
}

int main() {
  cin >> H >> W >> K;
  vector<string> S(H);
  REP(i, H) cin >> S[i];

  vector<int> v;
  cout << dfs(0, v, cal(S)) << endl;
}
