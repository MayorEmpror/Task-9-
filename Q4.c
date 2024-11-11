#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

struct data_base{
    char student_name[MAX_LEN][MAX_LEN];
    int student_age[10];
    char student_gender[10];
};
void name_data_base_search(){
   struct data_base Students = {
        .student_name = {
            "Hashir", "Ali", "David", "Anderson", "Micheal"
        },
        .student_age = {
            19,18,19,19,18
        },
        .student_gender ={
            'M','M','M','M','M'
        },
    };

char name_input[MAX_LEN];
printf("Enter your name : ");
fgets(name_input,MAX_LEN,stdin);
 name_input[strcspn(name_input, "\n")] = 0;

int found = 0;
int index_ = 0;
for(int i = 0;i<=5;i++){
    if(strcmp(name_input,Students.student_name[i]) == 0){
        found = 1; 
        index_ = i;
    }
}
if(found==1){
   printf("\033[34mRecord found\033[0m\n");
   printf("Name   : %s \n",Students.student_name[index_]);
   printf("Age    : %d \n",Students.student_age[index_]);
   printf("Gender : %c \n",Students.student_gender[index_]);
}else printf("\033[31m Record Not found\033[0m\n");
}

int main(){
    name_data_base_search();
    return 0;
}