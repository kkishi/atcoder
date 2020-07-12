#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define DBG(...)                \
  cerr << #__VA_ARGS__ << ": "; \
  debug(__VA_ARGS__);           \
  cerr << " (L" << __LINE__ << ")" << endl
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  bool flipped = false;
  deque<char> que(ALL(S));
  REP(q, Q) {
    int T;
    cin >> T;
    if (T == 1) {
      flipped = !flipped;
      continue;
    }
    int F;
    char C;
    cin >> F >> C;
    if ((F == 1) ^ flipped) {
      que.push_front(C);
    } else {
      que.push_back(C);
    }
  }
  string s(ALL(que));
  if (flipped) {
    reverse(ALL(s));
  }
  cout << s << endl;
}
