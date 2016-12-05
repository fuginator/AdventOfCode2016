/* Solution for Day 1 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>

char rotate(char dir, char mov){
    switch(dir){   // break no needed because of return
        case 'N':
          return mov == 'L' ? 'W' : 'E';
        case 'E':
          return mov == 'L' ? 'N' : 'S';
        case 'S':
          return mov == 'L' ? 'E' : 'W';
        case 'W':
          return mov == 'L' ? 'S' : 'N';
    }
    return 'N';  // return 'N' if invalid data
}

void move(char dir, int amt, int *cords){
    switch(dir){
        case 'N':
          cords[1] = cords[1] + amt;
          break;
        case 'E':
          cords[0] = cords[0] + amt;
          break;
        case 'S':
          cords[1] = cords[1] - amt;
          break;
        case 'W':
          cords[0] = cords[0] - amt;
          break;
    }
}

int main()
{
    char data[8];  // should be no more than 8 chars in an insturction - right?
    int cords[2] = {0, 0};  // x, y
    FILE *fp = fopen("input", "r");
    char dir = 'N';

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }
 
    while (fscanf(fp, "%s", data) != EOF) {
        dir = rotate(dir, data[0]);
        move(dir, atoi(data+1), cords);  // atoi strips ',' for us
    }

    printf("Final distance is %i blocks away.\n", abs(cords[0]) + abs(cords[1]));
    return(0);
}
