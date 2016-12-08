/* Solution for Day 6 of the 2016 Advent of Code */
/* Solution by Andrew Fugier (heatmap taken from my part Day4 solution) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* return the position in an array with the highest count */
char pick_heatmap(int* heatmap) {
    int i, pos, max = 0;
    for(i = 0; i <= 'z' - 'a'; i++){
        //printf("Reading pos %i with a score of %i\n", i, heatmap[i]);
        if(heatmap[i] > max) {
            max = heatmap[i];
            pos = i;
        }
    }
    //printf("We picked pos %i\n", pos);
    return pos;
}

int main()
{
    FILE *fp = fopen("input", "r");
    char data[16];  // no line would be more than this, right?
    int heatmaps[8][26] = {{0}}, i;

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }

    while (fscanf(fp, "%s", data) != EOF) {
        for(i = 0; i < 8; i++){
            heatmaps[i][(int)data[i] - 'a']++;
        }

    }

    // pull out of our heatmap, calc the checksum
    for(i = 0; i < 8; i++){
        printf("%c", pick_heatmap(heatmaps[i])+'a');
    }

    printf("\n");
    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
