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
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  in(string, s, t);
  s = s + s;
  vector<ll> last(26, -1);
  vector<vector<ll>> next(s.size(), vector(26, 0LL));
  for (int i = s.size() - 1; i >= 0; --i) {
    last[s[i] - 'a'] = i;
    rep(j, 26) {
      // dbg((char)('a'+j), last[j]);
      next[i][j] = last[j] == -1 ? -1 : last[j] - i;
    }
  }
  ll ans = 0;
  ll si = 0;
  rep(i, t.size()) {
    ll n = next[si][t[i] - 'a'];
    // dbg(t[i], n);
    if (n == -1) {
      out(-1);
      return 0;
    }
    ans += n + 1;
    si = (si + n + 1) % (s.size() / 2);
    // dbg(si);
  }
  out(ans);
}
