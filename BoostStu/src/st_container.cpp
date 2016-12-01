/*
 * st_container.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: tla001
 */

#include "st_container.h"

void Tarray() {
	boost::array<int, 10> ar;
	ar[0] = 1;
	ar.back() = 10;
	assert(ar[ar.max_size() - 1] == 10);
	ar.assign(12);
	for (boost::array<int, 10>::iterator pos = ar.begin(); pos != ar.end();
			++pos) {
		cout << *pos << ",";
	}
	int *p = ar.c_array(); //获取于是数组指针
	*(p + 5) = 253;
	cout << ar[5] << endl;
	ar.at(8) = 66;
	cout << ar[8] << endl;
	sort(ar.begin(), ar.end());
	for (boost::array<int, 10>::iterator pos = ar.begin(); pos != ar.end();
			++pos) {
		cout << *pos << ",";
	}
	cout << endl;
}
void Tbimap() {
	bimap<int, string> bm;
	//使用左视图
	//bm.left.insert(make_pair(1,"111"));
}
void TcirBuf() {
	circular_buffer<int> cb(5);
	circular_buffer<int>::iterator item;
	//cb.insert(cb.begin(), 0);
	cout << "size=" << cb.size() << endl;
	assert(cb.empty());
	int i;
	for (item = cb.begin(); item != cb.end(); ++item) {
		*item = i;
		i++;
		cout << *item << "\t";
	}
	//cb.push_back(1);
	//cb.push_front(2);
	//cb[4]=1;
	//cout<<cb.at(0)<<endl;

	vector<int> num;
	num.push_back(1);
}
void propertyTree() {
	ptree pt;
	read_xml("/home/tla001/workspace/conf.xml", pt);
	cout << pt.get < string > ("conf.theme") << endl;
	cout << pt.get<int>("conf.clock_style") << endl;
	cout << pt.get<long>("conf.gui") << endl;
	ptree child = pt.get_child("conf.urls");
	child.pop_front();
	cout << child.get < string > ("url") << endl;
	//cout<<pt.get<string>("conf.urls.url")<<endl;
//	for(ptree::iterator pos=child.begin();pos!=child.end();++pos){
//		//cout<<"url:"<<pos->second.get<string>("url") <<endl;
//	}
	pt.put("conf.theme", "Matix reloaded");
	//pt.put("conf.urls.url","http://www.360.com");
	pt.add("conf.urls.url", "http://www.360.com");
	//write_xml(cout,pt);
	write_xml("/home/tla001/workspace/conf.xml", pt);
}
