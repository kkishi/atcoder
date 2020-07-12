#include <bits/stdc++.h>

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  SegmentTree(int size, Operation operation, T identity = T())
      : operation_(operation), identity_(identity) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
  }
  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = operation_(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      if (begin <= cbegin && cend <= end) {
        return v_[index];
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(rec(cbegin, cmid, index * 2 + 1),
                        rec(cmid, cend, index * 2 + 2));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

 private:
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
};

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

map<pair<ll, ll>, ll> cache;

ll Aggregate(const vector<ll>& p, const SegmentTree<ll>& tree, ll begin, ll end) {
  if (end == begin) return 0;
  if (end - begin == 1) return p[begin];
  if (end - begin == 2) return max(p[begin], p[begin + 1]);
  pair<ll, ll> k = {begin, end};
  ll& v = cache[k];
  if (v == 0) {
    v = tree.Aggregate(begin, end);
    dbg("not cached");
  } else {
    dbg("cached");
  }
  return v;
}

ll rec(ll begin, ll end, ll maximum, const vector<ll>& p, const SegmentTree<ll>& tree, map<ll, ll>& index) {
  if (end - begin < 2) return 0;
  if (maximum == 0) maximum = Aggregate(p, tree, begin, end);
  ll maximum_i = index[maximum];
  ll second_maximum = max(Aggregate(p, tree, begin, maximum_i),
                          Aggregate(p, tree, maximum_i + 1, end));
  ll second_maximum_i = index[second_maximum];
  ll left = min(maximum_i, second_maximum_i);
  ll right = max(maximum_i, second_maximum_i);
  dbg(begin, end, maximum, second_maximum);
  dbg(begin, end, left, right);
  return (left - begin + 1) * (end - right) * second_maximum +
      rec(begin, right, (left == maximum_i ? maximum : second_maximum), p, tree, index) +
      rec(left + 1, end, (right == maximum_i ? maximum  : second_maximum), p, tree, index) -
      rec(left + 1, right, 0, p, tree, index);
}

int main() {
  in(ll, n);
  SegmentTree<ll> tree(n, [](ll a, ll b) { return max(a, b); });
  map<ll, ll> index;
  vector<ll> p(n);
  rep(i, n) {
    cin >> p[i];
    tree.Set(i, p[i]);
    index[p[i]] = i;
  }
  out(rec(0, n, n, p, tree, index));
}
