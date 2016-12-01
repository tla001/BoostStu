/*
 * Include.h
 *
 *  Created on: Jul 17, 2016
 *      Author: tla001
 */

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#include <vector>
#include <set>
#include <map>
#include <deque>
#include <numeric>

#include <boost/regex.hpp>
#include <boost/thread.hpp>
#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/assert.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>//���ڴ���
#include <boost/date_time/posix_time/posix_time.hpp>//ʱ�䴦��
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>//����ģʽ
#include <boost/pool/pool.hpp>//�ڴ��
#include <boost/pool/object_pool.hpp>//�����ڴ��
#include <boost/pool/singleton_pool.hpp>
#include <boost/utility.hpp>//С����
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/swap.hpp>
#include <boost/logic/tribool.hpp>//��̬�߼�
#include <boost/logic/tribool_io.hpp>
#include "uuids.h"
#include <boost/lexical_cast.hpp>//�ַ���ת��
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>//�ַ�������
#include <boost/tokenizer.hpp>//�ַ����ִʴ���
#include <boost/xpressive/xpressive_dynamic.hpp>//��̬����
//����
#include <boost/array.hpp>
#include <boost/bimap.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
//�㷨
#include <boost/foreach.hpp>
//��ѧ
#include <boost/integer_traits.hpp>//������
#include <boost/cstdint.hpp>//��������
#include <boost/rational.hpp>//������
//���ݴ���
#include <boost/crc.hpp>
#include <boost/random.hpp>
//����
#include <boost/utility/result_of.hpp>//����Զ��Ƶ�
#include <boost/bind.hpp>

using namespace std;
using namespace boost;
using namespace boost::gregorian;
using namespace boost::posix_time;
//using namespace boost::type_of;
using namespace boost::assign;
using namespace boost::xpressive;
using namespace boost::property_tree;

#endif /* INCLUDE_H_ */
