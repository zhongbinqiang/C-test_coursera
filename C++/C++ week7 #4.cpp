#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;
string a[20];
int sn;
string s_operator(string&);
string find_string(string &);
int main(){
	cin>>sn;
	for(int i = 0; i < sn; i++){
		cin>>a[i];
	}
	cin.ignore();
	string sop;
	while(true){
		getline(cin,sop);
		if(sop == "over") break;
		s_operator(sop);
	}
	return 0;
}
string find_string(string &s){
	string str;
	int i;
	for(i = 0; i<s.length(); i++){
		if(s.at(i) != ' '){
			str.push_back(s.at(i));
		} else break;
	}
	if(i != s.length()) s = s.substr(i+1,s.length()-i-1);
	return str;
}
string findop(string sf, int n){
	int pos = a[n-1].find(sf);
	char array[100];
	if(pos != string::npos){
		sprintf(array,"%d",pos);
	}
	else{
		sprintf(array,"%d",sf.length());
	} 
	return array;
}
string rfindop(string sf, int n){
	int pos = a[n-1].rfind(sf);
	char array[100];
	if(pos != string::npos){
		sprintf(array,"%d",pos);
	}
	else{
		sprintf(array,"%d",sf.length());
	} 
	return array;
}
string addop(string s1, string s2){
	for(int i = 0; i<s1.length(); i++){
		if(s1.at(i)<'0' || s1.at(i)>'9'){
			return s1+s2;
		}
	}
	for(int i = 0; i<s2.length(); i++){
		if(s2.at(i)<'0' || s2.at(i)>'9'){
			return s1+s2;
		}
	}
	long a = atoi(s1.c_str());
	long b = atoi(s2.c_str());
	if(a>=0 && a<=99999 && b>=0 && b<=99999){
		long c = a+b;
		char array[100];
		sprintf(array,"%d",c);
		return array;
	}else return s1+s2;
}
string copyop(int n, int x, int l){
	return a[n-1].substr(x,l);
}
string s_operator(string& s){
	string str;
	str = find_string(s);
	if(str == "printall"){
		for(int i = 0; i < sn; i++){
			cout<<a[i]<<endl;
		}
	}else if(str == "print"){
		int n = atoi(s_operator(s).c_str());
		cout<<a[n-1]<<endl;
	}else if(str == "reset"){
		string s1 = s_operator(s);
		//cout<<"reset s ="<<s1<<endl;//debug
		int n = atoi(s_operator(s).c_str());
		//cout<<"reset n="<<n<<endl;//debug
		a[n-1] = s1;
	}else if(str == "insert"){
		string s1 = s_operator(s);
		int n = atoi(s_operator(s).c_str());
		int x = atoi(s_operator(s).c_str());
		a[n-1].insert(x,s1);
	}else if(str == "rfind"){
		string s1 = s_operator(s);
		int n = atoi(s_operator(s).c_str());
		return rfindop(s1,n);
	}else if(str == "find"){
		string s1 = s_operator(s);
		int n = atoi(s_operator(s).c_str());
		return findop(s1,n);
	}else if(str == "add"){
		string s1 = s_operator(s);
		string s2 = s_operator(s);
		return addop(s1,s2);
	}else if(str == "copy"){
		int n = atoi(s_operator(s).c_str());
		int x = atoi(s_operator(s).c_str());
		int l = atoi(s_operator(s).c_str());
		return copyop(n,x,l);
	}else return str;
	return s;
}
