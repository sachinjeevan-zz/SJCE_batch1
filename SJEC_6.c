#include<stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main()
{
  char str[1000];
  scanf("%s",str);
  int len=0;
  while(str[len]!='\0'){
      len++;
  } 
  int dp[len][len];
  for(int i=0;i<len;i++){
      for(int j=0;j<len;j++){
          dp[i][j]=0;
          if(i==j){
              dp[i][j]=1;
          }
         
      }
  }
  int i=0,j=1,k=1;
  while(1){
      i=0;
      j=k;
      if(j-i==len){
          break;
      }
      while(j<len){
          if(j-i==1){
              if(str[i]==str[j]){
                  dp[i][j]=2;
              }
              else{
                  dp[i][j]=1;
              }
          }
          else{
              if(str[i]==str[j]){
                  dp[i][j]=dp[i+1][j-1]+2;
              }
              else{
                  dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
              }
          }
          i++;
          j++;


      }
      k++;
  }
  for(int i=0;i<len;i++){
      for(int j=0;j<len;j++){
          printf("%d ",dp[i][j]);
      }
      printf("\n");
  }
  i=0;
  j=len-1;
  char res[1000];
  k=0;
  while(i<=j){
      if(str[i]==str[j]){
          res[k]=str[i];
          k++;
i++;
j--;
      }
      else{
          if(dp[i][j-1]>=dp[i+1][j]){
              j--;
          }
          else{
              i++;
          }
      }
  }
  int temp=k;
  if(dp[0][len-1]%2==0){
      temp=k-1;
      while(temp>=0){
          res[k]=res[temp];
          k++;
          temp--;
      }res[k]='\0';
  }
  else{
      temp=k-2;
      while(temp>=0){
          res[k]=res[temp];
          k++;
          temp--;
      }res[k]='\0';
  }
  printf("%s",res);
}