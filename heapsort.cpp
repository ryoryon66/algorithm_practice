
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

void heapify(ll i,ll N, vector <ll> &A){
  ll left_child = i*2 + 1;
  ll right_child = i*2 + 2;

  if(left_child >= N) return;

  ll left_value = A[left_child];
  ll right_value = -inf;

  if(right_child < N) right_value = A[right_child];

  if(A[i] >= left_value and A[i] >= right_value ) return;

  if(left_value > right_value){
    swap(A[i],A[left_child]);
    heapify(left_child,N,A);
    
  } else {
    swap(A[i],A[right_child]);
    heapify(right_child,N,A);
  }
  return;
}

void init_heap(ll N, vector <ll> &A){

  for(int i=(N-1-1)/2; i>=0 ; i--){
    heapify(i,N,A);
  }

  return;
}

void heap_sort(ll N, vector <ll> &A){
  init_heap(N,A);

  while(N - 1) {
    swap(A[0], A[N - 1]);
    N--;
    heapify(0, N, A);
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

  heap_sort(N,A);

  REP(i,N) cout<<A[i]<< (i==N-1 ? "\n" : " ");

  REP(i,N) assert(A[i] == B[i]);

  return 0;
}
