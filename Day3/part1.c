/* Solution for Day 3 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("input", "r");
    int a1, a2, a3, possible = 0;

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }
 
    while (fscanf(fp, "%i %i %i", &a1, &a2, &a3) != EOF) {
        if(a1 + a2 > a3 && a2 + a3 > a1 && a3 + a1 > a2){
            possible++;
        } 
    }

    printf("Possible: %i\n", possible);
    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
