//Carson Gedeus
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int toBaseFour(int b, char letters[]){
int length, num=0, convert, *rem, i = 0, j = 0;
char arr1[4] = {'A', 'C', 'G', 'T'};

    length = strlen(letters);
    rem = malloc(sizeof(int)*32);
    convert = atoi(letters);

    while(1)
    {
        rem[num] = convert%4;
        convert = convert/4;
      //  printf("%d\n", rem[num]);//shows the remainder
        num++;//Takes the size of the array
        if(convert < 1){
            break;
        }
    }

    printf("Sequence #%d: ", b);
    for (i = num-1; i >= 0; i--) {
        printf("%c", arr1[rem[i]]);
    }

    printf("\n");
    return 0;
}

int toBaseTen(int a, char *gene){
    int product = 4;

    int i, j, length, convert, res =0, baseTen=0;
    char arr1[5] = {'A', 'C', 'G', 'T'};

    length = strlen(gene);
    for(i=0; i<length; i++){
        for(j=0; j<=3; j++){
            if(gene[i] == arr1[j])
            {
            gene[i] = j + '0';
            }
        }
    }

    printf("Sequence #%d: ", a);
    for(i=0; i<length; i++){
            gene[i] = gene[i] - '0';
            baseTen += gene[i]*pow(product, length-1-i);
    }
            printf("%d\n", baseTen);
    return 0;
}

int main(){
    char input[15];
    int n, t, i;

    scanf("%d", &t);
    for(i=0; i<t; i++){
        scanf("%s", input);

        if(isalpha(input[0])){
        toBaseTen(i+1,input);
        }
        else
        toBaseFour(i+1, input);
    }
    return 0;
}
