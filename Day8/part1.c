/* Solution for Day 8 of the 2016 Advent of Code */
/* Solution by Andrew Fugier (heatmap taken from my part Day4 solution) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("input", "r");
    char xy, data[64];
    int m[50][6] = { 0 };
    int i, j, pix = 0, arg1, arg2, index, amt;

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }

    while (fscanf(fp, "%s", data) != EOF) {
        // process the input line
        if(data[1] == 'e'){   // rectangle
            fscanf(fp, "%ix%i", &arg1, &arg2);
            for(i=0; i<arg2; i++){ for(j=0; j<arg1; j++){ m[j][i]=1; } }
        }else{
            // rotate 
            fscanf(fp, "%s %c=%i by %i", data, &xy, &index, &amt);
            if(xy=='x'){     // shift up down
                int t[6] = { 0 };
                for(int i = 0; i < 6; i++){ t[i] = m[index][i]; } // make copy
                for(int i = 0; i < 6; i++){
                    int src = i - amt;
                    if(src > 6) { src = src - 6; }
                    else if(src < 0) { src = src + 6; }
                    m[index][i] = t[src];
                }
            }
            if(xy=='y'){     // shift right left
                int t[50] = { 0 };
                for(int i = 0; i < 50; i++){ t[i] = m[i][index]; } // make copy
                for(int i = 0; i < 50; i++){
                    int src = i - amt;
                    if(src > 50) { src = src - 50; }
                    else if(src < 0) { src = src + 50; }
                    m[i][index] = t[src];
                }
            }
        }
    }

    for(i = 0; i < 6; i++){ for(j = 0; j < 50; j++){
            printf("%c", m[j][i]?'#':'.');
            pix = pix + m[j][i];
        } printf("\n"); }

    // calulate the number of 'on' pixes
    printf("There are %i Pixels on!\n", pix);

    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
