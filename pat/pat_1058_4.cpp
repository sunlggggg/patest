#include<iostream>
#include<cstdio>
using namespace std;
struct A{
	int a;//[0,10^7]
	int b;//[0,17)
	int c;//[0,29) 
};
int main(){
	while(1)
	{
		ios::sync_with_stdio(false);
		A a ,b; 
		scanf("%d.%d.%d",&a.a,&a.b,&a.c);
		scanf("%d.%d.%d",&b.a,&b.b,&b.c);
		if(a.c+b.c>28){
			a.c = a.c+b.c -29 ;
			a.b+=1;
		}else{
			a.c = a.c+b.c;
		}

		if(a.b+b.b > 16){
			a.b = a.b+b.b - 17 ;
			a.a+=1;
		}else{
			a.b = a.b+b.b;
		}
		a.a = a.a+b.a;
		cout<<a.a<<'.'<<a.b<<'.'<<a.c<<endl;
		return 0;
	}
}