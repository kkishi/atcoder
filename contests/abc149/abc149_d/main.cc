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

string hand = "rsp";
map<char, ll> score;

ll Score(char t, char m) {
  if ((hand.find(t) + 1) % 3 == hand.find(m)) {
    return score[t];
  }
  return 0;
}

ll solve(const string& t) {
  vector<ll> curr(3), prev(3);
  rep(i, t.size()) {
    rep(j, 3) {
      rep(k, 3) {
        if (k != j) {
          curr[j] = max(curr[j], prev[k]);
        }
      }
      curr[j] += Score(hand[j], t[i]);
    }
    swap(curr, prev);
  }
  ll ret = 0;
  rep(i, 3) ret = max(ret, prev[i]);
  return ret;
}

int main() {
  in(ll, n, k);
  rep(i, 3) cin >> score[hand[i]];
  in(string, t);
  vector<string> ts(k);
  rep(i, t.size()) {
    ts[i % k] += t[i];
  }
  ll ans = 0;
  rep(i, k) {
    ans += solve(ts[i]);
  }
  out(ans);
}
