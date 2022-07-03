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

const int N = 2e5 + 5;

vector < int > pos[N];
int n;
int a[N];

void test_case() {
  cin >> n;
  for (int i = 0; i < N; ++i) {
    pos[i].emplace_back(0);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos[a[i]].emplace_back(i);
  }
  int ops = 2e9;
  int val = 0;
  for (int i = 0; i < N; ++i) {
    pos[i].emplace_back(n + 1);
    int cnt = n - (sz(pos[i]) - 2);
    if (cnt < ops) {
      ops = cnt;
      val = i;
    }
  }
  vector < tuple < int, int, int > > ans;
  for (int i = 1; i + 1 < sz(pos[val]); ++i) {
    for (int j = pos[val][i] - 1; j > pos[val][i - 1]; --j) {
      if (a[j + 1] > a[j]) {
        ans.emplace_back(1, j, j + 1);
        a[j] = val;
      } else if (a[j + 1] < a[j]) {
        ans.emplace_back(2, j, j + 1);
        a[j] = val;
      }
    }
    if (pos[val][i + 1] == n + 1) {
      for (int j = pos[val][i] + 1; j <= n; ++j) {
        if (a[j] > a[j - 1]) {
          ans.emplace_back(2, j, j - 1);
          a[j] = val;
        } else if (a[j] < a[j - 1]) {
          ans.emplace_back(1, j, j - 1);
          a[j] = val;
        }
      }
    }
  }
  cout << ops << '\n';
  for (auto &[a, b, c] : ans) {
    cout << a << " " << b << " " << c << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}