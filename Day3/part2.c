/* Solution for Day 3 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("input", "r");
    int a1, a2, a3, b1, b2, b3, c1, c2, c3, possible = 0;

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }
 
    while (fscanf(fp, "%i %i %i", &a1, &b1, &c1) != EOF &&
           fscanf(fp, "%i %i %i", &a2, &b2, &c2) != EOF &&
           fscanf(fp, "%i %i %i", &a3, &b3, &c3) != EOF) {
        if(a1 + a2 > a3 && a2 + a3 > a1 && a3 + a1 > a2){ possible++; } 
        if(b1 + b2 > b3 && b2 + b3 > b1 && b3 + b1 > b2){ possible++; } 
        if(c1 + c2 > c3 && c2 + c3 > c1 && c3 + c1 > c2){ possible++; } 
    }

    printf("Possible: %i\n", possible);
    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
