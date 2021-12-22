#include <stdio.h>
#include <ctype.h>
#include <string.h>

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






void gematria_s(char str[Word], char text[Text])
{
  
    
    int word_length,i, j, z, sum = 0, sum_word = get_word_gv(str), check = 0, new_word_l;
    char ch;
    char *tokens = strtok(text, " ");
    char *token;
    char *new_token;
    int text_length = strlen(text);

  


    while(tokens != NULL)
    {
      word_length = strlen(tokens);
      for(i = 0; i < word_length; i++)
      {
            sum = 0;
            char geo[text_length];
            for(j = i; j < word_length && sum < sum_word; j++)
            {
                if ((tokens[j] >= 'a' && tokens[j]  <= 'z') || (tokens[j] >= 'A' && tokens[j]  <= 'Z'))
                {
                    ch = tolower(tokens[j]);
                    sum = sum + (ch - 96);
                    strncat(geo, &tokens[j], 1);
                }
                else
                {
                    strncat(geo, &tokens[j], 1);
                }

            }
         //   printf("sum word is: %d\n", sum_word);
            if(sum == sum_word)
            {
                char c = '~';
                strncat(geo, &c, 1);
                printf("%s\n", geo);
            }
            else
            {
                new_token = tokens;
                new_token = strtok(NULL, " ");
                while(new_token != NULL && sum_word < sum)
                {
                    new_word_l = strlen(new_token);
                    for(z = 0; z < new_word_l && sum_word > sum; z++)
                    {
                        if ((new_token[z] >= 'a' && new_token[z] <= 'z') || (new_token[z] >= 'A' && new_token[z] <= 'Z'))
                        {
                          ch = tolower(new_token[z]);
                          sum = sum + (ch - 96);
                          strncat(geo, &new_token[z], 1);
                        }
                        else
                        {
                          strncat(geo, &new_token[z], 1);
                        }

                    }

                    new_token = strtok(NULL, " ");
                }
                if(sum == sum_word)
                {
                 char c = '~';
                 strncat(geo, &c, 1);
                 printf("%s\n", geo);
                }
               
            }

        
       }
   //   printf("%s\n", tokens); 
      tokens = strtok(NULL, " ");
    }












































    /*
    for(i = 0; i < text_length - word_length; i++)
    {
        if(text[i] != ' ' || text[i] !== '\n')
        {
            

          if ((text[i] >= 'a' && text[i]  <= 'z') || (text[i] >= 'A' && text[i]  <= 'Z'))
          {
            int ch = tolower(text[i]) - 96;
            sum = sum + ch;
            count++;
          }

          if(sum == word_value)
          {

          }
        }
    }
    */

}

void atbash_s()
{

}


void anagram_s()
{
    
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

gematria_s(str, text);
printf("%d", get_word_gv(str));
//printf("%s", text);



}
