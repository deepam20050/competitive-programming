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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 2005;

int pref[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int k, n; cin >> k >> n;
  FOR(i, 1, k + 1) {
    int x; cin >> x;
    pref[i] = pref[i - 1] + x;
  }
  set < int > s1;
  FOR(i, 1, n + 1) {
    int req; cin >> req;
    set < int > s2;
    FOR(j, 1, k + 1) {
      int x = req - pref[j];
      if (i == 1 || s1.find(x) != s1.end()) {
        s2.em(x);
      }
    }
    s1 = s2;
  }
  printf("%d\n", sz(s1));
  return 0;
}