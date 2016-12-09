/* Solution for Day 7 of the 2016 Advent of Code */
/* Solution by Andrew Fugier */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char v[3];          // ABA or BAB types
    struct node* next;  // next node
};

void list_init(struct node *list){
    list->next=NULL;
}

void list_print(struct node *list){
    printf("LIST: ");
    while(list->next != NULL){
        printf("%c%c%c,", list->v[0], list->v[1], list->v[2]);
        list = list->next;
    }
    printf(" (END)\n");
}

void list_add(char *s, struct node *ll){
    while(ll->next != NULL){ ll = ll->next; }
    ll->next = malloc(sizeof(struct node));
    ll->v[0] = s[0]; ll->v[1] = s[1]; ll->v[2] = s[2];
    ll->next->next = NULL;
}

int list_find(char *s, struct node *ll){  // FIND THE INVERSE (ABA->BAB) in LL
    while(ll->next != NULL){
        if(ll->v[0] == s[1] && ll->v[1] == s[0] && ll->v[2] == s[1]){
          return 1;
        }
        ll = ll->next;
    }
    return 0;
}

void find_seq(char *s, struct node *list){   // checks for ABA or BAB seq
    // loop though string, checking for the ABBA seq
    // [0|1|2] verify non-NULL, 0!=1, 0==2
    //  ^      pointer
    int i = 0;
    while(s[i]+1 != '\0' && s[i+2] != '\0'){
        if((s[i] != s[i+1]) && (s[i]==s[i+2])){ 
            list_add(s+i, list);
        }
        i++;
    }
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
        int i = 0, in_hypernet = 0;
        char *s = data;
        struct node list_addr, list_net;
        list_init(&list_addr);
        list_init(&list_net);
        while(data[++i]){
            // parse each substring
            if(data[i] == '[' || data[i] == ']' || data[i+1] == '\0'){
                if(data[i+1]){ data[i] = '\0'; } // set null term if ! EOL
                if(in_hypernet){ find_seq(s, &list_net);  }
                else{            find_seq(s, &list_addr); }
                in_hypernet = !in_hypernet;
                s = data + i + 1;  // set for start of next string
            }
        }

        if(list_addr.next != NULL && list_net.next != NULL){
            int f = 0;
            do{
                f = list_find(list_addr.v, &list_net);
                valid_ip = valid_ip + f;
                list_addr = *list_addr.next;
            }while (list_addr.next != NULL && !f);
        }
    }
    printf("There are %i valid IPv7 addrs\n", valid_ip);

    fclose(fp);    // fp should be valid as we return -1 above we fail to open
    return(0);
}
