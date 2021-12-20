#include <stdio.h>
#include <ctype.h>

#define Text 1024
#define Word 30


void gematria_s()
{

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

printf("done:\n");
printf("%s", str);


check = 0;
printf("\n");
printf("Enter text:\n");


for(i = 0; i < Text && check == 0; i++)
{
    ch = getchar();
    if(ch == '~')
    {
        printf("works");
        check = 1;
    }
    else
    { 
        text[i] = ch;
    }
   
}

printf("\n");

printf("done:\n");
printf("%s", text);



}
