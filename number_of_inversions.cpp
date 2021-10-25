
//https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D

#include <bits/stdc++.h>
#define INF 100000000000
#define MOD 1000000007
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl;

typedef long long ll;

using namespace std;

//number_of_inversions result
ll ans = 0;

//[left,right)
void merge(vector <ll>& A,ll left,ll right){
  ll mid = (left + right)/2;
  ll left1 = left;
  ll left2 = mid;

  ll right1 = mid;
  ll right2 = right;

  vector <ll> A1;
  vector <ll> A2;
  REP(i,right1-left1) A1.push_back(A[i+left1]);
  REP(i,right2-left2) A2.push_back(A[i+left2]);


  assert(right1 - left1 == A1.size());
  assert(A1.size()+A2.size() == right -left);
  assert(right1 -left1+ right2-left2 == right - left);
  
  
  assert(right1 -left1+ right2-left2 == right - left);
  

  ll i = left;
  right1 -= left1;
  left1 -= left1;
  right2 -= left2;
  left2 -= left2;


  assert(left1 == 0 and left2 == 0);


 assert(right1 -left1+ right2-left2 == right - left);
 assert(right1 + right2 == right - left);


  A1.push_back(INF);
  A2.push_back(INF);

  while(1){
    assert(i <= right);
    assert(left1 <= right1 and left2 <= right2);
    if(left1 == right1 and left2 == right2) {assert(i == right);break;}
    ll a = -1;
    if(A1[left1] <= A2[left2]){
      a = A1.at(left1);
      left1++;
    } else {
      a = A2.at(left2);
      left2++;
      ans += right1 - left1;
    }
    A.at(i) = a;
    i++;
  } 
  
  
  
  return;

}

void merge_sort(vector <ll>& A,ll left, ll right){
  if(left + 1 == right) return;
  ll mid = (left +right)/2;

  merge_sort(A,left,mid);
  merge_sort(A,mid,right);
  merge(A,left,right);

}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  ll N;
  cin>>N;
  vector <ll> A(N);
  REP(i,N) cin>>A[i];

  merge_sort(A,0,N);

  cout<<ans<<endl;

  return 0;
}
