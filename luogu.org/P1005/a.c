#include <stdio.h>
#include <string.h>

#define BASE 1000
#define WIDTH 64

/* structure */
struct bgint{
	int buf[WIDTH],top;
};
typedef struct bgint bgint;
/* end */

/* function */
bgint* add   (bgint* dest,bgint* src);
bgint* mul   (bgint* dest,bgint* src);
bgint* mov   (bgint* dest,bgint* src);
bgint* pow2  (bgint* dest,int time);
bgint* clear (bgint* dest);
bgint* readbg(bgint* dest);
bgint* prt   (bgint* dest);

bgint* max(bgint*,bgint*);

void read(void);
bgint* solve(int now);
/* end */

/* global */
int n,m;
bgint a[127][127],dp[127][127],twopower[89];
bgint ans;
/* end */

int main(void){
	int i;
	clear(&ans);
	read();
	for(i=0;i<n;++i) add(&ans,solve(i));
	prt(&ans);
	putchar('\n');
	return 0;
}

void read(void){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i) 
		for(j=0;j<m;++j)
			readbg(clear(a[i]+j));
}

bgint* solve(int now){
	int l,r;
	for(l=m-1;l>=0;--l){
		for(r=l;r<m;++r){
			int time=l+m-r;
			if(r){
				bgint eax,ebx;

				pow2(&eax,time);
				mul(&eax,&a[now][l]);
				add(&eax,&dp[l+1][r]);

				pow2(&ebx,time);
				mul(&ebx,&a[now][r]);
				add(&ebx,&dp[l][r-1]);

				mov(dp[l]+r,max(&eax,&ebx));
			} else{
				bgint eax;

				pow2(&eax,time);
				mul(&eax,&a[now][l]);
				add(&eax,&dp[l+1][r]);

				mov(dp[l]+r,&eax);
			}
		}
	}
	return dp[0]+m-1;
}

bgint* clear(bgint* dest){
	memset(dest->buf,0,WIDTH*sizeof(int));
	dest->top=1;
	return dest;
}

bgint* add(bgint* dest,bgint* src){
	int i,newtop=(dest->top>src->top? dest->top : src->top)+10;

	for(i=0;i<newtop;++i) dest->buf[i]+=src->buf[i];
	for(i=0;i<newtop;++i){
		dest->buf[i+1]+=dest->buf[i]/BASE;
		dest->buf[i]%=BASE;
	}
	for(dest->top=newtop;!dest->buf[dest->top] && dest->top >= 0;--dest->top);
	++dest->top;
	return dest;
}

bgint* prt(bgint* now){
	int i;
	printf("%d",now->buf[now->top-1]);
	for(i=now->top-2;i>=0;--i) printf("%03d",now->buf[i]);
	return now;
}

bgint* mov(bgint* dest,bgint* src){
	memcpy(dest->buf,src->buf,WIDTH*sizeof(int));
	dest->top=src->top;
	return dest;
}

bgint* readbg(bgint* dest){
	int tmp;
	scanf("%d",&tmp);
	clear(dest) ->buf[0]=tmp;
	dest->top=0;
	while(dest->buf[dest->top]){
		dest->buf[dest->top+1]+=dest->buf[dest->top]/BASE;
		dest->buf[dest->top]%=BASE;
		++dest->top;
	}
	return dest;
}

bgint* mul(bgint* dest,bgint* src){
	bgint tmp;
	int i,j,newtop=dest->top+src->top+10;
	clear(&tmp);
	for(i=0;i<dest->top;++i)
		for(j=0;j<src->top;++j)
			tmp.buf[i+j]+=dest->buf[i]*src->buf[j];
	for(i=0;i<newtop;++i){
		tmp.buf[i+1]+=tmp.buf[i]/BASE;
		tmp.buf[i]%=BASE;
	}
	for(tmp.top=newtop;!tmp.buf[tmp.top] && tmp.top>=0;--tmp.top);
	++tmp.top;
	return mov(dest,&tmp);
}

bgint* pow2(bgint* dest,int time){
	if(twopower[time].buf[0]) {
		mov(dest,twopower+time);
		return dest;
	}
	bgint base;
	clear(&base);
	clear(dest);

	base.buf[0]=2;
	dest->buf[0]=1;

	while(time){
		if(time&1) mul(dest,&base);
		mul(&base,&base);
		time>>=1;
	}
	mov(twopower+time,dest);
	return dest;
}

bgint* max(bgint* a,bgint* b){
	if(a->top > b-> top) return a;
	if(a->top < b-> top) return b;
	else{
		int i;
		for(i=a->top-1;i>=0;--i){
			if(a->buf[i] > b->buf[i]) return a;
			if(a->buf[i] < b->buf[i]) return b;
		}
	}
	return a;
}
