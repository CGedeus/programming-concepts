// Carson Gedeus, 11/30/2015

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "HW7_Functions.c"

extern Node * head;
extern Node *post, *prior, *current;
extern FILE *finput, *foutput;


int main(){                 //main functions with print statements
int choice;
int option;

    load();

    printf("What do you like to do?\n");
    printf("1 - Insert something in the list\n");
    printf("2 - Delete something from the list\n");
    printf("3 - Print out it's contents \n");
    printf("4 - Return the element selected\n");
    printf("5 - Nothing at all\n");
    printf("0 - Terminate\n");
    printf("Enter 1 through 5: ");
    scanf("%d", &choice);


while(option != 0){             //Various case options
        switch(choice){
        case 1:
            insertsomething();
            printitout();
            break;
        case 2:
            deletesomething();
            break;
        case 3:
            printitout();
            break;
        case 4:
            servesomething();
            break;
        default:
            printf("OK, bye\n");
        }

    printf("Enter another option to continue..press zero to discontinue\n");
    scanf("%d", &option);

}
save();
return 0;
}
