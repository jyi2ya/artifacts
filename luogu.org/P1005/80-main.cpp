#include<cstdio>
#include <cstring>

#define BASE 1000
#define WIDTH 255

#define DBGOUT(a) ({\
		printf("DEBUG:line[%d]:out: "#a"=",__LINE__);\
		out(a);\
		putchar('\n');\
		})

typedef struct{
	int buf[WIDTH],top=0;
}BGint;

BGint a[WIDTH][WIDTH];
BGint dp[WIDTH][WIDTH];
int m,n;

void read(void);
void solve(int);
void clear(void);

BGint* max(BGint*,BGint*);
BGint* add(BGint*,BGint*);
BGint* mov(BGint*,BGint*);
BGint* pow2(BGint*,int);
BGint* out(BGint*);
BGint* mul(BGint*,BGint*);
BGint* init(BGint*);

int main(){
	BGint ans;
	init(&ans);

	read();
	int i;
	for(i=0;i<n;++i){
		solve(i);
		add(&ans,&dp[0][m-1]);
	}
	out(&ans);
	putchar('\n');
	return 0;
}

void clear(void){
	int i,j;
	for(i=0;i<=m;++i){
		for(j=0;j<=m;++j) {
			init(dp[i]+j);
		}
	}
}

void solve(int now){
	int l,r;
	clear();
	for(l=m-1;l>=0;--l){
		for(r=l;r<m;++r){
			int time=l+m-r;
			if(r){
				BGint tmp1,tmp2,eax,ebx;

				mov(&tmp1,dp[l+1]+r);
				mov(&eax,a[now]+l);

				pow2(&ebx,time);

				mul(&eax,&ebx);

				add(&tmp1,&eax);

				mov(&tmp2,dp[l]+r-1);
				mov(&eax,a[now]+r);

				pow2(&ebx,time);
				mul(&eax,&ebx);

				add(&tmp2,&eax);

				mov(dp[l]+r,max(&tmp1,&tmp2));
			} else{
				BGint tmp,eax,ebx;

				mov(&tmp,dp[l+1]+r);
				mov(&eax,a[now]+l);

				pow2(&ebx,time);
				mul(&eax,&ebx);

				add(&tmp,&eax);
				mov(dp[l]+r,&tmp);
			}
		}
	}
}

void read(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			init(a[i]+j);
			scanf("%d",a[i][j].buf);
			if(a[i][j].buf[0]>=1000) {
				a[i][j].buf[0]-=1000;
				a[i][j].buf[1]=1;
				a[i][j].top=2;
			}else a[i][j].top=1;
		}
}

BGint* pow2(BGint* dest,int time){
	BGint base;
	init(dest);
	init(&base);

	base.buf[0]=2;
	dest->buf[0]=1;

	while(time){
		if(time & 1) mul(dest,&base);
		mul(&base,&base);
		time>>=1;
	}
	return dest;
}
BGint* max(BGint* a,BGint* b){
	int p=a->top;
	if(a->top > b->top) return a;
	if(a->top < b->top) return b;
	while(--p>=0){
		if(a->buf[p] > b->buf[p]) return a;
		if(a->buf[p] < b->buf[p]) return b;
	}
	return a;
}
BGint* mov(BGint* dest,BGint* src){
	memcpy(dest->buf,src->buf,sizeof(int)*WIDTH);
	dest->top=src->top;
	return dest;
}
BGint* add(BGint* a,BGint* b){
	int i,bit=(a->top > b->top) ? a->top : b->top;
	for(i=0;i<bit;++i) {
		a->buf[i]+=b->buf[i];
		if(a->buf[i] >= BASE) ++a->buf[i+1];
		a->buf[i]%=BASE;
	}
	a->top=1;
	while(a->buf[a->top]) ++a->top;
	return a;
}
BGint* mul(BGint* a,BGint* b){
	int i,j;
	BGint ans;
	init(&ans);

	for(i=0;i<a->top;++i)
		for(j=0;j<b->top;++j){
			ans.buf[i+j]+=(a->buf[i])*(b->buf[j]);
			if(ans.buf[i+j]>=BASE) {
				ans.buf[i+j+1]+=ans.buf[i+j]/BASE;
				ans.buf[i+j]%=BASE;
			}
		}
	while(ans.buf[ans.top]) ++ans.top;
	mov(a,&ans);
	return a;
}
BGint* out(BGint *a){
	int i=a->top-1;
	printf("%d",a->buf[i--]);
	while(i>=0) printf("%03d",a->buf[i--]);
	return a;
}
BGint* init(BGint* a){
	a->top=1;
	memset(a->buf,0,sizeof(int)*WIDTH);
	return a;
}
