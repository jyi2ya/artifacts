#include <stdio.h>
#include <string.h>

char visr[20009],vis[20009];
int x[509],y[509];

int main(void)
{
	int n,m,i,j,ans=0,k;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<k;++i){
		scanf("%d%d",x+i,y+i);
		visr[x[i]]=1;
	}
	for(i=1;i<=n;++i){
		int tot=m;
		if(visr[i]) continue;
		memset(vis,0,sizeof(vis));
		for(j=0;j<k;++j){
			if(!vis[y[j]]){
				vis[y[j]]=1;
				--tot;
			}
			if(i>x[j]){
				if(y[j]-(i-x[j]) > 0){
					if(!vis[y[j]-(i-x[j])]){
						vis[y[j]-(i-x[j])]=1;
						--tot;
					}
				}
				if(y[j]+(i-x[j]) <= m){
					if(!vis[y[j]+(i-x[j])]){
						vis[y[j]+(i-x[j])]=1;
						--tot;
					}
				}
			}
			if(i<x[j]){
				if(y[j]-(x[j]-i) > 0){
					if(!vis[y[j]-(x[j]-i)]){
						vis[y[j]-(x[j]-i)]=1;
						--tot;
					}
				}
				if(y[j]+(x[j]-i) <= m){
					if(!vis[y[j]+(x[j]-i)]){
						vis[y[j]+(x[j]-i)]=1;
						--tot;
					}
				}
			}
		}
		ans+=tot;
	}
	printf("%d\n",ans);
	return 0;
}
