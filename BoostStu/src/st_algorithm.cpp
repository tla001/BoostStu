/*
 * st_algorithm.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: tla001
 */

#include "st_algorithm.h"

void Tforeach()
{
	map<int,string> m=list_of(make_pair(1,"one"))(make_pair(2,"two"));
	pair<int,string> x;
	BOOST_FOREACH(x,m)
		cout<<x.first<<"\t"<<x.second<<endl;
}
void Tmaxmin()
{
	cout<<std::max(200,12)<<endl;
	cout<<std::min(200,12)<<endl;
}
void Tinteger()
{
	cout<<integer_traits<int>::const_max<<endl;
	cout<<integer_traits<bool>::const_min<<endl;
	cout<<integer_traits<long>::is_signed<<endl;

	uint8_t u8;
	int_fast16_t i16;
	uintmax_t um;
	u8=255;
	i16=3200;
	um=u8+i16;
	cout<<typeid(u8).name()<<":"<<sizeof(u8)<<"v="<<(short)u8<<endl;
	cout<<typeid(i16).name()<<":"<<sizeof(i16)<<"v="<<i16<<endl;

	cout<<numeric_limits<uint_least16_t>::max()<<endl;
	cout<<numeric_limits<int_fast32_t>::max()<<endl;
}
void Tcrc()
{
	crc_32_type crc32;
	cout<<hex;
	cout<<crc32.checksum()<<endl;
	crc32.process_byte('a');
	cout<<crc32.checksum()<<endl;
	crc32.process_bytes("0123456789",10);
	cout<<crc32()<<endl;
	crc32.reset();
	char ch[]="1234567890";
	crc32.process_block(ch,ch+10);
	cout<<crc32.checksum()<<endl;
}
