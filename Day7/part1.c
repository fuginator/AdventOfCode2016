/* Solution for Day 7 of the 2016 Advent of Code */
/* Solution by Andrew Fugier (heatmap taken from my part Day4 solution) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int has_ABBA_seq(char* s){
    // loop though string, checking for the ABBA seq
    // [0|1|2|3] verify non-NULL, 0!=1, 1==2 && 0==3
    //  ^       pointer
    int i = 0, r = 0;
    while(s[i]+3 != EOF && s[i+3] != '\0'){
        if((s[i] != s[i+1]) && (s[i+1]==s[i+2]) && (s[i]==s[i+3])){ r=1; }
        i++;
    }
    return r;
}

int main()
{
    FILE *fp = fopen("input", "r");
    char data[512];  // no line would be more than this, right?
    int valid_ip = 0;

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }

    while (fscanf(fp, "%s", data) != EOF) {
        int i = 0, address_ABBA = 0, hypernet_ABBA = 0, in_hypernet = 0;
        char *s = data;
        while(data[++i]){
            // parse each substring
            if(data[i] == '[' || data[i] == ']' || data[i+1] == '\0'){
                if(data[i+1]){ data[i] = '\0'; } // set null term if ! EOL
                if(has_ABBA_seq(s)){ in_hypernet ? hypernet_ABBA++ : address_ABBA++; }
                in_hypernet = !in_hypernet;
                s = data + i + 1;  // set for start of next string
            }
        }
        if(!hypernet_ABBA && address_ABBA){ valid_ip++; }
    }
    printf("There are %i valid IPv7 addrs\n", valid_ip);

    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
