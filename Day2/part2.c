/* Solution for Day 2 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>

void move(int *pos, char dir){
    int mask[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    if(dir == 'U' && pos[0] > 0 && mask[pos[0]-1][pos[1]]) { pos[0]--; }
    if(dir == 'D' && pos[0] < 4 && mask[pos[0]+1][pos[1]]) { pos[0]++; }
    if(dir == 'R' && pos[1] < 4 && mask[pos[0]][pos[1]+1]) { pos[1]++; }
    if(dir == 'L' && pos[1] > 0 && mask[pos[0]][pos[1]-1]) { pos[1]--; }
    return;
}

int main()
{
    char c;             // for reading from the input file
    int pos[2] = {2,0}; // current position on the numpad (start @ '5')
    FILE *fp = fopen("input", "r");
        
    char keys[5][5] = {
        {'0', '0', '1', '0', '0'},
        {'0', '2', '3', '4', '0'},
        {'5', '6', '7', '8', '9'},
        {'0', 'A', 'B', 'C', '0'},
        {'0', '0', 'D', '0', '0'}
    };

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }
 
    while ((c = fgetc(fp))!= EOF) {
        move(pos, c);
        if(c == 10){ printf("%c", keys[pos[0]][pos[1]]); }  // output on newline
    }

    printf("\n");  // I hate things that thrash your console.  End w/ newline
    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
