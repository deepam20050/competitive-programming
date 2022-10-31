#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int N = 102;

int n, m;
string s[N];

bool check (const string &a, const string &b) {
  return a == b;
}

void test_case() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  deque < int > a;
  vector < bool > used(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (!used[j] && check(s[i], string(s[j].rbegin(), s[j].rend()))) {
        a.emplace_front(i);
        a.emplace_back(j);
        used[i] = 1;
        used[j] = 1;

        break;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!used[i] && check(s[i], string(s[i].rbegin(), s[i].rend()))) {
      auto it = a.begin() + sz(a) / 2;
      a.emplace(it, i);
      break;
    }
  }
  cout << m * sz(a) << '\n';
  for (auto &x : a) {
    cout << s[x];
  }
  cout << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}