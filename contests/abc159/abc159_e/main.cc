#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

const int INF = 10 * 1000 * 1000;
int H, W, K;
int S[10][1000];
int tot[10][1000];

vector<vector<int>> cal(const vector<string>& s) {
  vector<vector<int>> tot(H + 1, vector<int>(W + 1));
  rep(i, H) rep(j, W) {
    tot[i + 1][j + 1] =
        tot[i][j + 1] + tot[i + 1][j] - tot[i][j] + (s[i][j] == '1');
  }

  rep(i, H) {
    rep(j, W) cout << tot[i + 1][j + 1] << " ";
    cout << endl;
  }
  cout << endl;

  vector<vector<int>> dp(H + 1, vector<int>(W + 1));
  rep(i, H) rep(j, W) {
    int ans = INF;
    if (tot[i + 1][j + 1] <= K) {
      ans = 0;
    }
    cout << i << " " << j << " " << ans << endl;
    // horizontal
    rep(i2, i) if (tot[i + 1][j + 1] - tot[i2 + 1][j + 1] <= K) {
      ans = min(ans, dp[i2 + 1][j + 1] + 1);
      cout << i2 << " " << ans << " " << tot[i2 + 1][j + 1] << " "
           << dp[i2 + 1][j + 1] << endl;
      cout << " " << tot[i + 1][j + 1] << " " << tot[i2 + 1][j + 1] << endl;
    }
    // diagonal
    rep(j2, j) if (tot[i + 1][j + 1] - tot[i + 1][j2 + 1] <= K) {
      ans = min(ans, dp[i + 1][j2 + 1] + 1);
    }
    dp[i + 1][j + 1] = ans;
  }
  return dp;
}

vector<string> flipw(const vector<string>& s) {
  vector<string> t(s);
  rep(i, H) rep(j, W) t[i][W - 1 - j] = s[i][j];
  return t;
}

vector<string> fliph(const vector<string>& s) {
  vector<string> t(s);
  rep(i, H) rep(j, W) t[H - 1 - i][j] = s[i][j];
  return t;
}

int main() {
  cin >> H >> W >> K;
  vector<string> S(H);
  rep(i, H) cin >> S[i];
  /*
  auto v2 = flipw(S);
  rep(i, H) cout << v2[i] << endl;

  v2 = fliph(S);
  rep(i, H) {
    cout << v2[i] << endl;
  }
  */
  vector<vector<int>> dp1 = cal(S);
  rep(i, H) {
    rep(j, W) cout << dp1[i + 1][j + 1] << " ";
    cout << endl;
  }
  cout << endl;
  vector<vector<int>> dp2 = cal(flipw(S));
  rep(i, H) {
    rep(j, W) cout << dp2[i + 1][j + 1] << " ";
    cout << endl;
  }
  cout << endl;
  vector<vector<int>> dp3 = cal(fliph(S));
  rep(i, H) {
    rep(j, W) cout << dp3[i + 1][j + 1] << " ";
    cout << endl;
  }
  cout << endl;

  int ans = dp1[H][W];
  cout << ans << endl;
  // horizontal
  rep(i, H - 1) {
    cout << i << " " << dp1[i + 1][W] << " " << dp3[H - 1 - i][W] << endl;
    ans = min(ans, dp1[i + 1][W] + dp3[H - 1 - i][W] + 1);
  }
  // diagonal
  rep(i, W - 1) {
    cout << i << " " << dp1[H][i + 1] << " " << dp2[H][W - 1 - i] << endl;
    ans = min(ans, dp1[H][i + 1] + dp2[H][W - 1 - i] + 1);
  }
  cout << ans << endl;
}
