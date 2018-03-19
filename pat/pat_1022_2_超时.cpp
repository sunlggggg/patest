/**
1022. Digital Library (30)
时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:

For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.

Sample Input:
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
Sample Output:
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
**/

#include<iostream>
#include<map>
#include<set>
#include<sstream>
using namespace std;
map<string , set<int>> mpTitle , mpAuthor, mpKey , mpPub , mpYear;
void query(map<string,set<int>> mp, string tmp){
	if(mp.find(tmp)==mp.end()){
		printf("Not Found\n");
	}else {
		for(set<int>::iterator it = mp[tmp].begin();it!=mp[tmp].end();it++){
			printf("%07d\n",*it);
		}
	}
}
int main(){
	int n ;
	scanf("%d",&n);
	int id;
	string title,author,key , pub, year;
	for(int i = 0; i< n ; i++){
		scanf("%d",&id);
		getchar();
		getline(cin,title);
		mpTitle[title].insert(id);
		getline(cin,author);
		mpAuthor[author].insert(id);
		char t;
		key="";
		while((t =getchar())){
			if(t == '\n'){
				mpKey[key].insert(id);
				break;
			}
			else if(t != ' '){
				key+=t;
			} else {
				mpKey[key].insert(id);
				key = "";
			}
		}
		getline(cin,pub);
		mpPub[pub].insert(id);
		getline(cin,year);
		mpYear[year].insert(id);
	}
	string tmp;
	int m ;
	int type;
	scanf("%d",&m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d: ",&type);
		getline(cin,tmp);
		printf("%d: ^\n",*it);
		cout<<type<<": "<<tmp<<endl;
		if(type == 1)query(mpTitle,tmp);
		else if(type == 2) query(mpAuthor,tmp);
		else if(type == 3)query(mpKey,tmp);
		else if(type == 4)query(mpPub,tmp);
		else query(mpYear,tmp);
	}
	return 0;
}