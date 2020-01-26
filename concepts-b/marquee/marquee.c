//Carson Gedeus, marquee.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i, j, k, l;
    int sequence, numChar, sign=0;
    char word[100];

    scanf("%d", &sequence);

    for(i=0; i<=sequence; i++)
    {
        gets(word);
        scanf("%d", &numChar);

//use atoi function to convert
//for loop issue

        int length = strlen(word)-1;

        if(word[strlen(word)-1] == '\n')
            word[strlen(word)-1] = '\0';

        sign += 1;
        printf("Sign #%d\n", sign);

        for(k=0; k<length+1; k++)
        {
            putchar('[');

            for(l=0; l<numChar; l++)
            {
                char result = word[(k+l)%(length+1)];
                if(!result)
                    result = ' ';
                putchar(result);
            }
            printf("]\n");
        }

    }

}