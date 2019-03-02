/*
 * Ian Oberle
 * CS 2750 PA4
 * 11/04/2017
 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char **argv)
{
    FILE *fp;
    char *filename, file[25];
    char ch;
    int linecount = 0, wordcount = 0, charcount = 0;
    
    int i;
    
    //Checks if there were any command-line arguments
    if (argc < 2)
    {
        printf("No files for use were specified.");
        printf("Please enter a file name(s).");
        gets(file);
        printf("\n");

        //Opens selected file and does specified operations
        fp = fopen(file,"r"); 
        if(fp)
        {
            while ((ch=getc(fp)) != EOF)
            {
                if (ch != ' ' && ch != '\n')
                    ++charcount;
                if (ch == ' ' || ch == '\n')
                    ++wordcount;
                if (ch == '\n')
                    ++linecount;
            }   
            fclose(fp);
            printf("\nLines: %d\n", linecount);
            printf("Words: %d\n", wordcount);
            printf("Characters: %d\n", charcount);
            printf("File: %s\n", file);
        }
    }

    //Uses command-line arguments to complete project operations
    else
    for(i = 1;i < argc;i++)
    {
        charcount = 0;
        wordcount = 0;
        linecount = 0;
        filename = argv[i];
        fp = fopen(filename,"r"); 
        if(fp)
        {
            while ((ch=getc(fp)) != EOF)
            {
                if (ch != ' ' && ch != '\n')
                    ++charcount;
                if (ch == ' ' || ch == '\n')
                    ++wordcount;
                if (ch == '\n')
                    ++linecount;
            }   
            fclose(fp);
            printf("\nLines: %d\n", linecount);
            printf("Words: %d\n", wordcount);
            printf("Characters: %d\n", charcount);
            printf("File: %s\n", filename);
        }
    }
    return(0);
}
