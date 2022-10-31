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

const int N = 3e5 + 5;

int n;
char s[N];
vector < int > v[2];

int main () {
  scanf("%d", &n);
  scanf("%s", s + 1);
  FOR(i, 1, n + 1) {
    v[s[i] - 'A'].eb(i);
  }
  lli ans = 0;
  FOR(i, 1, n + 1) {
    int j = (s[i] - 'A') ^ 1;
    auto it = lower_bound(all(v[j]), i);
    int add = 0;
    if (it == v[j].end()) {
      add += n - i;
    } else {
      int idx = *it;
      add += idx - 1 - i;
      auto curr = lower_bound(all(v[j ^ 1]), i + 1);
      if (curr != v[j ^ 1].end()) {
        if (*curr == i + 1) {
          ans += n - idx;
        } else {
          ans += n - *curr + 1;
        }
      }
    }
    ans += add;
  }
  printf("%lld\n", ans);
  return 0;
}
