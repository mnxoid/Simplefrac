//(c) Mnxoid - All rights reserved
//----------Include section-------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cstring>
//----------Definitions-----------------------------------
#define eof 27
#define maxline 1000
//----------Declarations----------------------------------
using namespace std;
//----------Classes---------------------------------------
class odnochlen
 {
  private:
  public:
	double koef;
	int step;
  protected:
 };
class mnogochlen
 {
  private:
	odnochlen clear;
  public:
	odnochlen odnos[100];
	int maxstep;
	void init()
	 {
		maxstep=0;
		clear.koef=0.0;
		clear.step=0;
		int i;
		for (i=0;i<101;i++) {
			odnos[i]=clear;
		}
	 }
	void addodn(odnochlen odn)
	 {
		odnos[odn.step].koef=odnos[odn.step].koef+odn.koef;
		odnos[odn.step].step=odn.step;
		if (odn.step > maxstep) { maxstep=odn.step; }
	 }
  protected:
 };
class duzhka
 {
  private:
  public:
	mnogochlen mnog;
	int step;
  protected:
 };
class znamennyk
 {
  private:
  public:
	duzhka duzky[5];
	void init()
	 {
		int i;
		for (i=0;i<6;i++) { duzky[i].step=0; }
	 }
	int maxstep()
	 {
		int i,s;
		s=0;
		for (i=0;i<6;i++)
		 {
			s=s+duzky[i].mnog.maxstep*duzky[i].step;
		 }
		return s;
	 }
  protected:
 };
class drib
 {
  private:
  public:
	mnogochlen chys;
	znamennyk znam;
	bool valid()
	 {
		if (znam.maxstep()>chys.maxstep)
		 {
			return true;
		 } else {
			return false;
		 }
	 }
  protected:
 };
//----------Utility functions-----------------------------
int getline(char s[],int lim)
 {
	int c,i;
	for(i=0; i<lim-1 && (c=getchar()) != eof && c != '\n'; i++)
	 s[i]=c;
	 s[i]='\0';
	 i++;
	return(i);
 }
int getch()
 {
	char i[maxline];
	return(getline(i, maxline));
 }
void odnochlen_mul(odnochlen& recp, odnochlen mul)
 {
	recp.koef=recp.koef*mul.koef;
	recp.step=recp.step+mul.step;
 }
void odnochlen_out(odnochlen a)
 {
	cout << "The odnochlen is: " << a.koef << "*x^" << a.step << endl;
 }
void odnochlen_in(odnochlen& a,char str[256] = "This string was made by mnxoid just for lulz!")
 {
	char s[256];
	char k[20];
	char st[20];
	int i,j,n;
	for (i=0;i<257;i++) s[i]='\0';
	for (i=0;i<21;i++) k[i]='\0';
	for (i=0;i<21;i++) st[i]='\0';
	if (str == "This string was made by mnxoid just for lulz!") {
		n=getline(s,maxline);
	 } else {
		for (i=0;i<256;i++) { s[i]=str[i]; }
	 }
	i=0;j=0;
	if (s[i]=='x')
	 {
		i+=2;
		if (s[i]=='\0')
		 {
			a.koef=1;
			a.step=1;
		 } else {
			while (s[i] != '\0') {st[j]=s[i];i++;j++;}
			a.koef=1;
			a.step=atoi(st);
		 }
	 } else {
		while ((s[i] != 'x') && (s[i] != '\0')) {k[j]=s[i];i++;j++;}
		if (s[i] == '\0')
		 {
			a.koef=atof(k);
			a.step=0;
		 } else if (s[i+1]=='\0') {
			a.koef=atof(k);
			a.step=1;
		 } else {
			i+=2;
			j=0;
			while (s[i] != '\0') {st[j]=s[i];i++;j++;}
			a.koef=atof(k);
			a.step=atoi(st);
		 }
	 }
 }
void mnogochlen_out(mnogochlen a,bool silent)
 {
	int i;
	if (!silent) { cout << "The mnogochlen is: "; }
	for (i=a.maxstep;i>-1;i--)
	 {
		if (a.odnos[i].koef != 0)
		 {
			if (i==a.maxstep) 
			 {
				if ((i != 0) and (i != 1))
				 {
					if (a.odnos[i].koef != 1)
					 {
						cout << a.odnos[i].koef << "*x^" << a.odnos[i].step;
					 } else {
						cout << "x^" << a.odnos[i].step;
					 }
				 } else if (i==1) {
					if (a.odnos[i].koef != 1)
					 {
						cout << a.odnos[i].koef << "*x";
					 } else {
						cout << "x";
					 }
				 } else {
					cout << a.odnos[i].koef;
				 }
			 } else {
				if ((i != 0) and (i != 1))
				 {
					if (a.odnos[i].koef != 1)
					 {
						cout << " + " << a.odnos[i].koef << "*x^" << a.odnos[i].step;
					 } else {
						cout << " + " << "x^" << a.odnos[i].step;
					 }
				 } else if (i==1) {
					if (a.odnos[i].koef != 1)
					 {
						cout << " + " << a.odnos[i].koef << "*x";
					 } else {
						cout << " + " << "x";
					 }
				 } else {
					cout << " + " << a.odnos[i].koef;
				 }			 }
		 }
	 }
	if (!silent) { cout << endl; }
 }
void mnogochlen_add(mnogochlen& recv,mnogochlen dod)
 {
	int i;
	for (i=dod.maxstep;i>-1;i--)
	 {
		recv.addodn(dod.odnos[i]);
	 }
 }
void mnogochlen_mul(mnogochlen& recv,mnogochlen a,mnogochlen b)
 {
	int i;
	recv.init();
	for (i=b.maxstep;i>-1;i--)
	 {
		odnochlen to;
		int j;
		for (j=a.maxstep;j>-1;j--)
		 {
			to=a.odnos[j];
			odnochlen_mul(to,b.odnos[i]);
			recv.addodn(to);
		 }
	 }
 }
bool mnogochlen_compare(mnogochlen a,mnogochlen b)
 {
	int err,i;
	err=0;
	//for (i=0;i<101;i++) {
		streambuf *backup = cout.rdbuf();			//
		stringstream sout1;					//
		streambuf *soutbuf1 = sout1.rdbuf();			//	Special thx to:
		cout.rdbuf(soutbuf1);					//
		stringstream sout2;					//	    Kwizatz
		mnogochlen_out(a,true);					//
		streambuf *soutbuf2 = sout2.rdbuf();			// for posting a question on gamedev.net
		cout.rdbuf(soutbuf2);					//      about redirecting streams.
		mnogochlen_out(b,true);					//
		if (sout1.str() != sout2.str()) err++;
		//if (a.odnos[i].koef != b.odnos[i].koef) err++;
		//if (a.odnos[i].step != b.odnos[i].step) err++;
		cout.rdbuf(backup);
	//}
	if (err==0) return true; else return false;
 }
void mnogochlen_in(mnogochlen& a,char str[256] = "This string was made by mnxoid just for lulz!")
 {
	char s[256];
	int i,j,n;
	if (str == "This string was made by mnxoid just for lulz!") {
		n=getline(s,maxline);n=0;
	 } else {
		for (i=0;i<256;i++) { s[i]=str[i]; }
		n=0;
	 }
	string stri[50];
	stri[0]="";
	i=0;j=0;
	n=1;
	while (s[i] != '\0')
	 {
		if (((s[i]=='+') || (s[i]=='-')) && (i!=0))
		 {
			j++;stri[j]="";stri[j] += string(1,s[i]);i++;n++;
		 } else {
			stri[j] += string(1,s[i]);i++;
		 }
	 }
	for (i=0;i<n+1;i++) {
		odnochlen b;
		char temp[256];
		strcpy(temp,stri[i].c_str());
		b.koef=0;
		b.step=0;
		odnochlen_in(b,temp);
		a.addodn(b);
	 }
 }
void duzhka_open(mnogochlen& recv,duzhka src)
 {
	int i;
	recv.init();
	mnogochlen temp;
	temp.init();
	temp=src.mnog;
	for (i=src.step-1;i>0;i--)
	 {
		mnogochlen k;
		k=temp;
		mnogochlen_mul(temp,k,src.mnog);
	 }
	recv=temp;
 }
void duzhka_openvisual(duzhka d)
 {
	cout << "(";
	mnogochlen_out(d.mnog,true);
	cout << ")^" << d.step << " = ";
	mnogochlen s;
	s.init();
	duzhka_open(s,d);
	mnogochlen_out(s,true);
	cout << endl;	
 }
void znamennyk_sub(znamennyk& recv,znamennyk big,znamennyk small)
 {
	int i,k;
	recv.init();
	k=0;
	bool found;
	found=false;
	for (i=0;i<6;i++)
	 {
		int j;
		for(j=0;j<6;j++)
		 {
			bool tmpb;
			//mnogochlen_out(big.duzky[i].mnog,false);
			//mnogochlen_out(small.duzky[j].mnog,false);
			tmpb=mnogochlen_compare(big.duzky[i].mnog,small.duzky[j].mnog);
			if (tmpb)
			 {
				found=true;
				//cout << big.duzky[i].step << " - " << small.duzky[j].step;
				//cout << " = " << big.duzky[i].step-small.duzky[j].step << endl;
				if (big.duzky[i].step-small.duzky[j].step > 0)
				 {
					recv.duzky[k].mnog=big.duzky[i].mnog;
					recv.duzky[k].step=big.duzky[i].step-small.duzky[i].step;
					k++;
				 }
			 }
		 }
		if (!found)
		 {
			recv.duzky[k]=big.duzky[i];
			k++;
		 }
	 }
 }
void znamennyk_out(znamennyk z)
 {
	int i;
	for (i=0;i<6;i++)
	 {
		if (z.duzky[i].step>1) {
		cout << "(";
		mnogochlen_out(z.duzky[i].mnog,true);
		cout << ")^" << z.duzky[i].step;
		} else if (z.duzky[i].step==1) {
		cout << "(";
		mnogochlen_out(z.duzky[i].mnog,true);
		cout << ")"; }
	 }
	cout << endl;
 }
void znamennyk_in(znamennyk z,char str[256] = "This string was made by mnxoid just for lulz!")
 {
	char s[256];
	int i,j,n;
	if (str == "This string was made by mnxoid just for lulz!") {
		n=getline(s,maxline);n=0;
	 } else {
		for (i=0;i<256;i++) { s[i]=str[i]; }
		n=0;
	 }
	string stri[5];
	stri[0]="";
	string steps[5];
	steps[0]="";
	i=0;j=0;
	bool end,open,stepopen,first;
	end=false;
	open=false;
	stepopen=false;
	first=true;
	for (i=0;i<256;i++)
	 {
		if (end) {
			//do nothing
		 } else if (s[i]=='\0') {
			end=true; 
		 } else if (s[i]=='(') {
			if (first) {open=true;first=false;} else {j++;open=true;stepopen=false;}
			open=true;
		 } else if (s[i]==')') {
			open=false;
		 } else if (s[i]=='^') {
			stepopen=true;
		 } else if (stepopen) {
			steps[j] += string(1,s[i]);
		 } else if (open) {
			stri[j] += string(1,s[i]);
		 } else {
			cout << "error!" << endl;
		 }
		if (j==6) end=true;
	 }
	for (j=0;j<6;j++)
	 {
		char temp[256];
		strcpy(temp,stri[j].c_str());
		mnogochlen a;
		mnogochlen_in(a,temp);
		z.duzky[j].mnog=a;
		strcpy(temp,steps[j].c_str());
		if (steps[j]!="") {z.duzky[j].step=atoi(temp);} else {z.duzky[j].step=1;}
	 }
 }
//----------Main function---------------------------------
int main()
 {
	//this is the temporary testing part of the app, which will be commented in the future
	mnogochlen a;
	a.init();
	odnochlen o;
	o.koef=5.0;
	o.step=2;
	cout << "This is O" << endl;
	odnochlen_out(o);
	cout << "A=A+O" << endl;
	a.addodn(o);
	cout << "This is A.2" << endl;
	odnochlen_out(a.odnos[2]);
	o.koef=7.0;
	o.step=2;
	cout << "This is O" << endl;
	odnochlen_out(o);
	cout << "A=A+O" << endl;
	a.addodn(o);
	cout << "This is A.2" << endl;
	odnochlen_out(a.odnos[2]);
	odnochlen b;
	b.koef=3;
	b.step=5;
	cout << "This is B" << endl;
	odnochlen_out(b);
	cout << "O=O*B" << endl;
	odnochlen_mul(o,b);
	cout << "This is O" << endl;
	odnochlen_out(o);
	b.koef=4.6;
	b.step=0;
	cout << "A=A+B" << endl;
	a.addodn(b);
	cout << "This is A.0" << endl;
	odnochlen_out(a.odnos[0]);
	b.koef=3.1;
	cout << "A=A+B" << endl;
	a.addodn(b);
	cout << "This is B" << endl;
	odnochlen_out(b);
	cout << "This is A.0" << endl;
	odnochlen_out(a.odnos[0]);
	double a1,b1;
	a1=4.6;
	b1=3.1;
	b1=b1+a1;
	cout << b1 << endl;
	cout << a.maxstep << endl;
	cout << endl;
	mnogochlen_out(a,false);
	mnogochlen t1,t2,t3;
	t1.init();
	t2.init();
	b.koef=1;
	b.step=1;
	t1.addodn(b);
	b.step=0;
	t1.addodn(b);
	t2=t1;
	mnogochlen_out(t1,false);
	mnogochlen_out(t2,false);
	mnogochlen_mul(t3,t2,t1);
	mnogochlen_out(t3,false);
	cout << endl;
//duzhka testing
	duzhka d;
	d.mnog=a;
	d.step=2;
	duzhka_openvisual(d);
	d.step=3;
	duzhka_openvisual(d);
	d.mnog=t1;
	duzhka_openvisual(d);
//znamennyk substraction
	znamennyk znamb,znams,znamr;
	znamb.init();
	znams.init();
	znamr.init();
	t1.init();
	b.koef=2;
	b.step=1;
	t1.addodn(b);
	b.koef=1;
	b.step=0;
	t1.addodn(b);
	d.mnog=t1;
	d.step=3;
	znamb.duzky[1]=d;
//
	t1.init();
	b.koef=1;
	b.step=2;
	t1.addodn(b);
	b.koef=2;
	b.step=0;
	t1.addodn(b);
	d.mnog=t1;
	d.step=1;
	znamb.duzky[2]=d;
//
	t1.init();
	b.koef=2;
	b.step=1;
	t1.addodn(b);
	b.koef=1;
	b.step=0;                                     //TODO: Input mnogochlen/odnochlen/drib
	t1.addodn(b);
	d.mnog=t1;
	d.step=1;
	znams.duzky[1]=d;
//
	t1.init();
	b.koef=1;
	b.step=2;
	t1.addodn(b);
	b.koef=2;
	b.step=0;
	t1.addodn(b);
	d.mnog=t1;
	d.step=1;
	znams.duzky[2]=d;
	znamennyk_sub(znamr,znamb,znams);
	znamennyk_out(znamb);
	znamennyk_out(znams);
	znamennyk_out(znamr);
//the I/O part
	odnochlen_in(b);
	odnochlen_out(b);
	odnochlen_in(b,"2x^5\0");
	odnochlen_out(b);
//drib
	drib dr;
	dr.chys=a;
	dr.znam=znamb;
	mnogochlen_out(dr.chys,false);
	cout << a.maxstep << endl;
	znamennyk_out(dr.znam);
	cout << znamb.maxstep() << endl;
	cout << boolalpha << dr.valid() << noboolalpha << endl;// Special thx to : Nibu Thomas for posting this on ntcoder.com
//mnogochlen I/O
	a.init();
	mnogochlen_in(a);
	mnogochlen_out(a,false);
//znamennyk I/O
	znamb.init();
	znamennyk_in(znamb);
	znamennyk_out(znamb);
	//end of testing part put here a "* /" and a "/ *" in the start
	getch();
	return 0;
 }
//----------End of file-----------------------------------

