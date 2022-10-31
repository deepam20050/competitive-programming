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
using pss = pair < string, string >;

pss decrypt (string s) {
  reverse(all(s));
  vector < int > cnt(26);
  string order = "";
  for (auto &ch : s) {
    if (!cnt[ch - 'a']) {
      order += ch;
    }
    ++cnt[ch - 'a'];
  }
  int m = sz(order);
  int len_s = 0;
  FOR(i, 0, m) {
    len_s += cnt[order[i] - 'a'] / (m - i);
  }
  reverse(all(order));
  return mp(string(s.rbegin(), s.rbegin() + len_s), order);
}

string make_t (pss x) {
  string res = x.F;
  for (auto ch : x.S) {
    string tmp = "";
    for (auto c : x.F) {
      if (c != ch) {
        res += c;
        tmp += c;
      }
    }
    x.F = tmp;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    auto ans1 = decrypt(s);
    auto ans2 = make_t(ans1);
    if (ans2 == s) {
      cout << ans1.F << " " << ans1.S << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
