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

int a[N];
lli rgt[N];

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int zero = -1;
  for (int i = 1; i <= n; ++i) {
    rgt[i] = a[i] + rgt[i - 1];
    if (rgt[i] < 0) {
      cout << "No\n";
      return;
    }
    if (zero == -1 && rgt[i] == 0) {
      zero = i; 
    }
  }
  while (zero <= n && rgt[zero] == 0) {
    ++zero;
  }
  zero == n + 1 ? cout << "Yes\n" : cout << "No\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}