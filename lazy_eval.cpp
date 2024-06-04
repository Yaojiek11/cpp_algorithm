#include <iostream>
#include <numeric>
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

struct LazySegmentTree{
private:
    int n;
    vector<ll> node, lazy;
public:
    LazySegmentTree(vector<ll> v){
        int sz = (int)v.size();
        n = 1;
        while(n > sz) n*=2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    //k番目のノードついて遅延評価を行う
    void eval(int k, int l, int r){
        //遅延配列が空でない場合、自ノード及び子ノードへの
        //値の伝番が起こる
        if(lazy[k] != 0){
            node[k] += lazy[k];
            //最下段かどうかのチェック
            //子ノードは親ノードの1/2の範囲であるため、
            //伝番させるときは半分にする
            if(r - l > 1){
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }

            //伝番が終わったので、自ノードの遅延配列を空にする
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        //k番目のノードに対して遅延評価を行う
        eval(k, l, r);

        //範囲外なら何もしない
        if(b <= l || r <= a) return;
        //完全に被覆しているならば、遅延配列に値を入れた後に評価
        if(a <= l && r <= b){
            lazy[k] += (r - 1) * x;
            eval(k, l, r);
        }
        //そうでないならば、子ノードの値を再帰的に計算して、
        //計算済みの値をもらってくる
        else{
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        //関数が呼び出されたらまず評価
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};
int main(){
    return 0;
}