#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100
void pattern(){
    int num = 0;
printf("enter number of rows");
     scanf("%d",&num);
     num -= 2;
     for(int i =num+2;i>0;i--){
      for(int j=i;j>0;j--){
      printf(". ");
}
for(int j=num-i+2;j>=0;j--){
      printf("o");
}
printf("\n");
 
}
for(int i =0;i<num+3;i++){
      for(int j=i;j>0;j--){
      printf(". ");
}
for(int j=num-i+2;j>=0;j--){
      printf("o");
}
printf("\n");
 
}
}

int main(){
    pattern();
    return 0;
}