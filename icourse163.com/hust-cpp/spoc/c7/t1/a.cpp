#include <iostream>
using namespace std;

const double PI=3.14159;

class Sphere {
	double r;

	public:
	Sphere()
	{
		r = 0;
	}

	Sphere(double r1)
	{
		r = r1;
	}

	double getV(void);
	double getS(void);
	void setR(double r1);
	void show();
};

double Sphere::getS(void)
{
	return 4.0 * PI * r * r;
}

double Sphere::getV(void)
{
	return 4.0 / 3.0 * PI * r * r * r;
}

void Sphere::show()
{
	cout<<"半径为"<<r<<"的球表面积为"<<getS()<<endl;
	cout<<"半径为"<<r<<"的球体积为"<<getV()<<endl;
}

void Sphere::setR(double r1)
{
	r = r1;
}

int main()
{        
	double r1,r2;
	cin>>r1>>r2;
	Sphere  q1(r1),q2;
	q1.show();
	q2.show();
	q2.setR(r2);
	q2.show();
	return 0;
}
