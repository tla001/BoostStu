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
#include <boost/date_time/gregorian/gregorian.hpp>//日期处理
#include <boost/date_time/posix_time/posix_time.hpp>//时间处理
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>//工厂模式
#include <boost/pool/pool.hpp>//内存池
#include <boost/pool/object_pool.hpp>//对象内存池
#include <boost/pool/singleton_pool.hpp>
#include <boost/utility.hpp>//小工具
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/swap.hpp>
#include <boost/logic/tribool.hpp>//三态逻辑
#include <boost/logic/tribool_io.hpp>
#include "uuids.h"
#include <boost/lexical_cast.hpp>//字符串转换
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>//字符串处理
#include <boost/tokenizer.hpp>//字符串分词处理
#include <boost/xpressive/xpressive_dynamic.hpp>//动态正则
//容器
#include <boost/array.hpp>
#include <boost/bimap.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
//算法
#include <boost/foreach.hpp>
//数学
#include <boost/integer_traits.hpp>//整数类
#include <boost/cstdint.hpp>//数据类型
#include <boost/rational.hpp>//有理数
//数据处理
#include <boost/crc.hpp>
#include <boost/random.hpp>
//函数
#include <boost/utility/result_of.hpp>//结果自动推导
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
