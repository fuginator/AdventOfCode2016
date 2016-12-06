/* Solution for Day 4 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* return the position in an array with the highest count (and clear it) */
char pick_heatmap(int* heatmap) {
    int i, pos, max = 0;
    for(i = 0; i <= 'z' - 'a'; i++){
        if(heatmap[i] > max) {
            max = heatmap[i];
            pos = i;
        }
    }
    heatmap[pos] = 0;
    return pos;
}

int main()
{
    FILE *fp = fopen("input", "r");
    char data[64];  // no line would be more than this, right?
    int real_rooms = 0, sector_id_sum = 0;

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }
 
    while (fscanf(fp, "%s", data) != EOF) {
        int i = -1,sector_id = 0, heatmap['z' - 'a' + 1] = { 0 };
        char checksum[6],  calc[6] =  { '\0' };

        while(data[++i] != ']'){
            if(!sector_id && data[i] >= 'a' && data[i] <= 'z'){
                heatmap[(int)data[i] - 'a']++;  // add char to heatmap
            }

            if(!sector_id && data[i] >= '0' && data[i] <= '9'){
                sector_id = atoi(data+i);  // found a number, copy sector_id
            }

            if(data[i] == '['){
                strncpy(checksum, data+(++i), 5);  // at checksum, copy it
            }
        }

        // pull out of our heatmap, calc the checksum
        for(i = 0; i < 5; i++){
            calc[i] = pick_heatmap(heatmap) + 'a';
        }

        if(strcmp(checksum, calc) == 0) {
            real_rooms++;
            sector_id_sum = sector_id_sum + sector_id;
        }
    }

    printf("There were %i valid rooms, with a sector id sum of %i\n", real_rooms, sector_id_sum);

    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
