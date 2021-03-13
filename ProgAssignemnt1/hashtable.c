#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashtable.h"

void displayMenu(){
    printf("\nCommand List:");
    printf("\nP <name> : Create a person record of the specified first name");
    printf("\nF <name1> <name2> : Record that the two specified people are friends");
    printf("\nU <name1> <name2> : Record that the two specified people are no longer friends");
    printf("\nL <name> : Print out the friends of the specified person");
    printf("\nQ <name1> <name2> : Check whether the two people are friends");
    printf("\nX : Terminate the program\n");
}

HashNode* initHashNode(int key, int index, char* val){
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->next = NULL;
    node->frd = NULL;
    node->name = val;
    node->index = index;
    node->key = key;
    return node;
}

FriendNode* initFriendNode(char* friendname){
    FriendNode* node = (FriendNode*)malloc(sizeof(FriendNode));
    node->prev = NULL;
    node->next = NULL;
    node->firstName = friendname;
    return node;
}

HashNode* locateHash(char* target, Hash* hashTable, int size){
    if(hashTable == NULL || size == 0 || target == NULL){
        return NULL;
    }

    int key = keyHelper(target);
    int index = key % size;
    HashNode* node = hashTable[index].head;

    if(node == NULL){    //There is no such hash index for such name
        return NULL;
    }

    bool temp = false;
    while(node != NULL){    //Traverse the Linked list for the specific hash index 
        if(strcmp(target, node->name) == 0){     
            temp = true;
            break;
        }
        node = node->next;
    }

    if(!temp){
        return NULL;   //If none of the hash index nodes has the target name.
    }
    return node;
}

void deleteFriend(HashNode* node, char* FriendName){     //Given one hashnode and one friendnode, then this function will delete the friend from the friend linked list    
    FriendNode* Friend = node->frd;
	while(Friend != NULL){
		if(strcmp(Friend->firstName, FriendName) == 0){
			if(Friend->prev == NULL){
				node->frd = Friend->next;
				Friend->next->prev = NULL;
			}else{
			    Friend->prev->next = Friend->next;
        		if(Friend->next != NULL){
           			Friend->next->prev = Friend->prev;
				}
			}
		}
		Friend = Friend->next;
	} 
    free(Friend);
    return;
}

void connectFriend(HashNode* node, FriendNode* Friend){  //Given one hashnode and one friendnode, then this function will add the friend to the friend linked list
	if(node->frd != NULL){
		Friend->next = node->frd;
        node->frd->prev = Friend;
        node->frd = Friend;
        
    }else{
        node->frd = Friend;
    }
    return;
}

int keyHelper(char* val){
    int k = 0;
    int i;
	for (i = 0; i < (int)strlen(val); i++){
		k = k + val[i] + 1;
	}
	return k;
}
