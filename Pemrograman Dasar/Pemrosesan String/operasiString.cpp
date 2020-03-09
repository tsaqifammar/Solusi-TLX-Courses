#include<iostream>
#include<string>
using namespace std;

int main(){
	string s1, s2, s3, s4;
	
	cin >> s1 >> s2 >> s3 >> s4;
	int len2 = s2.size();
	
	int posisi = s1.find(s2);
	s1.erase(posisi, len2);
	
	int len3 = s3.size();
	int pos = s1.find(s3);
	s1.insert(pos+len3, s4);
	cout << s1 << endl;
}
