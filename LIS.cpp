//参考　https://qiita.com/drken/items/68b8503ad4ffb469624c
#include <bits/stdc++.h>
using namespace std;

// このまま提出しても動く
#include "atcoder/all"
using namespace atcoder;
using mint = static_modint<998244353>; // mod指定を変えるのはここ

#define INF 1000000000000
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl;
#define show(x) cout << #x << ": " << x << endl;
#define fi first
#define se second

typedef long long ll;

using Pi = pair<int, int>;
using Pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<ll>;


ll LIS(const vector<ll> &A) {
  ll N = (ll)A.size();

  const ll inf = (1LL << 60);
  vector<ll> dp(N + 1, inf);

  for(int j = 0; j <= N; j++) {
    if(j == 1)
      dp[j] = A[0];
    if(j == 0)
      dp[j] = -inf;
  }

  for(int i = 1; i <= N - 1; i++) {
    ll a = A[i];
    auto itr = lower_bound(all(dp), a);
    *itr = A[i];
  }

  ll ans = 0;

  for(int j = 0; j <= N; j++) {
    if(dp[j] == inf)
      continue;
    ans = j;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  
  print(LIS(A))
  return 0;
}
