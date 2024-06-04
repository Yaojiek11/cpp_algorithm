#include <iostream>
using namespace std;
 
const int Max=500;
int H,W;
char c[Max][Max];
bool reached[Max][Max];
 
void search(int x,int y){
        if(x<0 || H<=x || y<0 || W<=y || c[x][y]=='#') return;
        if(reached[x][y]) return;
        reached[x][y]=true;
        search(x+1,y);
        search(x-1,y);
        search(x,y+1);
        search(x,y-1);
}
 
int main(){
    cin>>H>>W;
    int s_h,s_w,g_h,g_w;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>c[i][j];
            if(c[i][j]=='s'){
                s_h=i;
                s_w=j;
            }
            if(c[i][j]=='g'){
                g_h=i;
                g_w=j;
            }
        }
    }
    search(s_h,s_w);
    if(reached[g_h][g_w]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}