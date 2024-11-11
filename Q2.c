#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100
void order(){
    int bolts,nuts,washers,total;
    char message[MAX_LEN] = "The order is OK";
    printf("enter number of bolts  ");
    scanf("%d",&bolts);
    printf("enter number of nuts  ");
    scanf("%d",&nuts);
    printf("enter number of washers  ");
    scanf("%d",&washers);

    if(nuts >= bolts ){
        if(2*washers > bolts){
             strcpy(message,"order is OK\n");
        }else strcpy(message,"washers are not twice as many as bolts\n");
    }else{
        strcpy(message,"nuts are less than bolts\n");
    }
   total  = (5*bolts ) + (1 * washers) + (3*nuts);
   printf("Check the order \t%s", message);
   printf("total cost is %d\n",total);



}
int main(){
    order();
    return 0;
}