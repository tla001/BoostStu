/*
 * st_smartptr.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: tla001
 */
#include "st_smartptr.h"
void Tscoped_ptr() {
	scoped_ptr < string > sp(new string("text"));
	cout << *sp << endl;
	cout << sp->size() << endl;

	auto_ptr<int> ap(new int(10));
	scoped_ptr<int> sp1(ap);
	assert(ap.get() == 0);
	ap.reset(new int(10));
	cout << *ap << "," << *sp1 << endl;

	//auto_ptr可以直接赋值操作，但是scoped_ptr不可以，他们都不能作为容器的元素
	//auto_ptr时由于转移语义  scoped_ptr 是由于不支持拷贝和赋值（声明为私有，拒绝指针所有权的转让）
	auto_ptr<int> ap2;
	ap2 = ap;
	assert(ap.get() == 0);
}

void Tscoped_array() {
	scoped_array<int> sa1(new int[100]);
	//重载了 ［］运算符，但是不能使用指针寻址
	//析构函数中使用的是delete[]
	//也不能使用容器以及stl算法
	sa1[1] = 10;
	cout << sa1[1] << endl;

	int *arr = new int[100];
	//使用scoped_array代理
	scoped_array<int> sa2(arr);

	fill_n(&sa2[0], 100, 5);
	cout << sa2[20] + sa2[30] << endl;
}
void Tshared_ptr() {
	//和scoped_ptr相比，有正常的拷贝赋值语义，可以进行同类型间的比较
	boost::shared_ptr<int> spi(new int);
	*spi = 10;
	assert(spi);
	cout << *spi << endl;
	assert(spi.unique());
	boost::shared_ptr<int> spi2 = spi;
	cout << spi.use_count() << endl;
	//停止shared_ptr的使用，spi不再持有任何指针
	spi.reset();
	assert(!spi);

	boost::shared_ptr < string > sps(new string("hi"));
	cout << sps->size() << endl;

	//可以用于标准关联容器(set map)
	typedef boost::shared_ptr<string> sp_t;
	map<sp_t, int> m;
	map<sp_t, int>::iterator iter;
	sp_t sp(new string("one"));
	m[sp] = 111;
	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << *iter->first << "\t" << iter->second << endl;
	}
}
void Tmake_shared() {
	//make_shared可以避免显示的调用new
	boost::shared_ptr < string > sp = make_shared < string > ("make_shared");
	boost::shared_ptr < vector<int> > spv = make_shared < vector<int> > (10, 2);
	cout << sp->size() << "\t" << spv->size() << endl;

	typedef vector<boost::shared_ptr<int> > vs;
	vs v(10);
	int i = 0;
	for (vs::iterator pos = v.begin(); pos != v.end(); pos++) {
		(*pos) = make_shared<int>(++i);
		cout << *(*pos) << " ";
	}
	cout << endl;
	shared_ptr<int> p = v[9];
	*p = 100;
	cout << *v[9] << endl;
	//引用计数
	cout << v[9].use_count() << endl;
}
void Tshared_array() {
	int*p = new int[100];
	shared_array<int> sa(p);
	shared_array<int> sa2 = sa;
	cout << sa.use_count() << endl;
}

void Tpool() {
	pool<> pl(sizeof(int));	//一个可以分配int的内存池
	int *p = (int *) pl.malloc();
	assert(pl.is_from(p));
	pl.free(p);
	object_pool < string > opl;
	string *op = opl.malloc();	//分配内存
	assert(opl.is_from(op));

	op = opl.construct("tao");	//构造对象，初始化
	cout << *op << endl;
	cout << op->size() << endl;
}
