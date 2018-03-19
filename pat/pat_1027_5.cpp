#include<iostream>
#include<deque>
using namespace std;
char cs[4] ={'A','B','C'};
deque<char> f(int a ){
	deque<char> s ; 
	int t = a%13;
	if(t<10)
		s.push_front(char('0'+t));
	else {
		s.push_front(cs[t-10]);
	}
	a/=13;
	t = a%13;
	if(t<10)
		s.push_front(char('0'+t));
	else {
		s.push_front(cs[t-10]);
	}
	return s ;
}
void p(deque<char> q){
	for(int i = 0 ; i< q.size();i++){
		cout<<q[i];
	}
}
int main(){
	int a , b, c; 
	cin >> a >> b >> c;
	
	cout<<"#";
	p(f(a));p(f(b));p(f(c));
	return 0 ;
}
/**

Sample Input
15 43 71
Sample Output
#123456

*/