/**
1137. Final Grading (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
For a student taking the online course "Data Structures" on China University MOOC (http://www.icourse163.org/), to be qualified for a certificate, he/
she must first obtain no less than 200 points from the online programming assignments, and then receive a final grade no less than 60 out of 100. The 
final grade is calculated by G = (Gmid-termx 40% + Gfinalx 60%) if Gmid-term > Gfinal, or Gfinal will be taken as the final grade G. Here Gmid-term and
Gfinal are the student's scores of the mid-term and the final exams, respectively.

The problem is that different exams have different grading sheets. Your job is to write a program to merge all the grading sheets into one.

Input Specification:

Each input file contains one test case. For each case, the first line gives three positive integers: P , the number of students having done the online 
programming assignments; M, the number of students on the mid-term list; and N, the number of students on the final exam list. All the numbers are no 
more than 10,000.

Then three blocks follow. The first block contains P online programming scores Gp's; the second one contains M mid-term scores Gmid-term's; and the 
last one contains N final exam scores Gfinal's. Each score occupies a line with the format: StudentID Score, where StudentID is a string of no more 
than 20 English letters and digits, and Score is a nonnegative integer (the maximum score of the online programming is 900, and that of the mid-term 
and final exams is 100).

Output Specification:

For each case, print the list of students who are qualified for certificates. Each student occupies a line with the format:

StudentID Gp Gmid-term Gfinal G

If some score does not exist, output "-1" instead. The output must be sorted in descending order of their final grades (G must be rounded up to an 
integer). If there is a tie, output in ascending order of their StudentID's. It is guaranteed that the StudentID's are all distinct, and there is at 
least one qualified student.

Sample Input:
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400

ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39

ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
Sample Output:

missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
**/
//1:四舍五入
//2:stringstream 清除缓冲区 .str("");
//最后一次可能没有考试
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
struct A{
	A(){
		stringstream ssm;
		ssm.str("");
		com = qm = qz =  -1;
		final = -1;
	}
	char name[50];
	int com;
	int qm;
	int qz;
	int final;
};
int mround(double a){
	if(a*2 - int(a) - int(a) > 1){
		return int(a) +1;
	}
	return int(a);
}
int mmround(double number)
{
    return (number > 0.0) ? floor(number + 0.5) : ceil(number - 0.5);
}
bool cmp(pair<string ,A> a, pair<string , A> b){
	if(a.second.final != b.second.final )
		return a.second.final > b.second.final ;
	else 
		return a.first<b.first;
}
int main(){
	int n1,n2,n3;
	scanf("%d%d%d",&n1,&n2,&n3);
	map<string,A> m;
	stringstream ssm;
	ssm.clear();
	map<string,A>::iterator mt;
	for(int i = 0 ; i < n1; i++){
		char t[50];
		int ttt;
		scanf("%s%d",&t,&ttt);
		if(ttt>=200&&ttt<=900){
			A a ; 
			strcpy(a.name,t);
			a.com = ttt;
			m.insert(make_pair(string(a.name),a));
		}
	}
	for(int i = 0 ; i < n2; i++){
		char t[50];
		int qz;
		scanf("%s%d",&t,&qz);
		string name(t);
		mt = m.find(name);
		if(mt!=m.end()){
			mt->second.qz = qz;
		}
	}
	//he must first obtain no less than 200 points from the online programming assignments,
	//and then receive a final grade no less than 60 out of 100. The 
	//final grade is calculated by G = (Gmid-termx 40% + Gfinalx 60%) if Gmid-term > Gfinal,
	//or Gfinal will be taken as the final grade G. Here Gmid-term and
	//Gfinal are the student's scores of the mid-term and the final exams, respectively.
	for(int i = 0 ; i < n3; i++){
		char t[50];
		int qm;
		scanf("%s%d",&t,&qm);
		string name(t);
		mt = m.find(name);
		if(mt!=m.end()){
			mt->second.qm = qm;
			if(mt->second.qz > qm){
				//四舍五入
					mt->second.final = int(mt->second.qz*0.4+mt->second.qm*0.6 + 0.5);
			}else {
				mt->second.final = mt->second.qm;
			}
			if(mt->second.final < 60 || mt->second.final > 100){
				m.erase(mt);//删除...
			}
		}
	}
	//sort
	vector<pair<string , A>> v(m.begin(),m.end());
	sort(v.begin(),v.end(),cmp);
	//输出
	for(int i = 0 ; i < v.size(); i++){
		if(v[i].second.qm!=-1)
			printf("%s %d %d %d %d\n",v[i].first.c_str(),v[i].second.com,v[i].second.qz,v[i].second.qm,v[i].second.final);
	}
	return 0;
}