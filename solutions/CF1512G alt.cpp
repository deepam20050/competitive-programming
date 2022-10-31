#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e7 + 5;

lli s[N];
int ans[N];

void init () {
  FOR(i, 1, N) {
    ans[i] = -1;
    for (int j = i; j < N; j += i) {
      s[j] += i;
    }
  }
  ans[1] = 1;
  FOR(i, 1, N) {
    if (s[i] < N * 1ll && ans[s[i]] == -1) {
      ans[s[i]] = i;
    }
  }
}

int main () {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int c;
    scanf("%d", &c);
    printf("%d\n", ans[c]);
  }
  return 0;
}
