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

const int kBits = 63;
using bs = bitset<kBits>;

bool check(vector<bs> v, bs x) {
  // rep(i, v.size()) dbg(v[i].to_string());
  int pivot = 0;
  rep(bit, kBits) {
    for (int i = pivot; i < v.size(); ++i) {
      if (!v[i][bit]) continue;
      swap(v[pivot], v[i]);
      for (int j = 0; j < v.size(); ++j) {
        if (j == pivot) continue;
        if (!v[j][bit]) continue;
        v[j] ^= v[pivot];
      }
      ++pivot;
    }
  }
  dbg(x.to_string());
  rep(i,v.size()) dbg(v[i].to_string());
  rep(i, kBits) if (x[i]) {
    bool ok = false;
    rep(j, v.size()) if (v[j][i]) {
      ok = true;
    }
    if (!ok) {
      return false;
    }
  }
  return true;
}

bool nonzero() {
  in(int, n);
  vector<bs> a(n);
  rep(i, n) {
    in(ll, ai);
    a[i] = ai;
  }
  in(string, s);
  vector<bs> v;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      v.push_back(a[i]);
    } else {
      if (!check(v, a[i])) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  in(int, t);
  while (t--) {
    out(nonzero() ? 1 : 0);
  }
}
