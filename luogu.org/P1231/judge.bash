#!/bin/bash

output_other()
{
	cat <<'EOF'
#include <stdio.h>
#include <string.h>
#define ll long long
#define N 51001
#define M 151001
#define inf 23333333
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define fur(i,x,y) for(i=x;i<=y;i++)
#define fdr(i,x,y) for(i=x;i>=y;i--)
#define Fur(i,x,y) for(ll i=x;i<=y;i++)
#define Fdr(x,y) for(ll i=x;i>=y;i--)
#define in2(x,y) in(x);in(y)
#define in3(x,y,z) in2(x,y);in(z)
#define in4(a,b,c,d) in2(a,b);in2(c,d)
#define ln pc('\n');
#define pk pc(' ');
#define outn(x) out(x);ln;
#define outk(x) out(x);pk;
#define out2(x,y) outk(x);outn(y);
#define out3(x,y,z) outk(x);out2(y,z)
#define out4(w,x,y,z) outk(w);out3(x,y,z)
#define clr(x,y) memset(x,y,sizeof(x))
#define cpy(x,y) memcpy(x,y,sizeof(x))

/*---------------------------------------*/

namespace fib{char b[300000]= {},*f=b;}
#define gc ((*fib::f)?(*(fib ::f++)):(fgets(fib::b,sizeof(fib::b),stdin)?(fib::f=fib::b,*(fib::f++)):-1))
inline void in(ll &x){x=0;char c;bool f=0;while((c=gc)>'9'||c<'0')if(c=='-')f=!f;x=c-48;while((c=gc)<='9'&&c>='0')x=x*10+c-48;if(f)x=-x;}
namespace fob{char b[300000]= {},*f=b,*g=b+300000-2;}
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
struct foce{~foce(){pob;fflush(stdout);}} _foce;
namespace ib{char b[100];}
inline void out(ll x){if(x==0){pc(48);return;}if(x<0){pc('-');x=-x;}char *s=ib::b;while(x) *(++s)=x%10,x/=10;while(s!=ib::b) pc((*(s--))+48);}
inline void ps(char s[]){ll i=0,len=strlen(s);while(i<len)pc(s[i++]);}

/*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------*/

struct edge{ll next,to,w;}e[M];
ll cnt=2,n,m,st,ed;
ll head[N],d[N]={0},q[N*2];
inline void add(ll x,ll y,ll w){e[cnt].to=y;e[cnt].next=head[x];e[cnt].w=w;head[x]=cnt++;}//邻接表
inline void ins(){
    ll n1,n2,n3,m,i,x,y;
    in3(n1,n2,n3);
    st=1;//源点
    ed=n2+n1*2+n3+2;//汇点
    in(m);
    while(m--){
	in2(x,y);y++;x+=n2+1;
	add(y,x,1);add(x,y,0);
}
    fur(i,n2+2,n2+n1+1){y=i+n1;add(i,y,1);add(y,i,0);}
    in(m);
    while(m--){
	in2(x,y);x+=n2+n1+1;y+=n1*2+n2+1;
	add(x,y,1);add(y,x,0);
}
    fur(i,2,n2+1){add(st,i,1);add(i,st,0);}
    fur(i,n2+n1*2+2,ed-1){add(i,ed,1);add(ed,i,0);}
}
inline bool bfs(){
    ll h=0,t=1,x,i;
    clr(d,0);
    q[h]=st;d[st]=1;
    while(h<t){
	x=q[h++];if(x==ed)return 1;
	for(i=head[x];i;i=e[i].next)
	if(e[i].w&&!d[e[i].to]){
	    d[e[i].to]=d[x]+1;
	    q[t++]=e[i].to;
    }
}
    return 0;
}
inline ll dfs(ll x,ll mf){
    if(x==ed)return mf;
    ll i,us=0,w;
    for(i=head[x];i;i=e[i].next)
    if(e[i].w&&d[e[i].to]==d[x]+1){
	w=mf-us;
	w=dfs(e[i].to,min(e[i].w,w));
	e[i].w-=w;
	e[i^1].w+=w;
	us+=w;
	if(us==mf)return us;
	}
    if(!us)d[x]=-1;//这种dinic加了优化，相对快一些
    return us;
}
inline ll work(){ll ans=0;while(bfs())ans+=dfs(st,inf);return ans;}
int main(){
    freopen("in", "r", stdin);
    ins();//构图
    outn(work());//网络流
}
EOF
}

data()
{
	perl <<'EOF'
$NMAX = 1000;
$MMAX = 1000;
$N1 = $NMAX, $N2 = $NMAX, $N3 = $NMAX;
$M1 = $MMAX, $M2 = $MMAX;
print("$N1 $N2 $N3\n");
print("$M1\n");
for (1..$M1) {
	printf("%d %d\n", rand($N1) + 1, rand($N2) + 1);
}
print("$M2\n");
for (1..$M2) {
	printf("%d %d\n", rand($N1) + 1, rand($N3) + 1);
}
EOF
}

compile()
{
	gcc main.c -o main && g++ o.c -o other
}

output_other > o.c
compile || exit 1
echo 'Judge start'
data > in
./main < in > out
./other < in > ans
while diff out ans; do
	data > in
	./main < in > out
	./other < in > ans
done
