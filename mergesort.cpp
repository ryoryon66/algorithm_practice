
// C++ (GCC9.2.1) AtCoder
/*
Ctrl+Option+N で　実行
atcoder コメントアウトはずせ

テストケースランダム生成
simple_ans.cppとtest_target.cppにぺたり
make_testcase.cppで入力生成スクリプトを書いて標準出力に出せるようにしてbash counter_example.shすると良い

*/
#include <bits/stdc++.h>
using namespace std;


#define INF 1000000000000
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl;
#define show(x) cout << #x << ": " << x << endl;
#define fi first
#define se second

typedef long long ll;

using Pi = pair<int, int>;
using Pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<ll>;

const ll inf = 1000000000000000000;

void merge_sort(ll first,ll last, vector <ll> &A){

  if(last - first == 0) return;

  ll mid = (first + last) / 2;

  merge_sort(first,mid,A);
  merge_sort(mid+1,last,A);

  vector <ll> B(last-first+1,0);

  ll idx1 = first;
  ll idx2 = mid+1;

  for(int i=0;i<last-first+1;i++){

    ll a1 = A[idx1];
    ll a2 = A[idx2];

    if(idx1 > mid) a1 = inf;
    if(idx2 > last) a2 = inf;

    if(a1 <= a2){
      B[i] = a1;
      idx1++;
    } else {
      B[i] = a2;
      idx2++;
    }
  }

  for(int i=0;i<last-first+1;i++){
    A[first + i] = B[i];
  }

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  std::cout<<std::fixed<<std::setprecision(10); //小数を出力するときだけ小数点以下10桁

  ll N;
  cin>>N;

  vector <ll> A(N);
  REP(i,N) cin>>A[i];
  auto B = A;
  sort(all(B));

  merge_sort(0,N-1,A);

  REP(i,N) cout<<A[i]<< (i==N-1 ? "\n" : " ");

  REP(i,N) assert(A[i] == B[i]);

  return 0;
}
