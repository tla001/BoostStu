/*
 * st_tools.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: tla001
 */
#include "Include.h"
void Ttypeof()
{
	//typeof 类型推倒
	//BOOST_TYPEOF(2.3*3) x=2.0*3;
	//BOOST_AUTO(y,2);
	//BOOST_AUTO(&a,new double[20]);
}

void Tassign()
{
	//assign 重载+=运算符
	vector<int> v;
	vector<int>::iterator vi;
	v+=1,2,3,4,5,6;

	set<string> s;
	s+="cpp","java","c#";

	map<int,string> m;
	m+=make_pair(1,"one"),make_pair(2,"two");

	//assign 辅助函数 insert push_back push_front
	//push_back(v)(1)(7)(9);
	//push_front(v),8;
	insert(s)("cpp2");
	insert(m)(4,"four");
	//使用list_of初始化
	deque<string> d=(list_of("tao")("wang"),"zhang","li");
	map<int,string> m2=list_of(make_pair(1,"one"))(make_pair(2,"two"));
	//vector< vector<int> > vv=list_of(list_of(1)(2))(list_of(2)(3));
	//使用map_list_of
	//map<int,int> m3=map_list_of((1,2),(3,4));

	for(vi=v.begin();vi!=v.end();vi++)
		cout<<*vi<<"\t";
	cout<<endl;
	for(set<string>::iterator si=s.begin();si!=s.end();si++)
		cout<<*si<<"\t";
	cout<<endl;
	for(map<int,string>::iterator mi=m.begin();mi!=m.end();mi++)
		cout<<mi->first<<"\t:"<<mi->second<<endl;
	cout<<endl;
}
void Tswap()
{
	int a[10];
	int b[10];
	boost::swap(a,b);
}
void Ttibool()
{
	tribool tb(true);
	tribool tb2(!tb);
	if(tb){
		cout<<"true"<<endl;
	}
	cout<<tb<<"\t"<<tb2<<endl;
	tb2=indeterminate;
	assert(indeterminate(tb2));
	cout<<(tb2||true)<<endl;
	cout<<(tb2&&false)<<endl;
	cout<<tb<<"\t"<<tb2<<endl;
}

void Tuuid()
{
	//唯一标识符
	uuid u;
	vector<unsigned char> v(16,7);
	copy(v.begin(),v.end(),u.begin());
	cout<<u.size()<<"\t"<<u<<endl;

	//Nil生成器 无效的uuid
	uuid u1= nil_generator()();
	assert(u1.is_nil());
	cout<<u1<<endl;
	u1=nil_uuid();
	assert(u1.is_nil());

	//字符串生成器
	string_generator sgen;
	uuid u2=sgen("0123456789abcdef0123456789abcdef");
	cout<<u2<<endl;
	uuid u3=sgen("01234567-89ab-cdef-0123-456789abcdef");
	cout<<u3<<endl;

	//名字生成器
	//随机生成器
	random_generator rgen;
	uuid u4=rgen();
	assert(u4.version()==uuid::version_random_number_based);
	cout<<u4<<endl;
	//uuid转换为字符串
	string str =lexical_cast<string>(u4);
	cout<<str<<endl;
}
void Tsha1()
{
	sha1 sha;
	char *szmsg="a short message";
	sha.process_byte(0x01);//处理一个字节
	sha.process_bytes(szmsg,strlen(szmsg));//处理多个字节
	sha.process_block(szmsg,szmsg+strlen(szmsg));
	unsigned int digest[5];
	sha.get_digest(digest);
	for(int i=0;i<5;i++)
		cout<<hex<<digest[i];
}
