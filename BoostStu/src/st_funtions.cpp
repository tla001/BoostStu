/*
 * st_funtions.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: tla001
 */

#include "st_funtions.h"

void Tresultof()
{
	typedef double (*Func)(double d);
	Func func=sqrt;
//	result_of<Func(double)>::type x=func(5.0);
//	cout<<typeid(x).name()<<endl;
}
void Ff(int a,int b){
	cout<< a+b<<endl;
}
void Fg(int a,int b,int c){
	cout<< a+b+c<<endl;;
}
struct demo{
		void f(int a,int b){
			cout<<a+b<<endl;
		}
	};
class point{
public :
	int x;
	int y;
};
void Tbind()
{
	//绑定普通函数
	int x=12,y=4;
	bind(Ff,_1,_2)(x,y);
	bind(Fg,_1,2,1)(x);
	//绑定成员函数
	demo a,&ra=a;
	demo*p=&a;
	bind(&demo::f,a,_1,20)(10);
	bind(&demo::f,ra,_2,_1)(10,20);
	bind(&demo::f,p,_1,_2)(10,20);
	//绑定成员变量
	vector<point> v(10);
	vector<int> v2(10);
	transform(v.begin(),v.end(),v2.begin(),bind(&point::x,_1));
}
