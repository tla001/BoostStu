/*
 * st_timer.cpp
 *
 *  Created on: Jul 19, 2016
 *      Author: tla001
 */
#include "st_timer.h"

void Ttimer() {
	//����һ����ʱ����
	timer t;
	cout << "max timespan:" << (double) t.elapsed_max() / 3600 << " h" << endl;
	cout << "min timespan:" << (double) t.elapsed_min() << " s" << endl;

	long long sum = 0;
	for (int i = 0; i < 10000000; i++)
		sum = sum + i;
	cout << "now time elapsed:" << (double) t.elapsed() << " s" << endl;

	progress_timer t1; //����ʱ�Զ�����Զ��󴴽������ŵ�ʱ��
	for (int i = 0; i < 10000000; i++)
		sum = sum + i;
}
void TprogressDisplay() {
	vector < string > v(100);
	ofstream file("test.txt");

	//����һ��progress_display ����,������СΪv�Ĵ�С
	//progress_display pd(v.size());
	progress_display pd(v.size(), cout, "�ٷֱȣ�\t", "״̬����\t", "���ȣ�\t");
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
	date d1;		//һ����Ч������
	date d2(2010, 1, 1);
	date d3(2010, Jan, 1);
	date d4(d2);
	//��Ҫ -l boost_date_time
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

	//���ڶ���ıȽ�
	//assert(d2<d4);
	assert(d2 == d4);
	//assert(d3<d4);

	//date::ymd_type����һ���Ի�ȡ����������
	date::ymd_type ymd = d5.year_month_day();
	assert(ymd.year == 1999);
	cout << ymd.month << endl;

	cout << d5.day_of_week() << endl;
	cout << d5.day_of_year() << endl;
	cout << d5.end_of_month() << endl;
	cout << d5.week_number() << endl;
	//�ַ������
	cout << to_simple_string(d5) << endl;
	cout << to_iso_string(d5) << endl;
	cout << to_iso_extended_string(d5) << endl;

	//��tm�ṹת��
	tm tm1 = to_tm(d5);
	date d11 = date_from_tm(tm1);
	cout << d11 << endl;
}
void TdateDeal() {
	//֧�� + - �� / ����
	days dd1(10);
	days dd2(-100), dd3(255);
	//assert(dd1==dd2);
	weeks wk(3);
	cout << wk.days() << endl;

	months mt(2);
	years yr(1);
	months mt1 = yr + mt;
	cout << mt1.number_of_months() << endl;

	//���ڼ���
	date d1 = from_string("1993-12-28");
	date d2(2016, 7, 24);
	cout << "days total:" << d2 - d1 << endl;

	//��������
	date_period dp(date(2010, 1, 1), days(20));
	dp.shift(days(2));
	cout << "the begin day is :" << dp.begin().day() << endl;
	cout << "period is " << dp.length().days() << endl;

	//���ڵ�����
	day_iterator d_iter(d2);
	++d_iter;
	cout << to_simple_string(*d_iter) << " " << d_iter->day_of_week() << endl;
}
void TtimeDeal() {
	//ʱ����
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

	//ʱ���
	ptime p1(date(2010, 3, 5), hours(1));
	ptime p2 = time_from_string("2010-3-5 01:00:00");

	ptime p3 = second_clock::local_time();
	ptime p4 = microsec_clock::universal_time();
	cout << p3 << endl << p4 << endl;
	cout << p3 + hours(3) << endl;
	cout << to_simple_string(p3) << endl;

	//ʱ������
	time_period tp(p4, hours(8));
	tp.shift(hours(2));
	cout << tp.length() << endl << tp.begin().date() << endl;

	//ʱ�������
	for (time_iterator t_iter(p1, minutes(10)); t_iter < p1 + hours(1);
			++t_iter) {
		cout << *t_iter << endl;
	}
}
