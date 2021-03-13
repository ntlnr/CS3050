#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct FriendNode{
    char *firstName;
    struct FriendNode *prev, *next;
}FriendNode;


typedef struct HashNode{
    int key, index;
    char *name;
    struct FriendNode* frd;
    struct HashNode *next;
}HashNode;


typedef struct Hash {
    struct HashNode* head;
    int elements;
}Hash;

void displayMenu();
HashNode* initHashNode(int key, int hashIndex, char* val);
FriendNode* initFriendNode(char* friendname);
HashNode* locateHash(char* target, Hash* hashTable, int size);
void deleteFriend(HashNode* node, char* FriendName);
void connectFriend(HashNode* node, FriendNode* Friend);
int keyHelper(char* val);

