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

	//auto_ptr����ֱ�Ӹ�ֵ����������scoped_ptr�����ԣ����Ƕ�������Ϊ������Ԫ��
	//auto_ptrʱ����ת������  scoped_ptr �����ڲ�֧�ֿ����͸�ֵ������Ϊ˽�У��ܾ�ָ������Ȩ��ת�ã�
	auto_ptr<int> ap2;
	ap2 = ap;
	assert(ap.get() == 0);
}

void Tscoped_array() {
	scoped_array<int> sa1(new int[100]);
	//������ �ۣ�����������ǲ���ʹ��ָ��Ѱַ
	//����������ʹ�õ���delete[]
	//Ҳ����ʹ�������Լ�stl�㷨
	sa1[1] = 10;
	cout << sa1[1] << endl;

	int *arr = new int[100];
	//ʹ��scoped_array����
	scoped_array<int> sa2(arr);

	fill_n(&sa2[0], 100, 5);
	cout << sa2[20] + sa2[30] << endl;
}
void Tshared_ptr() {
	//��scoped_ptr��ȣ��������Ŀ�����ֵ���壬���Խ���ͬ���ͼ�ıȽ�
	boost::shared_ptr<int> spi(new int);
	*spi = 10;
	assert(spi);
	cout << *spi << endl;
	assert(spi.unique());
	boost::shared_ptr<int> spi2 = spi;
	cout << spi.use_count() << endl;
	//ֹͣshared_ptr��ʹ�ã�spi���ٳ����κ�ָ��
	spi.reset();
	assert(!spi);

	boost::shared_ptr < string > sps(new string("hi"));
	cout << sps->size() << endl;

	//�������ڱ�׼��������(set map)
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
	//make_shared���Ա�����ʾ�ĵ���new
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
	//���ü���
	cout << v[9].use_count() << endl;
}
void Tshared_array() {
	int*p = new int[100];
	shared_array<int> sa(p);
	shared_array<int> sa2 = sa;
	cout << sa.use_count() << endl;
}

void Tpool() {
	pool<> pl(sizeof(int));	//һ�����Է���int���ڴ��
	int *p = (int *) pl.malloc();
	assert(pl.is_from(p));
	pl.free(p);
	object_pool < string > opl;
	string *op = opl.malloc();	//�����ڴ�
	assert(opl.is_from(op));

	op = opl.construct("tao");	//������󣬳�ʼ��
	cout << *op << endl;
	cout << op->size() << endl;
}
