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



struct encoder_memory {
    char string[MAX_LEN];
    char key_input[MAX_LEN];
    char *ciphered_values;
    int *ASCII_string;
    int *Key_ascii;
    int *cipher;
    
};
void cipher(char string[],char key[]){
struct encoder_memory memo;
strcpy(memo.string,string);
strcpy(memo.key_input,key);
//printf("%s",memo.string);
int len_string = strlen(memo.string);
int len_key = strlen(memo.key_input);
//printf("\n string lenth is %d",len_string);
memo.ASCII_string = (int*)malloc(len_string * sizeof(int));
memo.Key_ascii =   (int*)malloc(len_string * sizeof(int));
memo.cipher = (int*)malloc(len_string * sizeof(int));
memo.ciphered_values =  (char*)malloc(len_string * sizeof(char));

int j = 0;
for(int i = 0;memo.string[i] != '\0';i++){
   memo.ASCII_string[i] = (int)memo.string[i];
   memo.Key_ascii[i] = (int)memo.key_input[j];
   j+=1;
   if(memo.key_input[j]=='\0'){
    j =0;
   }
}
for(int i = 0;i<len_string;i++){
   if(  memo.ASCII_string[i] != 32){
     memo.ASCII_string[i] -= 64;
   }else   memo.ASCII_string[i] = 20;
   if( memo.Key_ascii[i] != 32 ){
     memo.Key_ascii[i] -= 64;
   }
}
for(int i = 0;i<len_string;i++){
    memo.cipher[i] = memo.ASCII_string[i] + memo.Key_ascii[i];
}
for(int i = 0;i<len_string;i++){
    memo.cipher[i] = memo.cipher[i]%26;
}
for(int i = 0;i<len_string;i++){
    memo.cipher[i] += 64;
}
for(int i = 0;i<len_string;i++){
    memo.ciphered_values[i] = (char)memo.cipher[i];
}
//add this valies 
  printf("Entered string  : %s\n ",memo.string);
  printf("Ciphered string : %s\n ",memo.ciphered_values);


// for(int i = 0;i<len_string;i++){
//     printf("%s\n ",memo.string);
//   //printf("\n%d : %d : %d : %c",memo.ASCII_string[i],memo.Key_ascii[i], memo.cipher[i], memo.ciphered_values[i]);
// }


}
void encoder(){
char string[MAX_LEN];
char key_s[MAX_LEN];
printf("Enter the sentence : ");
fgets(string,MAX_LEN,stdin);
string[strcspn(string, "\n")] = 0;
printf("Enter the key : ");
fgets(key_s,MAX_LEN,stdin);
key_s[strcspn(key_s, "\n")] = 0;
cipher(string,key_s);

}


int main(){
    pattern();
    //num_printer
    //order();
    //key_hole();
    //name_data_base_search();
    //encoder();
    return 0;
}



