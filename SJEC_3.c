#include<stdio.h>
int main()
{
    int fn1,fn2,fn,n;
    scanf("%d",&n);
    fn2=2;
    fn1=8;
    printf("%d %d ",fn2,fn1);
    fn=4*fn1+fn2;
    while(fn<=n){
        printf("%d ",fn);
        fn2=fn1;
        fn1=fn;
        fn=4*fn1+fn2;
    }
    

}