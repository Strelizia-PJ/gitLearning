#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char buf[200];
    FILE *fp;
    int len;
    int charCount = 0;
    int wordCount = 0;
    char c;
    int isWord = 0;
    int meetTheFirstWord = 0;
	int i = 0;

    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("read error");
        exit(0);
    }

    while (fgets(buf, 100, fp) != NULL)
    {
        len = strlen(buf);
        for ( i = 0; i < len; i++)
        {
            c = buf[i];
            //printf("%c", c);
            if (c != '\0')
            {
                charCount++;
            }

            if (meetTheFirstWord == 0 && isalnum(c) && c != ' ' && c != ',')
            {
                meetTheFirstWord = 1;
            }
            

            if (isalnum(c) && meetTheFirstWord && c != ' ' && c != ',')
            {
                isWord = 1; 
                //printf("%c", c);
            }
            else if(isWord == 1 && isalnum(c) == 0)
            {
                isWord = 0;
                wordCount++;
                //printf("\n");
            }
            else
            	//printf("\n");
        }

    }
    
    if(isWord == 1)
    	wordCount++;
    
    if (!strcmp(argv[1],"-w"))
    {
        printf("µ¥´ÊÊý: %d", wordCount);
        return wordCount;
    }
    else if(!strcmp(argv[1],"-c"))
    {
        printf("×Ö·ûÊý: %d", charCount);
        return charCount;
    }

    return 0;
}
