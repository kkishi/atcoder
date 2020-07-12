#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

bool pal(const string& s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  string S;
  cin >> S;
  string a = S.substr(0, (S.size() - 1) / 2);
  string b = S.substr((S.size() + 3) / 2 - 1);
  //  cout << a << " " << b << endl;
  cout << (pal(S) && pal(a) && pal(b) ? "Yes" : "No") << endl;
}
