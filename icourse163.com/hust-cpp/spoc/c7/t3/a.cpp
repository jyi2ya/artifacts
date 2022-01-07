#include<iostream>
#include <cstring>
using namespace std;
class opera

{

    //char name[30]="未命名";//歌剧名称
    char name[30];

    int ts[4];  // ts[0]：包厢的总数，ts[1]：一等座的总座位数

                  //ts[2]：二等座的总座位数，ts[3]：三等座的总座位数

    int es[4];// es[0]：空包厢的数量，es[1]：一等座的空闲座位数

                  //es[2]：二等座的空闲座位数，es[3]：三等座的空闲座位数

    int ps[4];// ps[0]：包厢的票价，ps[1]：一等座的票价

                  //ps[2]：二等座的票价，，ps[3]：三等座的票价

    int income;//总收入

public:

    opera(); //默认构造函数，数据成员的初始值请参看输出样例

    void set_name(char*);//更改剧名

    void set_ps(int[]);//更改座位价格

    void booking(int, int);//售票，如果余票小于订票数，

                         //终止该次售票，并输出购票失败提示信息

    void refund(int, int);//退票，不收手续费

    void print();

    ~opera(); //析构函数，完成票房统计，内容与格式请参看输出样例

};

void opera::refund(int a1, int b1) {
    int k;
    es[a1] += b1;
    if (a1 == 0)
        k=700;
    else if (a1 == 1)
        k=380;
    else if (a1 == 2)
        k=180;
    else
        k=80;
    income -= b1 * k;
}

void opera::booking(int a, int b) {
    int k;
    if (b > es[a]) {
        cout << "余票(" << es[a] << ")不足，购买失败" << endl;
        return;
    }
    else {
        es[a] -= b;
    }
    if (a == 0)
        k = 700;
    else if (a == 1)
        k = 380;
    else if (a == 2)
        k = 180;
    else
        k = 80;
    income += b *k;
}
void opera::set_name(char* p) {
    for (int i = 0; i < 30; i++) {
        name[i]= p[i];
    }
}
void opera::set_ps(int a[]) {
    for (int i = 0; i < 4; i++) {
        ps[i] = a[i];
    }
}
opera::opera() {
   
	strcpy(name, (char *)"未命名");
    income = 0;
    ps[0]=0,ps[1]=0,ps[2]=0,ps[3]=0;
    ts[0] = 20,ts[1]=100,ts[2]=240,ts[3]=300;
    for (int i = 0; i < 4; i++) {
        es[i] = ts[i];
    }
}
opera::~opera() {
    cout << "二进宫的总收入：" << income << endl;

    cout << "二进宫的票房如下：" << endl;

    cout << "包厢售出" << ts[0] - es[0] << endl;
    cout << "一等座售出" << ts[1] - es[1] << endl;
    cout << "二等座售出" << ts[2] - es[2] << endl;
    cout << "三等座售出" << ts[3] - es[3] << endl;
}




void opera::print()

{

    char line[20] = "------------------";

    cout << line << "戏曲名：" << name << line << endl;



    char st[4][20] = { "包厢","一等座","二等座","三等座" };



    for (int i = 0; i < 4; i++)

        cout << st[i] << "<" << "票价：" << ps[i] << " /总数：" << ts[i] << " /可售：" << es[i] << ">" << endl;



    cout << line << "总收入：" << income << line << endl << endl;

};
int main()

{

    opera p1;

    p1.print();



    p1.set_name((char *)"二进宫");//更改剧名



    int p[] = { 700,380,180,80 };

    p1.set_ps(p);//更改座位价格



    p1.booking(0, 9);//购买9张包厢票

    p1.booking(1, 15);//购买15张一等票

    p1.booking(3, 20);//购买20张三等票

    p1.print();



    p1.booking(0, 13);//购买13张包厢票

    p1.booking(2, 14);//购买14张二等票

    p1.refund(3, 6);//退6张三等票

    p1.print();

    return 0;

}
