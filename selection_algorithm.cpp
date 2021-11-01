/*
https://hkashima.github.io/algorithm2021_5.pdf
最悪計算量O(N)の順序統計量アルゴリズム
選んできた中央値と同じ値がいっぱいあって再起呼び出しに渡す配列のサイズが上手く定数倍でおさえられないケースがあるのでpartitionにおいて３グループに分ける必要がある。

この実装で計算量O(N)になってるかはちょっとわからん。
一応テスト回してみると
10**8　66s
10**7 10s 5s 5s 6s ...
10**6 1s 0s 1s 1s 1s 1s 0s
*/
#include <bits/stdc++.h>
using namespace std;



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

template <typename T> bool chmax(T &a, const T &b) {
  if(a < b) {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T> bool chmin(T &a, const T &b) {
  if(a > b) {
    a = b; // aをbで更新
    return true;
  }
  return false;
}

const ll inf = (1LL << 60);

Pll partition(vector<ll> &A, ll pivot) {
  vector<ll> small; // pivot未満
  vector<ll> big;   // pivot超過
  vector<ll> same;

  for(auto a : A) {
    if(a < pivot)
      small.push_back(a);
    else if(a == pivot)
      same.push_back(a);
    else
      big.push_back(a);
  }

  ll size_small = small.size();
  ll size_same = same.size();

  for(int i = 0; i < A.size(); i++) {
    if(i < size_small)
      A[i] = small[i];
    else if(i < size_small + size_same)
      A[i] = same[i - size_small];
    else
      A[i] = big[i - size_small - size_same];
  }

  return Pll(size_small, size_same);
}

ll order(vector<ll> &A, ll k) { 
  // k 0-indexed
  /*
  show(k)
  for(auto a:A) cout<<a<<" ";
  cout<<endl;
  */

  assert(A.size() != 0);

  if(A.size() == 1) {
    sort(all(A));
    return A[k];
  }

  ll N = A.size();

  vector<ll> T;
  for(int i = 0; i < N; i += 5) {
    vector<ll> vec5;
    for(int j = 0; j < 5 and i + j < N; j++)
      vec5.push_back(A[i + j]);
    /*
    for(auto v : vec5) cout<<v<<" ";
    cout<<endl;
    */
    sort(all(vec5));
    T.push_back(vec5[vec5.size() / 2]);
  }

  ll m = order(T, T.size() / 2);
  // show(m)
  Pll result = partition(A, m);
  ll size_small = result.first;
  ll size_same = result.second;
  /*
  show(size_small)
  show(size_same)
  */

  if(k < size_small) {
    vector<ll> B;
    for(int i = 0; i < size_small; i++) {
      B.push_back(A[i]);
    }

    return order(B, k);
  } else if(k < size_small + size_same) {
    return A[k];
  } else {
    vector<ll> B;
    for(int i = size_small + size_same; i < N; i++) {
      B.push_back(A[i]);
    }

    return order(B, k - size_small - size_same);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::cout << std::fixed
            << std::setprecision(10); //小数を出力するときだけ小数点以下10桁

  ll N;
  cin >> N;

  vector<ll> A(N);

  REP(i, N) cin >> A[i];
  auto B = A;
  auto C = A;

  ll k;
  cin >> k;

  // 0-indexed
  k--;

  cout << order(A, k) << endl;

  // test
  /*

  sort(all(B));

  

  for(int i = 0; i < N; i++) {
    auto D = C;
    assert(order(D, i) == B[i]);
  }
  */
  

  return 0;
}

//testcase
/*

/*

make testcases automatically

https://betrue12.hateblo.jp/entry/2019/09/07/171628

example
int main(){
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    uniform_int_distribution<int> dist_N(4, 10), dist_A(1, 20);　//distribution
    int N = dist_N(rnd);
    vector<int> A(N);
    for(int i=0; i<N; i++) A[i] = dist_A(rnd);

    cout << N << endl;
    for(int i=0; i<N; i++) cout << A[i] << " \n"[i==N-1];
    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

//#include <atcoder/all>
//using namespace atcoder;

#define INF 100000000000
#define MOD 1000000007
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl;
#define show(x) cout << #x << ": " << x << endl;

typedef long long ll;

using Pi = pair<int, int>;
using Pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<ll>;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  std::cout<<std::fixed<<std::setprecision(10); //小数を出力するときだけ小数点以下10桁

  random_device seed_gen;
  mt19937_64 rnd(seed_gen());

  uniform_int_distribution<int> dist_N(1000000,1000000),dist_a(-90,90);
 

  string S;

  ll N = dist_N(rnd);
  uniform_int_distribution<int> dist_k(1, N); // dist_a(-999, 999);
  print(N)
  REP(i,N){
  
    cout<<dist_a(rnd)<<" ";
  }
  cout<<endl;


  print(dist_k(rnd))


  return 0;
}
*/
