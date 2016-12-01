/*
 * st_timer.cpp
 *
 *  Created on: Jul 19, 2016
 *      Author: tla001
 */
#include "st_timer.h"

void Ttimer() {
	//声明一个计时对象
	timer t;
	cout << "max timespan:" << (double) t.elapsed_max() / 3600 << " h" << endl;
	cout << "min timespan:" << (double) t.elapsed_min() << " s" << endl;

	long long sum = 0;
	for (int i = 0; i < 10000000; i++)
		sum = sum + i;
	cout << "now time elapsed:" << (double) t.elapsed() << " s" << endl;

	progress_timer t1; //析构时自动输出自对象创建所流逝的时间
	for (int i = 0; i < 10000000; i++)
		sum = sum + i;
}
void TprogressDisplay() {
	vector < string > v(100);
	ofstream file("test.txt");

	//声明一个progress_display 对象,技术大小为v的大小
	//progress_display pd(v.size());
	progress_display pd(v.size(), cout, "百分比：\t", "状态栏：\t", "进度：\t");
	vector<string>::iterator pos;
	for (pos = v.begin(); pos != v.end(); pos++) {
		file << *pos << endl;
		//usleep(100000);
		//++pd;
		if (pos->empty()) {
			cout << endl;
			cout << "null string" << endl;
			pd.restart(v.size());
			pd += (pos - v.begin() + 1);
		} else
			++pd;
	}
}
void Tdate() {
	//gregorian::date d1;
	date d1;		//一个无效的日期
	date d2(2010, 1, 1);
	date d3(2010, Jan, 1);
	date d4(d2);
	//需要 -l boost_date_time
	date d5 = from_string("1999-12-31");
	date d6(from_string("2005/1/1"));
	date d7 = from_undelimited_string("20011118");

	date d8(max_date_time);
	date d9(min_date_time);
	date d10(not_a_date_time);

	cout << d5 << endl;
	cout << d8 << endl;
	cout << d10 << endl;

	cout << day_clock::local_day() << endl;
	cout << day_clock::universal_day() << endl;

	//日期对象的比较
	//assert(d2<d4);
	assert(d2 == d4);
	//assert(d3<d4);

	//date::ymd_type可以一次性获取年月日数据
	date::ymd_type ymd = d5.year_month_day();
	assert(ymd.year == 1999);
	cout << ymd.month << endl;

	cout << d5.day_of_week() << endl;
	cout << d5.day_of_year() << endl;
	cout << d5.end_of_month() << endl;
	cout << d5.week_number() << endl;
	//字符串输出
	cout << to_simple_string(d5) << endl;
	cout << to_iso_string(d5) << endl;
	cout << to_iso_extended_string(d5) << endl;

	//与tm结构转换
	tm tm1 = to_tm(d5);
	date d11 = date_from_tm(tm1);
	cout << d11 << endl;
}
void TdateDeal() {
	//支持 + - × / 运算
	days dd1(10);
	days dd2(-100), dd3(255);
	//assert(dd1==dd2);
	weeks wk(3);
	cout << wk.days() << endl;

	months mt(2);
	years yr(1);
	months mt1 = yr + mt;
	cout << mt1.number_of_months() << endl;

	//日期计算
	date d1 = from_string("1993-12-28");
	date d2(2016, 7, 24);
	cout << "days total:" << d2 - d1 << endl;

	//日期区间
	date_period dp(date(2010, 1, 1), days(20));
	dp.shift(days(2));
	cout << "the begin day is :" << dp.begin().day() << endl;
	cout << "period is " << dp.length().days() << endl;

	//日期迭代器
	day_iterator d_iter(d2);
	++d_iter;
	cout << to_simple_string(*d_iter) << " " << d_iter->day_of_week() << endl;
}
void TtimeDeal() {
	//时间间隔
	time_duration td1(1, 10, 30, 1000);
	time_duration td2 = hours(2) + seconds(10);
	hours h(1);
	minutes m(10);
	seconds s(30);
	millisec ms(10);
	time_duration td3 = h + m + s + ms;
	time_duration td4 = duration_from_string("1:10:30:001");
	cout << td4.hours() << " h " << td4.minutes() << " min " << td4.seconds()
			<< " s" << endl;
	cout << td4.total_milliseconds() << endl;

	//时间点
	ptime p1(date(2010, 3, 5), hours(1));
	ptime p2 = time_from_string("2010-3-5 01:00:00");

	ptime p3 = second_clock::local_time();
	ptime p4 = microsec_clock::universal_time();
	cout << p3 << endl << p4 << endl;
	cout << p3 + hours(3) << endl;
	cout << to_simple_string(p3) << endl;

	//时间区间
	time_period tp(p4, hours(8));
	tp.shift(hours(2));
	cout << tp.length() << endl << tp.begin().date() << endl;

	//时间迭代器
	for (time_iterator t_iter(p1, minutes(10)); t_iter < p1 + hours(1);
			++t_iter) {
		cout << *t_iter << endl;
	}
}
