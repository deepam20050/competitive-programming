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

void solve () {
  string s;
  cin >> s;
  vector < int > cnt(26);
  string t = "";
  int uniq = 0;
  for (auto &ch : s) ++cnt[ch - 'a'];
  FOR(i, 0, 26) {
    if (cnt[i] > 0) {
      t += i + 'a';
      ++uniq;
    }
  }
  if (uniq == 1) {
    cout << s << '\n';
    return;
  }
  if (uniq == 2) {
    if (abs(t[1] - t[0]) == 1) {
      cout << "No answer\n";
    } else {
      cout << s << '\n';
    }
    return;
  }
  if (uniq == 3) {
    do {
      if (abs(t[0] - t[1]) != 1 && abs(t[1] - t[2]) != 1) {
        FOR(i, 0, 3) cout << string(cnt[t[i] - 'a'], t[i]);
        cout << '\n';
        return;
      }
    } while (next_permutation(all(t)));
    cout << "No answer\n";
    return;
  }
  deque < int > ans = {2, 0, 3, 1};
  FOR(i, 4, uniq) {
    if (i & 1) ans.eb(i);
    else ans.emplace_front(i);
  }
  FOR(i, 0, sz(ans)) {
    cout << string(cnt[t[ans[i]] - 'a'], t[ans[i]]);
  }
  cout << '\n';
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}