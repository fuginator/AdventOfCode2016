/* Solution for Day 9 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>

void output(char c, unsigned long *ol){
    if(c != '\n'){
        printf("%c", c);
        (*ol)++;
    }
}

int main()
{
    FILE *fp = fopen("input", "r");
    char d;
    unsigned long ol = 0;
    int i, j, arg1, arg2;

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }

    while (fscanf(fp, "%c", &d) != EOF) {
        if(d == '('){  // hit a marker
            fscanf(fp, "%ix%i)", &arg1, &arg2);
            char temp[128];
            fgets(temp, arg1+1, fp);        // snag arg1 data
            for(i = 0; i < arg2; i++){      // and print it
                for(j = 0; j < arg1; j++){  // arg2 times
                    output(temp[j], &ol);
                }
            }
        }else{
            output(d, &ol);                 // regular data
        }
    }
    printf("\nWe output %lu chars.\n", ol);

    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
