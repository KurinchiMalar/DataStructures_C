/* 
 * File:   main.c
 * Author: kurnagar
 *
 * Created on September 22, 2013, 1:48 PM
 */

#include <stdio.h>
#include <stdlib.h> 
#include <assert.h> 

typedef unsigned int DataType;

#define BITi( DX , bit_pos ) \
		( ( ( 0X80000000 >> ( bit_pos -1 ) ) & ( DX ) )  >0  )

#define pviu(V)    printf("%-15s=%-12u\n",#V,V)
#define pvix(V)    printf("%-15s=%#010x\n",#V,V)
 
int different_bits_pos  ( DataType DX,  DataType DY)
{
int i;

for ( i=1;  i<=  sizeof(DataType)*8 ; i++)
{ 
     if ( BITi(DX,i) != BITi(DY,i) )
	return i;
}  

return 0;// no difference 
} 




typedef struct node {
	DataType key;
	struct node* leftchild, *rightchild;
	int bitpos;
}Node;


Node * root=NULL;

Node * search(Node * t, DataType k )
{
	if ( !t) return NULL;   // root is null

	Node * current, *next;

	current = t;

	next     = t-> leftchild;

	while( next-> bitpos > current -> bitpos)
	{
		current  = next;

		next     =  ( BITi(k, next->bitpos ) ) ? 
			next->rightchild:  next->leftchild;

	}

	return next; 
}

void insert( Node ** root_d_ptr, DataType k)
{

	printf("To insert "); 
	pvix(k);
	printf("\n"); 

	int differingPos;
	if( ! (*root_d_ptr) ) 
	{
		*root_d_ptr= malloc(sizeof(Node) );
		assert(*root_d_ptr);

		(*root_d_ptr) ->bitpos = 0; 
		(*root_d_ptr) -> key = k;
		(*root_d_ptr) -> leftchild = (*root_d_ptr);
		printf("inserted root:");
		pvix((*root_d_ptr) -> key);

		return ;
	}

	Node * current, * parent, * lastnode, * newnode;

	lastnode = search(  (*root_d_ptr) , k);
	if ( k == lastnode-> key ) 
	{ 
		printf("Duplicate %x\n", k); exit(1); 
	}
	else
	{ 
		printf("Data in last node node is "); 	
		pvix( lastnode->key);
	}


	differingPos = different_bits_pos( k, lastnode->key);
	pviu(differingPos);

	current = (*root_d_ptr) -> leftchild;
	parent  = (*root_d_ptr);

	while( (current-> bitpos > parent -> bitpos) &&   // while((!datanode) and (patricia rule satisfaction) )
			current->bitpos < differingPos) 
	{
		parent = current;

		current = (  BITi( k, current-> bitpos )?
				current->rightchild  : current->leftchild) ; 
	}

	newnode= malloc(sizeof(Node) );
	assert(newnode);

	newnode ->bitpos = differingPos;

	newnode -> key = k;

	newnode -> leftchild = ( BITi(k, differingPos)) ? current: newnode;
	newnode -> rightchild = ( BITi(k, differingPos)) ? newnode: current;

	if ( current == parent -> leftchild)// current will be pointing to datanode so, that is the point of fitting new node in...ie) detach current ptr link and attach to parent.
		parent->leftchild = newnode;
	else
		parent->rightchild = newnode;

	printf("inserted  "); 
	pvix(k);
}
 


 void display_search_result(Node * t, DataType k )
{

	Node * search_result = search (root, k);

	if ( search_result -> key == k)
		printf("Found %#x \n", k);  
	else 
		printf("Not Found %#x \n", k);  
}


int main(int argc, char * argv[])
{


	insert( &root, 0x80000000); 

	insert( &root, 0x00);  

	insert( &root, 0xa0000000); 

	insert( &root, 0x90000000);   

	insert( &root, 0xb0000000);  

	display_search_result (root, 0xa0000000);

	display_search_result (root, 0x90000000);

	display_search_result (root, 0x80000000);


} 
