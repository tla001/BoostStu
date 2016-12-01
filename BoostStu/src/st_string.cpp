/*
 * st_string.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: tla001
 */

#include "st_string.h"

void Ttrans()
{
	int x=lexical_cast<int>("100");
	long y=lexical_cast<long>("2000");
	float pai=lexical_cast<float>("3.14159e5");
	double e=lexical_cast<double>("2.71828");
	cout<<x<<"\t"<<y<<"\t"<<pai<<"\t"<<e<<endl;
	try{
		cout<<lexical_cast<int>("0x100");
		cout<<lexical_cast<bool>("fasle");
		cout<<lexical_cast<double>("helloworld");
	}
	catch(bad_lexical_cast &e){
		cout<<"error:"<<e.what()<<endl;
	}
}
void Tformat()
{
	cout<<format("%s:%d+%d=%d\n")%"sum" % 1 % 2 % (1+2);
	format fmt("(%1%+%2%)*%2%=%3%\n");
	fmt %2 % 5;
	fmt % ((2+5)*5);
	cout<<fmt.str()<<endl;
}
void Tstringalgo()
{
	string str("readme.txt");
	if(ends_with(str,"txt")){
		cout<<to_upper_copy(str)+" UPPER"<<endl;
		assert(ends_with(str,"txt"));
	}
	replace_first(str,"readme","followme");
	cout<<str<<endl;

	vector<char> v(str.begin(),str.end());
	vector<char> v2=to_upper_copy(erase_first_copy(v,"txt"));
	for(int i=0;i<v2.size();i++){
		cout<<v2[i];
	}
}
void Ttokennizer()
{
	//Ä¬ÈÏÄ£°å
	string str("Link raise the master_sword.");
	tokenizer<> tok(str);
	for(tokenizer<>::iterator pos=tok.begin();pos!=tok.end();++pos){
		cout<<"["<<*pos<<"]";
	}
	cout<<endl;

	//×Ö·û¼¯ºÏ·Ö´Ê
	char *str1="Link ;; <master-sword> zalda";
	char_separator<char> sep;
	tokenizer<char_separator<char>,char *> tok1(str1,str1+strlen(str1),sep);
	for(tokenizer<char_separator<char>,char *> ::iterator pos=tok1.begin();pos!=tok1.end();++pos){
		cout<<"["<<*pos<<"]";
	}
	cout<<endl;
	tok1.assign(str1,str1+strlen(str1));
	char_separator<char>(" ;-","<>");
	for(tokenizer<char_separator<char>,char *> ::iterator pos=tok1.begin();pos!=tok1.end();++pos){
		cout<<"["<<*pos<<"]";
	}
	cout<<endl;
	//¶ººÅ·Ö¸ô·û
	string str2="id,100,name,\"marico\"";
	escaped_list_separator<char> sep2;
	tokenizer<escaped_list_separator<char> > tok2(str2,sep2);
	for(tokenizer<escaped_list_separator<char> > ::iterator pos=tok2.begin();pos!=tok2.end();++pos){
		cout<<"["<<*pos<<"]";
	}
	cout<<endl;
	//Æ«ÒÆÁ¿·Ö´Ê
	string str3="2233344445";
	int offsets[]={2,3,4};
	offset_separator sep3(offsets,offsets+3,true,false);
	tokenizer<offset_separator> tok3(str3,sep3);
	for(tokenizer<offset_separator> ::iterator pos=tok3.begin();pos!=tok3.end();++pos){
		cout<<"["<<*pos<<"]";
	}
	cout<<endl;
}
void Txpressive()
{
	cregex reg=cregex::compile("a.c");
	assert(regex_match("abc",reg));
//	cregex reg1=cregex::compile("\\d{6}((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))",icase);
//	xpressive::cmatch what;
//	assert(regex_match("99955519701019999",what,reg1));
//	for(xpressive::cmatch::iterator pos=what.begin();pos!=what.end();++pos){
//		cout<<endl;
//		cout<<"date:"<<what[1]<<what[3]<<what[5]<<endl;
//	}
	//²éÕÒ
	char * str="there is a POWER-suit item";
	cregex reg2=cregex::compile("(power)-(.{4})",icase);
	assert(regex_search(str,reg2));
	xpressive::cmatch what1;
	regex_search(str,what1,reg2);
	assert(what1.size()==3);
	cout<<what1[1]<<what1[2]<<endl;
	//Ìæ»»
	string str2("readme.txt");
	sregex reg3=sregex::compile("(.*)(me)");
	cout<<regex_replace(str2,reg3,"manual")<<endl;
	cout<<regex_replace(str2,reg3,"$1you")<<endl;
	//µü´úÆ÷
	string str3("Power-bomb,power-suit, pOWER-beam all items\n");
	sregex reg4=sregex::compile("power-(\\w{4})",icase);

	xpressive::sregex_iterator pos1(str3.begin(),str3.end(),reg4);
	xpressive::sregex_iterator end;
	while(pos1!=end){
		cout<<"["<<(*pos1)[0]<<"]";
		++pos1;
	}
	cout<<endl;
}
