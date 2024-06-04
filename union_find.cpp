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
#define ll long long
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define rep(i, n) for(int (i)=1; (i)<=(n); (i)++)
typedef pair<int, int> P;

const int MAX_N = 100000;
int par[MAX_N+10]; //親の番号
int ran[MAX_N+10]; //木の深さ

//n要素で初期化
void init(int n){
    rep(i, n){
        par[i] = i; //はじめはすべての頂点は親
        ran[i] = 0;
    }
}

//木の根を求める
int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]); //経路圧縮 //根を見つけるまで再帰的に処理
    }
}

//xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    //ランクが大きいほうを小さいほうの根にする
    if(ran[x] < ran[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(ran[x] == ran[y]) ran[x]++; //同じ場合、1ランクだけずれる
    }
}

//xとyが同じ集合に属するか否か
bool same(int x, int y){
    return find(x) == find(y);
}

int N, Q, p, a, b;

int main(){
    cin >> N >> Q;
    init(N);
    REP(i, Q){
        cin >> p >> a >> b;
        if(p == 0){
            unite(a, b);
        }else{
            if(same(a, b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}