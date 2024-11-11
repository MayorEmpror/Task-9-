#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100
void num_printer(){
  int num = 0;
    printf("enter numbers");
    scanf("%d",&num);
    int k = 1;
    int counter = 1;
    for(int i =1;i<=num;i++){
        k = 1;
       if(i%2 != 0){
            for(int j =1;j<=i;j++){
                    printf("%d",k);
                     if(j>=counter){
                     k -= 1; 
                    }else k +=1 ;
                 }
           }else num += 1;
           if(i%2 != 0){
           printf("\n");
           counter+= 1;
     }
   
    }
}
int main(){
   num_printer();
   return 0;
}