#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
#define INF 100000000
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define rep(i, n) for(int (i)=1; (i)<=(n); (i)++)
typedef pair<int, int> P;
typedef long long ll;
int a[100];
int n, k;

bool solve(){
    int i, j, sum, q_size;
    sum = 0;
    queue<int> q;
    if(sum == k) return true;
    q.push(sum);
    for(i=0; i<n; i++){ //a[i]を足すかでループ
        q_size = q.size();
        for(j=0; j<q_size; j++){ //キューの数だけループ
            sum = q.front();
            q.pop();
            //和がkならtrueを返す
            if(sum + a[i] == k) return true;
            //キューに入れる
            q.push(sum + a[i]);
            q.push(sum);
        }
    }
    return false;
}

int main(){
    int i;
    //入力
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    //出力
    if(solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}