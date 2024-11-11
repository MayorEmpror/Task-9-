#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

struct Lock {
   char master[MAX_LEN];
    char username[MAX_LEN];
    int key;
    int password;
};
void lock(char master[],int key,int password,char username[]){
     if(strcasecmp(master,username)==0){
        if(password == key){
            printf("\033[32mAccess granted\033[0m");
        } else printf("Access denied");
     }else printf("\033[31mAccess denied\033[0m");
}
void key_hole(){
    struct Lock initails;
    strcpy(initails.master,"admin");
    initails.key =1234;
    
    printf("enter username ");
    scanf("%s",initails.username);
    printf("entre password ");
    scanf("%d",&initails.password);
    lock(initails.master,initails.key,initails.password,initails.username);
}

int main(){
    key_hole();
    return 0;
}