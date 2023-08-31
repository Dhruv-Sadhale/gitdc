#include<stdio.h>
#include<string.h>
int main(){
   
    
    
    char pass_correct[]="yo3";
    int j=0;
    while(j<3){
        int count=0;
        char pass[100];
        printf("enter password\n");
        fgets(pass,100,stdin);

        // code from gpt to replace \n with \0
        char *newline = strchr(pass, '\n');
      if (newline) {
     *newline = '\0'; // Replace newline with null terminator
}

    for(int i=0;i<strlen(pass_correct);i++){
        if(pass[i]!=pass_correct[i]){
            count++;
        }
    }
    if(count==0){
        printf("correct password \n");
        break;
    }
    else{
        printf("incorrect password\n");
    }
    j++;
    }
    return 0;
}