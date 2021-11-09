#include <stdio.h>

char a[10][10];
int N,M,T,sx,sy,fx,fy,ans=0;
int visited[10][10];

void read(){
        scanf("%d%d%d",&N,&M,&T);
        scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
        for(int i=0;i<T;i++){
                int x,y;
                scanf("%d%d",&x,&y);
                a[y-1][x-1]=1;
        }
        for(int i=0;i<=N;i++) a[i][M]=1;
        for(int i=0;i<M;i++) a[N][i]=1;
#ifdef DEBUG
        for(int i=0;i<=N;i++){
                for(int j=0;j<=M;j++) putchar(a[i][j]?'@':' ');
                putchar('\n');
        }
#endif
}

void dfs(int x,int y){
        if(a[y][x]==1 || x<0 || y<0) return;
        if(visited[x][y]) return;
        if(x==fx-1 && y==fy-1) {ans++;return;}
        visited[x][y]=1;
        dfs(x+1,y);
        dfs(x,y+1);
        dfs(x,y-1);
        dfs(x-1,y);
	visited[x][y]=0;
}

int main(){
        read();
        dfs(sx-1,sy-1);
        printf("%d\n",ans);
        return 0;
}

