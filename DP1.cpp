#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define INF 1e9+7

int N, T, dp[501][10001]={};

int main(){
    cin >> N >> T;
    vector<int> t(N+1);
    vector<int> x(N+1);
    for(int i=1; i<=N; i++)
        cin >> t[i] >> x[i];

    for(int i=1; i<=N; i++){
        for(int j=0; j<=T; j++){
            //i番目のやりたいことをやる
            if(j-t[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-t[i]]+x[i]);

            //やらない
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[N][T] << endl;

    return 0;
}