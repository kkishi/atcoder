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

const ll kMods[] = {
  1000000007,
  1000992299,
  999119999,
};

struct Hash {
  ll hash[3];
  void Add(char c) {
    rep(i, 3) {
      hash[i] = (hash[i] * 26 + c - 'a') % kMods[i];
    }
  }
  bool operator<(const Hash& h) const {
    rep(i, 3) if (hash[i] != h.hash[i]) return hash[i] < h.hash[i];
    return false;
  }
  bool operator==(const Hash& h) const {
    rep(i, 3) if (hash[i] != h.hash[i]) return false;
    return true;
  }
};

Hash hashes[5000];

int main() {
  in(int, n);
  in(string, s);
  rep(i, n) hashes[i].Add(s[i]);
  int ans = 0;
  for (int length = 2; length <= n / 2; ++length) {
    set<Hash> seen;
    for (int i = 0; i + length - 1 < n; ++i) {
      hashes[i].Add(s[i + length - 1]);
      if (ans == length) continue;
      if (i - length >= 0) {
        seen.insert(hashes[i - length]);
      }
      if (seen.count(hashes[i])) {
        ans = length;
      }
    }
  }
  out(ans);
}
