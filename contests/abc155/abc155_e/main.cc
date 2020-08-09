#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll dp[1000001][2];

int main() {
  string N;
  cin >> N;

  dp[0][0] = 0;
  dp[0][1] = 1;
  rep(i, N.size()) {
    int digit = N[i] - '0';
    dp[i + 1][0] =
        min({dp[i][0] + digit, dp[i][1] + (10 - digit), dp[i][1] + 1 + digit});
    dp[i + 1][1] = min(dp[i][0] + 1 + (9 - digit), dp[i][1] + (9 - digit));
    /*
    if (digit == 0) {
      dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 1);
    }
    */
    dbg(i, N[i], dp[i + 1][0], dp[i + 1][1]);
  }
  cout << min(dp[N.size()][0], dp[N.size()][1] + 1) << endl;
}
