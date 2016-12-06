/* Solution for Day 5 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
    FILE *fp = fopen("input", "r");
    char data[16];  // no input would be more than this, right?

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }
 
    while (fscanf(fp, "%s", data) != EOF) {
        unsigned char digest[16];
        char out[33],  in[33];
        int i, progress = 0;
        unsigned long long index = 0;

        while(progress < 8){
            snprintf(in, sizeof(in), "%s%llu", data, index);
            MD5((unsigned const char *)in, strlen(in), digest);

            for (i = 0; i < 16; i++) {
                snprintf(out+(i*2), 16*2, "%02x", digest[i]);
            }
            
            if(!strncmp(out, "00000", 5)){
                printf("Digest of '%s' is '%s' - here we should use char '%c'\n", in, out, out[5]);
                progress++;
            }
            index++;
        }
    }

    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
