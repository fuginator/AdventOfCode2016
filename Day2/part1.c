/* Solution for Day 2 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>

int move(int pos, char dir){
    // some logic here to keep us from falling off a 9-key key pad (1,2,3 top)
    if(dir == 'U' && pos > 3) { pos = pos - 3; }
    if(dir == 'D' && pos < 7) { pos = pos + 3; }
    if(dir == 'R' && pos%3 != 0) { pos++; }
    if(dir == 'L' && pos%3 != 1) { pos--; }
    return pos;
}

int main()
{
    char c;      // for reading from the input file
    int pos = 5; // current position on the numpad
    FILE *fp = fopen("input", "r");

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }
 
    while ((c = fgetc(fp))!= EOF) {
        pos = move(pos, c);
        if(c == 10){ printf("%i", pos); }  // output on newline
    }

    printf("\n");  // I hate things that thrash your console.  End w/ newline
    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
