// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

char s[N];
int cost[N];
lli pref[N];
vector < int > chars[26];
map < lli, int > cnt;

int main () {
  FOR(i, 0, 26) scanf("%d", cost + i);
  scanf("%s", s + 1);
  int n = (int)strlen(s + 1);
  FOR(i, 1, n + 1) {
    pref[i] = pref[i - 1] + cost[s[i] - 'a'];
    chars[s[i] - 'a'].eb(i);
  }
  lli ans = 0;
  FOR(i, 0, 26) {
    cnt.clear();
    for (auto &j : chars[i]) {
      if (cnt.find(pref[j - 1]) != cnt.end()) {
        ans += cnt[pref[j - 1]];
      }
      ++cnt[pref[j]];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
