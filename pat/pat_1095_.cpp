//查询时间有序
//char * 是地址 有时候需要拷贝 
//.c_str(); %s 

#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct T{
	int h,m,s;
};
struct A{
	A(){ispair = 0 ;}
	int ispair; //0 no 1 in 2 out 
	char n[8];
	bool f; //true in false out
	T t;
};
A as[10010];
A as_paired[10010];
struct ptrCmp
{
    bool operator()( const char * s1, const char * s2 ) const
    {
        return strcmp( s1, s2 ) < 0;
    }
};
bool cmp(A a, A b){
	int c = strcmp(a.n,b.n);
	if(c) return c < 0 ;
	else if(a.t.h != b.t.h ) return a.t.h < b.t.h;
	else if(a.t.m != b.t.m ) return a.t.m < b.t.m ; 
	else return a.t.s < b.t.s; 
}
bool cmpT(A a, A b){
	if(a.t.h != b.t.h ) return a.t.h < b.t.h;
	else if(a.t.m != b.t.m ) return a.t.m < b.t.m ; 
	else return a.t.s < b.t.s; 
}
bool cmpMap(pair<char * , int > a ,pair<char * , int >  b){
	if(a.second!=b.second)
		return a.second > b.second;
	else{
		int c=strcmp(a.first,b.first);
		return c<0;
	}
}
int cT(T t1 ){ 
	return (t1.h  ) * 60*60 + (t1.m )*60 + (t1.s) ;
}
int cT(T t1, T t2 ){ 
	return (t1.h - t2.h ) * 60*60 + (t1.m - t2.m)*60 + (t1.s - t2.s) ;
}

void pT(int t, T *rt){
	rt->s= t%60;
	t/=60;
	rt->m = t%60;
	t/=60;
	rt->h = t%60;
}
int main(){
	
	int n , m ;
	scanf("%d%d",&n,&m ); 
	for(int i = 0 ; i< n ; i++){
		char t[4];
		A a;
		scanf("%s%d:%d:%d%s",a.n,&a.t.h,&a.t.m,&a.t.s,t);
		if(!strcmp(t,"in")) a.f = true;
		else a.f = false;
		as[i]= a;
	}
	sort(as,as+n ,cmp);
	//compute the max
	map<char*,int,ptrCmp> ma;
	map<char*,int,ptrCmp>::iterator mt;
	//delete no paired 
	A *pre = &as[0]; 
	for(int i = 1 ; i< n ; i++ ){
		if(!strcmp(as[i].n,pre->n) && as[i].f == false && pre->f == true){
			int t = cT(as[i].t,pre->t);
			if((mt = ma.find(as[i].n))!=ma.end()){
				mt->second +=t;
			}else {
				char *s = new char[8];
				strcpy(s,as[i].n);
				ma.insert(make_pair(s, t));
			}
			pre->ispair = 1;
			as[i].ispair = 2;
		}
		pre = &as[i];
	}
	sort(as,as+n ,cmpT); //根据时间排序 会打乱map的顺序。。。。char * strcpy进行复制
	int nowCount = 0 ;
	int k = 0 ;
	for(int i  = 0 ;i< m; i++){
		T t_;
		scanf("%d:%d:%d",&t_.h,&t_.m,&t_.s);
		for(; k< n ; k++ ){
			if(cT(as[k].t) <= cT(t_)){
				if(as[k].ispair == 1)  nowCount++;
				else if(as[k].ispair == 2) nowCount--;
			}
			else break;
		}
		printf("%d\n",nowCount);
	}
	if(ma.size() == 0 ){
		return 0 ;
	}

	vector<pair<char *,int>> vmap (ma.begin(),ma.end());
	sort(vmap.begin(),vmap.end(),cmpMap);
	int t_max = vmap[0].second ; 
	printf("%s ", vmap[0].first );
	for(int i = 1; i < vmap.size(); i++ ){
		if(vmap[i].second == vmap[0].second  )
			printf("%s ", vmap[i].first );
	}
	T *rt = new T;
	pT(vmap[0].second,rt);
	printf("%02d:%02d:%02d", rt->h,rt->m,rt->s);
	return 0 ;
}

