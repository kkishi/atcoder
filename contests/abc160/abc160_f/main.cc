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
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

template <int Mod>
class ModInt {
 public:
  ModInt() : n_(0) {}
  ModInt(long long n) : n_(n % Mod) {
    if (n_ < 0) {
      // In C++, (-n)%m == -(n%m).
      n_ += Mod;
    }
  }
  ModInt& operator+=(const ModInt& m) {
    n_ += m.n_;
    if (n_ >= Mod) {
      n_ -= Mod;
    }
    return *this;
  }
  ModInt& operator++() { return (*this) += 1; }
  ModInt& operator-=(const ModInt& m) {
    n_ -= m.n_;
    if (n_ < 0) {
      n_ += Mod;
    }
    return *this;
  }
  ModInt& operator--() { return (*this) -= 1; }
  ModInt& operator*=(const ModInt& m) {
    n_ *= m.n_;
    n_ %= Mod;
    return *this;
  }
  ModInt& operator/=(const ModInt& m) {
    *this *= m.inverse();
    return *this;
  }
#define DEFINE_BINARY_OPERATOR(op) \
  ModInt operator op(const ModInt& m) const { return ModInt(*this) op##= m; }
  DEFINE_BINARY_OPERATOR(+)
  DEFINE_BINARY_OPERATOR(-)
  DEFINE_BINARY_OPERATOR(*)
  DEFINE_BINARY_OPERATOR(/)
#undef DEFINE_BINARY_OPERATOR
#define DEFINE_COMPARISON_OPERATOR(op) \
  bool operator op(const ModInt& m) const { return n_ op m.n_; }
  DEFINE_COMPARISON_OPERATOR(!=)
  DEFINE_COMPARISON_OPERATOR(<)
  DEFINE_COMPARISON_OPERATOR(<=)
  DEFINE_COMPARISON_OPERATOR(==)
  DEFINE_COMPARISON_OPERATOR(>)
  DEFINE_COMPARISON_OPERATOR(>=)
#undef BDEFINE_COMPARISON_OPERATOR
  ModInt pow(int n) const {
    // a * b ^ n = answer.
    ModInt a = 1, b = *this;
    while (n != 0) {
      if (n & 1) {
        a *= b;
      }
      n /= 2;
      b *= b;
    }
    return a;
  }
  ModInt inverse() const {
    // Compute the inverse based on Fermat's little theorem. Note that this only
    // works when n_ and Mod are relatively prime. The theorem says that
    // n_^(Mod-1) = 1 (mod Mod). So we can compute n_^(Mod-2).
    return pow(Mod - 2);
  }
  long long value() const { return n_; }

  static ModInt factorial(int n) {
    for (int i = factorial_.size(); i <= n; ++i) {
      factorial_.push_back(i == 0 ? 1 : factorial_.back() * i);
    }
    return factorial_[n];
  }
  static ModInt combination(int n, int k) {
#if DEBUG
    assert(n <= 1000000 && "n is too large. If k is small, consider using combination_slow.");
#endif
    return factorial(n) / factorial(n - k) / factorial(k);
  }
  static ModInt combination_slow(int n, int k) {
    ModInt numerator = 1;
    for (int i = 0; i < k; ++i) {
      numerator *= (n - i);
    }
    return numerator / factorial(k);
  }

 private:
  long long n_;
  static std::vector<ModInt> factorial_;
};

template<int Mod>
std::vector<ModInt<Mod>> ModInt<Mod>::factorial_;

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}

template <typename T, T Op1(T, T), T Op2(T)>
class TreeDP {
 public:
  TreeDP(const std::vector<std::vector<int>>& edges) : edges_(edges) {
    parent_edge_.resize(edges.size());
    dp_.resize(edges.size());
    for (std::size_t i = 0; i < edges.size(); ++i) {
      dp_[i].resize(edges[i].size());
    }
    result_.resize(edges.size());
  }

  // TODO: Pass this via a constructor.
  void SetUnit(const T& unit) { unit_ = unit; }

  T DFS(int node, std::optional<int> parent) {
    T t = unit_;
    for (std::size_t i = 0; i < edges_[node].size(); ++i) {
      int child = edges_[node][i];
      if (parent && child == *parent) {
        parent_edge_[child] = i;
        continue;
      }
      t = Op1(t, dp_[node][i] = DFS(child, node));
    }
    return Op2(t);
  }

  void Rerooting(int node, std::optional<std::pair<int, T>> parent) {
    std::vector<T>& dp = dp_[node];
    if (parent) {
      dp[parent_edge_[node]] = parent->second;
    }
    const std::vector<int> edges = edges_[node];

    // lower[i] = Op1(dp[i - 1], Op1(dp[i - 2], ...))
    std::vector<T> lower(edges.size() + 1);
    lower[0] = unit_;
    for (std::size_t i = 0; i < edges.size(); ++i) {
      lower[i + 1] = Op1(lower[i], dp[i]);
    }

    // higher[i] = Op1(dp[i], Op1(dp[i + 1], ...))
    std::vector<T> higher(edges.size() + 1);
    higher[edges.size()] = unit_;
    for (int i = edges.size() - 1; i >= 0; --i) {
      higher[i] = Op1(higher[i + 1], dp[i]);
    }

    result_[node] = Op2(higher[0]);

    for (std::size_t i = 0; i < edges.size(); ++i) {
      int child = edges[i];
      if (parent && child == parent->first) {
        continue;
      }
      Rerooting(child, {{node, Op2(Op1(lower[i], higher[i + 1]))}});
    }
  }

  const std::vector<std::vector<T>>& DP() const { return dp_; }
  const std::vector<T>& Result() const { return result_; }

 private:
  T unit_ = T();
  std::vector<std::vector<int>> edges_;
  std::vector<int> parent_edge_;
  std::vector<std::vector<T>> dp_;
  std::vector<T> result_;
};

using mint = ModInt<1000000000+7>;

struct DP {
  int size;
  mint cnt;
  mint fact;
};

ostream& operator<<(ostream& os, const DP& dp) {
  os << "{" << dp.size << "," << dp.cnt << "," << dp.fact << "}";
  return os;
}

DP Combine(DP a, DP b) {
  return {a.size + b.size, a.cnt * b.cnt, a.fact * b.fact};
}

DP Calc(DP x) {
  return {x.size + 1, x.cnt / x.fact * mint::factorial(x.size),
          mint::factorial(x.size + 1)};
}

int main() {
  int N;
  cin >> N;

  vector<vector<int>> edges(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  TreeDP<DP, Combine, Calc> tdp(edges);
  tdp.SetUnit({0, 1, 1});
  tdp.DFS(0, std::nullopt);
  tdp.Rerooting(0, std::nullopt);
  REP(i, N) cout << tdp.Result()[i].cnt << endl;
}
