// Sure, here's a question that incorporates various basic concepts of C programming:

// **Question: Implement a program that reads a sentence from the user, then performs the following tasks:**

// 1. **Word Count:** Count the number of words in the sentence and display the count.
// 2. **Character Frequency:** Determine and display the frequency of each character (excluding spaces) in the sentence.
// 3. **Longest Word:** Find and display the longest word in the sentence.
// 4. **Vowel Count:** Count and display the number of vowels in the sentence.
// 5. **Reverse Order:** Display the sentence in reverse word order (e.g., "Hello world" becomes "world Hello").

// Remember to use appropriate data structures such as arrays and structures, and utilize pointers, functions, and loops to accomplish these tasks.
#include <stdio.h>
#include <string.h>
int word_count(char str[]);
   void char_freq(char str[]);
   void longestword(char str[]);
int word_count(char str[])
{

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && str[0] != ' ' && str[strlen(str)] != ' ')
        { // check again
            count++;
        }
    }
    return count + 1;
}
 
    void char_freq(char str[])
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
           
            // check again
                int count = 0;
                for ( int i = 0; str[i] != '\0'; i++)
                {
                    
                    if (str[i] == j && str[i] != ' ')
                    {
                        count++;
                    }
                }
                if (count!=0){
                printf("count of %c is %d \n", j,count);
                }
            
        }
    }
     struct word{
        char long_word[100];
        char max[100];
    };

    void longestword(char str[]){
        struct word s1[100];
        char max[100];
        int count=0;
        int first=0;
        int last=0;
        int k=0;
     for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ' || str[i]=='\n'){
           int j;
            int m=0;
            for( j=first;j<i;j++){
                s1[k].long_word[m]=str[j];
                m++;
            }
            s1[k].long_word[m]='\0';
            if(strlen(s1[k].long_word)>strlen(max)){
               
               strcpy( max,s1[k].long_word);
            }
            first=i+1;
             k++;
        }
     }

     printf("longest word is \n");
     puts(max);
for(int z=1; z<=k; z++){
    puts(s1[z].long_word);
}
    }


    int main()
    {
        char str[200];
        printf("Enter a sentence\n"); // input from user
        fgets(str, 200, stdin);
        printf("Is this your sentence?\n");
        puts(str);
        printf("Number of words in the sentence are %d \n", word_count(str));
        char_freq(str);
        longestword(str);
        return 0;
    }