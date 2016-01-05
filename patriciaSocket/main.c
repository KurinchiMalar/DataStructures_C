/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on September 22, 2013, 7:57 PM
 */
/*****************************************************************************
 * STANDARD INCLUDE FILES
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <string.h>

/*****************************************************************************
 * LOCAL DEFINITIONS
 *****************************************************************************/
#define BYTE_BITi( DX , bit_pos ) \
		( ( ( 0X80 >> ( bit_pos -1 ) ) & ( DX ) )  >0  )
#define __attribute__(x)

struct in_addr __attribute__((__packed__)) {
    unsigned long s_addr; // load with inet_aton()
};

typedef struct sockaddr_in __attribute__((__packed__)) {
    short sin_family; // e.g. AF_INET
    unsigned short sin_port; // e.g. htons(3490)
    struct in_addr sin_addr; // see struct in_addr, below
    char sin_zero[8]; // zero this if you want to
}
socketType;

typedef struct Node {
    socketType* data;
    struct Node* leftchild;
    struct Node* rightchild;
    int bitpos;
} Node;
Node* root = NULL;

/*****************************************************************************
 * GLOBAL VARIABLE DEFINITIONS
 *****************************************************************************/
int byte_end_indices[16] = {8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128};

/*
char* construct_complete_array(socketType* m){
    unsigned char complete[16]= {0};
    unsigned char *temp = (unsigned char*)m;
    size_t j;
    printf("\n*** Inside construct_complete_array ***\n");
    for (j = 0;j<sizeof(*m);j++){
        complete[j] = *(temp);
        printf("%.2x ", *(temp));
 *temp++;
    }
    return complete;
}
 */
void print_utility(socketType* d) {
    unsigned char *p = (unsigned char*) d;
    size_t i;
    for (i = 0; i<sizeof (*d); i++) {
        printf("%.2x ", *(p));
        //complete[i] = *(p);
        *p++;
    }
}

int cur_byte(int n) { // given bitpos occurs at which byte
    if (n % 8 == 0) {
        return (n / 8);
    }
    return (n / 8) + 1;
}

int find_bit_at_bitpos(char* totalarray, int bitpos) {

    int curbytepos = cur_byte(bitpos); // identify the byte for the given bit position in total array.
    int prevbytepos = curbytepos - 1;
    //printf("\ncurbytepos is %d",curbytepos);
    char curbyte = *(totalarray + (curbytepos - 1)); // extract the actual byte from total array.
    //printf("\ncurbyte is %.2x",curbyte);
    int end_index_of_prevbyte = byte_end_indices[prevbytepos - 1];
    //printf("\n end_index_of_prevbyte is %d",end_index_of_prevbyte);
    int toMove = (bitpos - end_index_of_prevbyte); // in current byte move to this many bits and find bit at that pos.
    //printf("\ntoMove %d",toMove);
    return (BYTE_BITi(curbyte, toMove));


}

Node* search(Node* root, socketType* k) {
    Node *current = NULL, *next = NULL;
    current = root;
    next = current->leftchild;
    unsigned char *temp = (unsigned char*) k;
    size_t iter;
    unsigned char structtobyte_ar[16] = {0};
    for (iter = 0; iter<sizeof (*k); iter++) {
        structtobyte_ar[iter] = *(temp);
        *temp++;
    }
    while (next->bitpos > current->bitpos) {
        current = next;

        next = find_bit_at_bitpos(structtobyte_ar, next->bitpos) ? next->rightchild : next->leftchild;
    }
    return next;
}

int compare_struct(socketType* existing, socketType* now) {
    if ((existing->sin_addr.s_addr == now->sin_addr.s_addr) && (existing->sin_family == now->sin_family) && (existing->sin_port == now->sin_port) && (!strcmp(existing->sin_zero, now->sin_zero))) {
        return 1;
    }
    return 0;
}

int diff_bit_calc(socketType* datanode, socketType* knode) {
    //printf("\n*** Inside diff_bit_calc ***\n");
    socketType* datanodebkp = datanode;
    socketType* knodebkp = knode;
    unsigned char datanode_ar[16] = {0};
    unsigned char knode_ar[16] = {0};
    unsigned char *temp1 = (unsigned char*) datanodebkp;
    size_t j;
    for (j = 0; j<sizeof (*datanodebkp); j++) {
        datanode_ar[j] = *(temp1);
        //printf("%.2x ", *(temp1));
        *temp1++;
    }
    unsigned char *temp2 = (unsigned char*) knodebkp;
    size_t k;
    for (k = 0; k<sizeof (*knodebkp); k++) {
        knode_ar[k] = *(temp2);
        //printf("%.2x ", *(temp2));
        *temp2++;
    }
    /*
        printf("\nDatanode diff @ 22 : %d", find_bit_at_bitpos(datanode_ar, 22));

        printf("\nknode diff @ 22 :%d", find_bit_at_bitpos(knode_ar, 22));
     */
    int bit_index = 1;
    for (; bit_index < 128; bit_index++) {
        if (find_bit_at_bitpos(datanode_ar, bit_index) != find_bit_at_bitpos(knode_ar, bit_index)) {
            return bit_index;
        }
    }
    return bit_index;
}

Node* insert(Node** root_d_ptr, socketType* k) {

    if (*root_d_ptr == NULL) {
        printf("\nRoot is Null");
        printf("\nsize of struct(NODE)is :%d\n", sizeof (struct Node));
        *root_d_ptr = (Node*) malloc(sizeof (struct Node));
        assert(*root_d_ptr);
        (*root_d_ptr)->leftchild = (*root_d_ptr);
        (*root_d_ptr)->bitpos = 0;
        (*root_d_ptr)->data = k;
        printf("\nInserted Root");
        print_utility(k);
        return *root_d_ptr;
    }
    Node *parent = NULL, *current = NULL, *lastnode = NULL, *newnode = NULL;

    lastnode = search(*root_d_ptr, k);
    if (compare_struct(lastnode->data, k)) {
        printf("\nDuplicate entry. Insert Failed");
        return lastnode;
    } else {
        printf("\nLastNode is : ");
        print_utility(lastnode->data);
        printf("\n");
        printf("\nTo insert   : ");
        print_utility(k);
        printf("\n");
    }
    int diff_bit = diff_bit_calc(lastnode->data, k);
    printf("\nDiffering bit is : %d", diff_bit);
    //char newnode_ar[sizeof (k)];
    //memcpy(newnode_ar, &k, sizeof (k));
    printf("\n***Printing memcpy new_node_ar...***: ");
    socketType* kbkp = k;
    unsigned char newnode_ar[16] = {0};
    unsigned char *temp1 = (unsigned char*) kbkp;
    size_t j;
    for (j = 0; j<sizeof (*kbkp); j++) {
        newnode_ar[j] = *(temp1);
        printf("%.2x ", newnode_ar[j]);
        *temp1++;
    }
    // iterate whole tree and find where to position this new node.
    parent = *(root_d_ptr);
    current = parent ->leftchild;
    while ((current ->bitpos > parent->bitpos) && (current->bitpos < diff_bit)) { // not datanode && tree rule satified
        parent = current;
        current = find_bit_at_bitpos(newnode_ar, current->bitpos) ? current->rightchild : current->leftchild;
    }
    newnode = (Node*) malloc(sizeof (Node));
    assert(newnode);
    newnode ->bitpos = diff_bit;
    newnode ->data = k;
    printf("\n** newnode->leftchild: %d", find_bit_at_bitpos(newnode_ar, diff_bit));

    newnode ->leftchild = find_bit_at_bitpos(newnode_ar, diff_bit) ? current : newnode;
    newnode ->rightchild = find_bit_at_bitpos(newnode_ar, diff_bit) ? newnode : current;
    if (parent ->leftchild == current) {
        parent ->leftchild = newnode;
    } else {
        parent ->rightchild = newnode;
    }
    printf("\nInserted :");
    print_utility(newnode->data);
/*
    printf("\ncheck...parent..left right");
    print_utility(parent->leftchild->data);
    print_utility(parent->rightchild->data);
*/
    printf("\ncheck...Newnode..left right\n");
    print_utility(newnode->leftchild->data);
    printf("\n");
    print_utility(newnode->rightchild->data);
    printf("\n");
}

int main(int argc, char** argv) {
    struct sockaddr_in *record1, *record2, *record3, *record4, *record5;

    record1 = (struct sockaddr_in*) malloc(sizeof (struct sockaddr_in));
    memset(record1, 0, 16);
    record1->sin_family = 16;
    record1->sin_port = 4;
    record1->sin_addr.s_addr = 1UL;
    strcpy(record1->sin_zero, "1");

    record2 = (struct sockaddr_in*) malloc(sizeof (struct sockaddr_in));
    memset(record2, 0, 16);
    record2->sin_family = 16;
    record2->sin_port = 4;
    record2->sin_addr.s_addr = 1UL;
    strcpy(record2->sin_zero, "1");

    record3 = (struct sockaddr_in*) malloc(sizeof (struct sockaddr_in));
    memset(record3, 0, 16);
    record3->sin_family = 17;
    record3->sin_port = 5;
    record3->sin_addr.s_addr = 2UL;
    strcpy(record3->sin_zero, "2");
    
    record4 = (struct sockaddr_in*) malloc(sizeof (struct sockaddr_in));
    memset(record4, 0, 16);
    record4->sin_family = 1;
    record4->sin_port = 5;
    record4->sin_addr.s_addr = 2UL;
    strcpy(record4->sin_zero, "2");
    
    record5 = (struct sockaddr_in*) malloc(sizeof (struct sockaddr_in));
    memset(record5, 0, 16);
    record5->sin_family = 16;
    record5->sin_port = 6;
    record5->sin_addr.s_addr = 3UL;
    strcpy(record5->sin_zero, "3");


    insert(&root, record1);
    insert(&root, record2);
    insert(&root,record3);
    insert(&root,record4);
    insert(&root,record5);
    Node* catch = insert(&root,record4);
    printf("\n...Duplicate in Tree:");
    print_utility(catch->data);
    printf("\n");
    return (EXIT_SUCCESS);
}

