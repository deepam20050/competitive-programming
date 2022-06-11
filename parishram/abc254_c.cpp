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

typedef long long lli;
typedef pair < int, int > pii;

const int N = 2e5 + 5;

int a[N];
int n, k;
bool used[N];

void test_case() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      vector < int > v;
      for (int j = i; j <= n; j += k) {
        v.emplace_back(a[j]);
      }
      sort(all(v));
      for (int j = i, z = 0; j <= n; j += k) {
        a[j] = v[z++];
        used[j] = 1;
      }
    }
  }
  is_sorted(a + 1, a + n + 1) ? cout << "Yes\n" : cout << "No\n";
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