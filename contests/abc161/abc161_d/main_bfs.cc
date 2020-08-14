#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int K;
  cin >> K;

  queue<string> que;
  for (int i = 1; i <= 9; ++i) {
    string s = "0";
    s[0] += i;
    que.push(s);
  }
  for (int i = 0; i < K; ++i) {
    string here = que.front();
    if (i == K - 1) {
      cout << here << endl;
      break;
    }
    que.pop();
    int x = here.back() - '0';
    for (int i = x - 1; i <= x + 1; ++i) {
      if (i < 0 || 10 <= i) {
        continue;
      }
      que.push(here + (char)('0' + i));
    }
  }
}
