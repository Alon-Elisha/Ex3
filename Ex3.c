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
    char fulls[Text] = "";
    int fulls_count = 0;

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
                int news = 0;
                int new_len = strlen(geometric);
                for(news= 0; news < new_len; news++)
                {
                    fulls[fulls_count] = geometric[news];
                    fulls_count++;
                }
                fulls[fulls_count] = '~';
                fulls_count++;
                //strcat(fulls, geometric);
                //strcat(fulls,"~");
                //printf("%s~", geometric);
            }
        }

    }
    int rem = strlen(fulls);
    fulls[rem - 1] = '\0';
    printf("%s", fulls);


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
    char fulls[Text] = "";
    int fulls_count = 0;

    int i, j, count = 0, count1 = 0, pointed, index, index2;
    int sum_word = get_word_gv(str);
    int length = strlen(text);  
    bool flag1 = true, flag2 = true;
    int size = 0;
    char atbash1[Word] = " ";
    char atbash2[Word] = " ";
    for(i = 0; i < length; i++)
    {
        if ((text[i] >= 'a' && text[i]  <= 'z') || (text[i] >= 'A' && text[i]  <= 'Z'))
        {
            count = 0;
            pointed = i;
            index = 0;
            flag1 = true;
            strcpy(atbash1, str);
            strcpy(atbash2, str);
            atbash_code(atbash1);
            atbash_code(atbash2);

            char at1[Text] = " ";
            while(flag1 == true && count != strlen(atbash1))
            {
               // printf("hey\n");
                if(text[pointed] == atbash1[count])
                {
                   // printf("i = %d index = %d and str = %s\n", i, index, at1);
                    at1[index] = text[pointed];
                    count++;
                    pointed++;
                    index++;
                }
                else{
                    if(text[pointed] != ' ' || text[pointed] != '\n')
                    {
                        flag1 = false;
                    }
                    else
                    {
                        at1[index] = text[pointed];
                        pointed++;
                        index++;
                    }
                }
            }
            if(flag1 == true)
            {
                int iz = 0;
                for(iz = 0; iz < strlen(at1); iz++)
                {
                    fulls[fulls_count] = at1[iz];
                    fulls_count++;
                }
                fulls[fulls_count] = '~';
                fulls_count++;
                //strcat(fulls, at1);
                //strcat(fulls, "~");
                //printf("%s~", at1);
            }

            count1 = 0;
            int pointed1 = i;
            int index1 = 0;
            flag2 = true;
            char at2[Text] = " ";
            while(flag2 == true && count1 != strlen(atbash2))
            {
               // printf("hey\n");
                if(text[pointed1] == atbash1[count1])
                {
                   // printf("i = %d index = %d and str = %s\n", i, index, at1);
                    at2[index1] = text[pointed1];
                    count1++;
                    pointed1++;
                    index1++;
                }
                else{
                    if(text[pointed1] != ' ' || text[pointed1] != '\n')
                    {
                        flag2 = false;
                    }
                    else
                    {
                        at2[index] = text[pointed1];
                        pointed1++;
                        index1++;
                    }
                }
            }
            if(flag2 == true)
            {
                int iz = 0;
                for(iz = 0; iz < strlen(at2); iz++)
                {
                    fulls[fulls_count] = at2[iz];
                    fulls_count++;
                }
                fulls[fulls_count] = '~';
                fulls_count++;
                //strcat(fulls, at2);
                //strcat(fulls, "~");
                //printf("%s~", at2);
            }
            
        }
        
    }
    int rem = strlen(fulls);
    fulls[rem - 1] = '\0';
    printf("%s", fulls);
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
    char fulls[Text] = "";
    int fulls_count = 0;

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
                int zx = 0;
                for(zx = 0; zx < strlen(letters); zx++)
                {
                    fulls[fulls_count] = letters[zx];
                    fulls_count++;
                }
                fulls[fulls_count] = '~';
                fulls_count++;
                //strcat(fulls, letters);
                //strcat(fulls, "~");
                //printf("%s~", letters);
            }

        }
    }
    int rem = strlen(fulls);
    fulls[rem - 1] = '\0';
    printf("%s", fulls);
    
}





void main()  {



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
        text[i] = ch;
    }
    /*
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
    */
   
}

printf("Gematria Sequences: ");
gematria_s(str, text);
printf("\n");
//anagram_s(str,text);
printf("Atbash Sequences: ");
atbash_s(str, text);
printf("\n");
printf("Anagram Sequences: ");
anagram_s(str,text);
printf("\n");
//printf("%d", get_word_gv(str));
//



}
