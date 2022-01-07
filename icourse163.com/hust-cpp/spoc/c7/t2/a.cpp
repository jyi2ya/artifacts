#include <iostream>

using namespace std;

double tax=0; //系统收到的交易税

class NPC

{      

       int role;//角色类型，1：农夫,2：矿工

       char skill;//技能，'c':种植，是农夫的技能，'d'：挖掘，是矿工的技能

       double gold;//金币数量

       double corn;//谷物数量

public:

       NPC(int _r)//构造函数，新对象的角色值为_r,技能和角色配套，金币和谷物数量都为0
       {
	       role = _r;
	       skill = role == 1 ? 'c' : 'd';
	       gold = 0;
	       corn = 0;
       }

       void work()//工作。角色为农夫，谷物数量增加1000；角色为矿工，金币数量增加5
       {
	       if (skill == 'c')
		       corn += 1000;
	       if (skill == 'd')
		       gold += 5;
       }

       void trade(NPC &p)//交易。交易双方必须为不同类型角色,且农夫的谷物不少于200，矿工的金币不少于4.5
       {
	       NPC &farmer = role == 1 ? *this : p;
	       NPC &miner = role == 1 ? p : *this;
	       if (p.role == role)
		       return;
	       if (farmer.corn < 200 || miner.gold < 5)
		       return;
	       farmer.corn -= 200;
	       farmer.gold += 4;
	       miner.corn += 200;
	       miner.gold -= 4;
	       farmer.gold -= 0.5;
	       miner.gold -= 0.5;
	       tax += 1;
       }

              //交易后，农夫的谷物减少200，金币增加4,矿工的金币减少4，谷物增加200。双方各自缴纳0.5个金币的税

       double get_corn()//返回corn的值
       {
	       return corn;
       }

       double get_gold()//返回gold的值
       {
	       return gold;
       }

       char get_skill()//返回技能
       {
	       return skill;
       }

};

 

int main()

{

       NPC NP1(1),NP2(2);

       for (int i=0;i<3;i++) NP1.work();

       NP2.work();

       cout<<"NP1.skill:"<<NP1.get_skill()<<'\t'<<"NP1.corn:"<<NP1.get_corn()<<'\t'

       <<"NP1.gold:"<<NP1.get_gold()<<endl;

       cout<<"NP2.skill:"<<NP2.get_skill()<<'\t'<<"NP2.corn:"<<NP2.get_corn()<<'\t'

       <<"NP2.gold:"<<NP2.get_gold()<<endl;

       for (int i=0;i<2;i++)

       {     

              cout<<"trade_"<<i+1<<"----------------------------"<<endl;

              NP1.trade(NP2);

              cout<<"NP1.skill:"<<NP1.get_skill()<<'\t'<<"NP1.corn:"<<NP1.get_corn()

                     <<'\t'<<"NP1.gold:"<<NP1.get_gold()<<endl;

              cout<<"NP2.skill:"<<NP2.get_skill()<<'\t'<<"NP2.corn:"<<NP2.get_corn()

                     <<'\t'<<"NP2.gold:"<<NP2.get_gold()<<endl;

              cout<<"tax:"<<tax<<endl;

       }

       return 0;

}
