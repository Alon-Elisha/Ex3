#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define Text 1024
#define Word 30



int get_word_gv(char str[Word])
{
    int i, sum = 0, letter = 0;
    int word_length= strlen(str);
    for(i = 0; i < word_length; i++)
    {
         if ((str[i] >= 'a' && str[i]  <= 'z') || (str[i] >= 'A' && str[i]  <= 'Z'))
        {
            letter = tolower(str[i]) - 96;
            sum = sum + letter;
        }
    }

    return sum;
}



/*
bool handle_tokens(char geo[Text], char *tokens1, int sum_word)
{
    int i,j, sum = 0;
    char *tokens = tokens1;
    while(tokens != NULL && sum < sum_word)
    {
        int word_length = strlen(tokens);    
        for(j = i; j < word_length && sum < sum_word; j++)
        {
            if ((tokens[i] >= 'a' && tokens[i]  <= 'z') || (tokens[i] >= 'A' && tokens[i]  <= 'Z'))
            {
                char ch = tolower(tokens[j]);
                sum = sum + (ch - 96);
                strncat(geo, &tokens[j], 1);
            }
            else
            {
                strncat(geo, &tokens[j], 1);
            }

        }
        tokens = strtok(NULL, " ");
  
    }

    if(sum == sum_word)
    {
        return true;
    }
    printf("%d\n", sum);
    return false;
}

*/


void gematria_s(char str[Word], char text[Text])
{


    int i, j, sum = 0, count = 0, pointed;
    int sum_word = get_word_gv(str);
    int length = strlen(text);  
    //char geometric[Text];
    for(int i = 0; i < length; i++)
    {
     //   printf("%d", i);
     //if(text[i] != ' ' && text[i] != '\n')
    if ((text[i] >= 'a' && text[i]  <= 'z') || (text[i] >= 'A' && text[i]  <= 'Z'))
        {
            sum = 0;
            count = 0;
            pointed = i;
            char geometric[Text] = " ";
            while(sum < sum_word && pointed < length)
            {
                if((text[pointed] >= 'a' && text[pointed]  <= 'z') || (text[pointed] >= 'A' && text[pointed]  <= 'Z'))
                {
                    sum = sum + tolower(text[pointed]) - 96;
                }              
                geometric[count] = text[pointed];
                count = count + 1;   
                pointed++;      
            }

        
            if(sum == sum_word)
            {
                printf("%s~", geometric);
            }
        }

    }
    


}




void atbash_code(char str[Word])
{
    int i, pos;
    for(i = 0; i < strlen(str); i++)
    {
        pos = 0;
        if( str[i] >= 65 && str[i] <= 90)
        {
            pos = str[i] - 65;
            pos = 25 - pos;
            str[i] = pos + 65;
        }
        if( str[i] >= 97 && str[i] <= 122)
        {
            pos = str[i] - 97;
            pos = 25 - pos;
            str[i] = pos + 97;
        }
    }
}




void atbash_s(char str[Word], char text[Text])
{

    int i, j, count = 0, pointed;
    int sum_word = get_word_gv(str);
    int length = strlen(text);  
    bool flag = true;
    int size = 0;
    char atbash1[Word] = " ";
    char atbash2[Word] = " ";
    strcpy(atbash1, str);
    strcpy(atbash2, str);
    atbash_code(atbash1);
    atbash_code(atbash2);
    for(i = 0; i < length; i++)
    {
        if ((text[i] >= 'a' && text[i]  <= 'z') || (text[i] >= 'A' && text[i]  <= 'Z'))
        {
            count = 0;
            pointed = i;
        }
        
    }
}





void removeChar(char * str, char charToRemmove){
    int i, j, check = 0;
    int len = strlen(str);
    //char str[Word] = " ";
    for(i=0; i<len; i++)
    {
        if(str[i] == charToRemmove && check == 0)
        {
            for(j=i; j<len; j++)
            {
                str[j] = str[j+1];
            }
            len--;
            i--;
            check = 1;
        }
    }
    
}




void anagram_s(char str[Word], char text[Text])
{
    int i, j, count = 0, pointed;
    int sum_word = get_word_gv(str);
    int length = strlen(text);  
    bool flag = true;
    int size = 0;
    // every letter
    for(i = 0; i < length; i++)
    {
        
        size = 0;
        count = 0;
        pointed = i;
        // start from not space and alphabet
        if ((text[i] >= 'a' && text[i]  <= 'z') || (text[i] >= 'A' && text[i]  <= 'Z'))
        {
            // inital values and string to hold
            count = 0;
            pointed = i;
            flag = true;
            char letters[Text] = " ";
            char let[Word] = " ";
            char have[Word] = " ";
            strcpy(have, str);
            strcpy(let,str);
            while(flag == true)
            {
                // pointer to first occurence
                char *ch = strchr(str, text[pointed]);
                if(ch != NULL)
                {
                    removeChar(have, text[pointed]);
                    letters[count] = text[pointed];
                    count++;
                    pointed++;
                }
                else
                {            
                    flag = false;       
                }
            }
            if(have[0] == '\0')
            {
                printf("%s~", letters);
            }

        }
    }


    
}





void main()  {

char str[] = "aabzAX";
atbash_code(str);
printf("%s", str);
  
/*

int i;
char ch;
char str[Word];
char text[Text];
int check = 0;
printf("Enter word:\n");

for(i = 0; i < Word && check == 0; i++)
{
    ch = getchar();
    if(ch == '\n' || ch == '\t' || ch == '\0' || ch == EOF)
    {
        check = 1;
    }
    else
    {
        str[i] = ch;
    }
}



check = 0;

printf("Enter text:\n");


for(i = 0; i < Text && check == 0; i++)
{
    ch = getchar();
    if(ch == '~')
    {
        //text[i] = ch;
        check = 1;
    }
    else
    { 
         if(ch == '\n')
         {
            text[i] = ' ';
         }
         else
         {
             text[i] = ch;
         }
    }
   
}


//gematria_s(str, text);
anagram_s(str,text);

//printf("%d", get_word_gv(str));
//printf("%s", text);

*/

}
