#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"

int main(){
    displayMenu();
    int size = 26; 
    char command = '0';
    Hash* hashtable = (Hash*)calloc (size, sizeof(Hash));
    
    while(command != 'X'){
        scanf("%c", &command);

        switch(command){
            case 'P':{
            	getchar();
                char* name = (char*)calloc(50, sizeof(char));
                scanf("%s",name);
                int key = keyHelper(name);
                int hashIndex = key % size;
                HashNode* node = initHashNode(hashIndex, key, name);

                if(hashtable[hashIndex].head == NULL){
                    hashtable[hashIndex].head = node;
                    hashtable[hashIndex].elements = 1;
                    break;
                }else{
                    node->next = hashtable[hashIndex].head;
                    hashtable[hashIndex].head = node;
                    hashtable[hashIndex].elements++;
                    break;
                }
            }

            case 'F':{
            	getchar();
                char* name1 = (char*)calloc(50, sizeof(char));
                char* name2 = (char*)calloc(50, sizeof(char));
                scanf("%s %s",name1, name2);
                int key1 = keyHelper(name1);
                int key2 = keyHelper(name2);

                HashNode* node1 = locateHash(name1, hashtable, size);
                if(node1 == NULL){
                     printf("%s is not recorded in the system", name1);
                     break;
                }
                FriendNode* friend1 = initFriendNode(name2);
                if(friend1 == NULL){
                    printf("The memory allocation failed");
                    break;
                }
                connectFriend(node1, friend1);
                
                HashNode* node2= locateHash(name2, hashtable, size);
                FriendNode* friend2 = initFriendNode(name1);
                if(friend2 == NULL){
                    printf("The memory allocation failed");
                    break;
                }
                connectFriend(node2, friend2);
                break;  
            }
            
            case 'L':{
            	getchar();
            	char *name = (char *)calloc(50, sizeof(char));
                scanf("%s", name);
                HashNode* node = locateHash(name, hashtable, size);
                if(node != NULL){
                    FriendNode* Friend = node->frd;
                    if(Friend == NULL){
                    	printf("The user does not have any friend in this system");
					}
                    while(Friend != NULL){
                        printf("%s ", Friend->firstName);
                        Friend = Friend->next;
                    }
                }else{
                	printf("The provided user does not exist in this system");
				}
				break;
			}
			
			case 'U':{
                getchar();
                char *name1, *name2;
                name1 = (char *)calloc(50, sizeof(char));
                name2 = (char *)calloc(50, sizeof(char));
                scanf("%s %s",name1,name2);
                
                int key1 = keyHelper(name1);
                int key2 = keyHelper(name2);
                
                HashNode* Node1 = locateHash(name1, hashtable, size);
                if(Node1 == NULL){
                	 printf("%s is not recorded in the system", name1);
                     break;
				}
                FriendNode* Friend1 = locateFriend(Node1, name2);
                if(Friend1 == NULL){
                	printf("These two persons are not friends");
                	break;
				}
                deleteFriend(Node1,Friend1);
                
                
                HashNode* Node2 = locateHash(name2, hashtable, size);
                if(Node2 == NULL){
                	 printf("%s is not recorded in the system", name2);
                     break;
				}
                FriendNode * Friend2 = locateFriend(Node2, name1);
                deleteFriend(Node2,Friend2);
                
                break;
            }
            
             case 'Q':{
                getchar();
                char *name1, *name2;
                name1 = (char *)calloc(50, sizeof(char));
                name2 = (char *)calloc(50, sizeof(char));
                scanf("%s %s",name1, name2);
                
                HashNode* node;
                node = locateHash(name1, hashtable, size);
                FriendNode* Friend = locateFriend(node, name2);
                if(Friend == NULL)
                    printf("NO\n");
                else
                    printf("YES\n");
                break;
            }
            
            default:
                break;
        }
        char a;
        while(a != '\n' && (a = getchar()) != EOF );
        printf("\n");
    }
    return 0;
}
