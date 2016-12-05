/* Solution for Day 1 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>

struct node {           // used for a basic linked-list
    int cords[2];       // x, y
    struct node* next;  // next node; NULL for end-of-list
};

int partTwoDone = 0;    // have we found the solution to part 2?

char rotate(char dir, char mov){
    switch(dir){   // break not needed because of return
        case 'N':
          return mov == 'L' ? 'W' : 'E';
        case 'E':
          return mov == 'L' ? 'N' : 'S';
        case 'S':
          return mov == 'L' ? 'E' : 'W';
        case 'W':
          return mov == 'L' ? 'S' : 'N';
    }
    return 'N';    // return 'N' if invalid data
}

/* Search for a pair in ll, if not found, add it*/
/* Return value 1 if we found it, 0 otherwise */
int searchOrAdd(int *cords, struct node *ll){
    while(ll->next != NULL){
        if(ll->cords[0] == cords[0] && ll->cords[1] == cords[1]){
            if(!partTwoDone){
                printf("First location visited twice is %i blocks away. (at block %i, %i)\n", \
                       abs(cords[0]) + abs(cords[1]), cords[0], cords[1]);
                partTwoDone = 1;
            }
            return 1;
        }
        ll = ll->next;
    }
    // if we got here, we didn't find it.  Add it and return 0
    // as a bonus, we're already at the end of the list from the search
    ll->next = malloc(sizeof(struct node));
    ll->cords[0] = cords[0]; ll->cords[1] = cords[1];
    ll->next->next = NULL;
    return 0;
}

void step(int *cords, int cordIndex, int amt, struct node *ll){
    int i;
    int increment = amt < 0 ? -1 : 1;
    for(i = 0; i < abs(amt); i++){
        cords[cordIndex] = cords[cordIndex] + increment;
        searchOrAdd(cords, ll);  // wound up not using return value
    }
}

void move(char dir, int amt, int *cords, struct node *ll){
    step(cords,                                       // the cords 
         dir == 'N' || dir == 'S' ? 1 : 0,            // X = 1 vs Y = 0
         dir == 'N' || dir == 'E' ? amt : amt * -1,   // N,E pos vs S,W Neg
         ll);
}

int main()
{
    char data[8];  // should be no more than 8 chars in an insturction - right?
    int cords[2] = {0, 0};  // x, y
    FILE *fp = fopen("input", "r");
    char dir = 'N';

    struct node ll; 
    ll.cords[0] = ll.cords[1] = 0;
    ll.next = NULL;

    if(fp == NULL) {
        printf("could not open input file\n");
        return -1;
    }
 
    while (fscanf(fp, "%s", data) != EOF) {
        dir = rotate(dir, data[0]);
        move(dir, atoi(data+1), cords, &ll);  // atoi strips ',' for us
    }

    printf("Final distance is %i blocks away. (at block %i, %i)\n", abs(cords[0]) + abs(cords[1]), cords[0], cords[1]);
    fclose(fp);  // fp should be valid as we return -1 above we fail to open
    return(0);
}
