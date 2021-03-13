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

HashNode* initHashNode(int hashIndex, int key, char* val){
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->next = NULL;
    node->frd = NULL;
    node->name = val;
    node->index = hashIndex;
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
    int hashIndex = key % size;
    HashNode* node = hashTable[hashIndex].head;

    if(node == NULL){    //There is no such hashIndex for such name
        return NULL;
    }

    bool temp = false;
    while(node != NULL){    //Traverse the Linked list for the specific hashIndex 
        if(!strcmp(target, node->name)){     
            temp = true;
            break;
        }
        node = node->next;
    }

    if(!temp){
        return NULL;   //If none of the hashIndex nodes has the target name.
    }
    return node;
}

FriendNode* locateFriend(HashNode* node, char* friendName){
    if(node == NULL || friendName == NULL){
        return NULL;
    }

    FriendNode* friendnode = node->frd;
    
    if(friendnode == NULL){    //The specific person does not have any friends.
        return NULL;
    }

    bool temp = false;
    while (friendnode != NULL) {
        if (!strcmp(friendnode->firstName,friendName)) {
            temp = true;
            break;
        }
        friendnode = friendnode->next;
    }
    if(!temp){
        return NULL;   //If there is no friend whose name is the required name.
    }
    return friendnode;
}

void deleteFriend(HashNode* Node, FriendNode* Friend){     //Given one hashnode and one friendnode, then this function will delete the friend from the friend linked list
	if(Friend->prev == NULL){                         //If the friend node is the first node in this doubly linked list
        Node->frd = Friend->next;
        if(Friend->next != NULL){
        	Friend->next->prev = NULL;
		}     
    }else{
	if(Friend->next != NULL){                      //If the friend noed is not the first node in this doubly linked list
            Friend->next->prev = Friend->prev;
	}
        Friend->prev->next = Friend->next;
               
    }
    free(Friend);
    return;
}

void connectFriend(HashNode* Node, FriendNode* Friend){  //Given one hashnode and one friendnode, then this function will add the friend to the friend linked list
	if(Node->frd == NULL){
        Node->frd = Friend;
    }else{
        Friend->next = Node->frd;
        Node->frd->prev = Friend;
        Node->frd = Friend;
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
