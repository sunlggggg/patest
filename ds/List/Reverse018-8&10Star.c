#include<stdio.h>

void Reverse (int Seq[], int from , int to ){
    int tmp;
    //[watch out] the value '(to - from + 1 )/2'
    for(int i = 0; i <= (to - from + 1 )/2 ; i++ ){
        tmp = Seq[from + i];
        Seq[ from+ i ] = Seq[to - i ];
        Seq[to-i ] = tmp ;
    }
}
void Converse(int Seq[], int n , int p ){
    Reverse(Seq,0, p-1) ;
    Reverse(Seq,p, n-1) ;
    Reverse(Seq,0, n-1) ;

}
int main(){
    int Seq[] = {1,2,3,4,5,6,7,8,9};
    Converse(Seq, 9 , 5) ;
    int a = 0 ;
    printf("%d",sizeof(a));
    return 0 ;
}