// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

string s, t, ansl, ansr;
deque < char > oleg, igor;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> t;
  int n = sz(s);
  sort(all(s));
  sort(all(t));
  reverse(all(t));
  FOR(i, 0, n + 1 >> 1) {
    oleg.eb(s[i]);
  }
  FOR(i, 0, n >> 1) {
    igor.eb(t[i]);
  }
  FOR(i, 0, n) {
    bool mode = 0;
    if (i & 1) {
      if (!oleg.empty() && oleg[0] >= igor[0]) mode = 1;
      if (mode) {
        ansr += igor.back();
        igor.pop_back();
      } else {
        ansl += igor[0];
        igor.pop_front();
      }
    } else {
      if (!igor.empty() && oleg[0] >= igor[0]) mode = 1;
      if (mode) {
        ansr += oleg.back();
        oleg.pop_back();
      } else {
        ansl += oleg[0];
        oleg.pop_front();
      }
    }
  }
  reverse(all(ansr));
  ansl += ansr;
  cout << ansl << '\n';
  return 0;
}
