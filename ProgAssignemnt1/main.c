#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"

int main(){
    int size = 26; 
    char command;
    Hash* hashtable = (Hash*)calloc (size, sizeof(Hash));
    
    displayMenu();
    
	do{
        command = getchar();

        switch(command){
            case 'P':{
            	getchar();
                char* userName = (char*)calloc(50, sizeof(char));
                scanf("%s",userName);
                int index = keyHelper(userName) % size;
                HashNode* node = initHashNode(index, keyHelper(userName), userName);

                if(hashtable[index].head != NULL){
                	node->next = hashtable[index].head;
                    hashtable[index].head = node;
                    hashtable[index].elements++;
                    break;
                    
                }else{
                   hashtable[index].head = node;
                    hashtable[index].elements = 1;
                    break;
                }
            }

            case 'F':{
            	getchar();
                char* n1 = (char*)calloc(50, sizeof(char));
                char* n2 = (char*)calloc(50, sizeof(char));
                scanf("%s %s",n1, n2);
                int key1 = keyHelper(n1);
                int key2 = keyHelper(n2);

                HashNode* node1 = locateHash(n1, hashtable, size);
                if(node1 == NULL){
                     printf("%s is not recorded in the system", n1);
                     break;
                }
                FriendNode* friend1 = initFriendNode(n2);
                if(friend1 == NULL){
                    printf("The memory allocation failed");
                    break;
                }
                connectFriend(node1, friend1);
                
                HashNode* node2= locateHash(n2, hashtable, size);
                FriendNode* friend2 = initFriendNode(n1);
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
                char* n1 = (char *)calloc(50, sizeof(char));
                char* n2 = (char *)calloc(50, sizeof(char));
                scanf("%s %s",n1,n2);
                
                int key1 = keyHelper(n1);
                int key2 = keyHelper(n2);
                
                HashNode* Node1 = locateHash(n1, hashtable, size);
                if(Node1 == NULL){
                	 printf("%s is not recorded in the system", n1);
                     break;
				}
                deleteFriend(Node1,n2);
                
                
                HashNode* Node2 = locateHash(n2, hashtable, size);
                if(Node2 == NULL){
                	 printf("%s is not recorded in the system", n2);
                     break;
				}
                deleteFriend(Node2,n1);
                
                break;
            }
            
             case 'Q':{
                getchar();
                char* n1= (char *)calloc(50, sizeof(char));
                char* n2 = (char *)calloc(50, sizeof(char));
                scanf("%s %s",n1, n2);
                
                HashNode* node;
                node = locateHash(n1, hashtable, size);
                if(node == NULL){
                	printf("NO\n");
                	break; 
				}
				FriendNode* Friend = node->frd;
    			while (Friend != NULL) {
        			if (strcmp(Friend->firstName,n2)==0) {
            				break;
        			}
        			Friend = Friend->next;
   				}
                
                if(Friend == NULL){
                	 printf("NO\n");
                	 break; 
				}else{ 
                    printf("YES\n");
                }
                break;
            }
            
            default:
                break;
        }
        char a;
        while(a != '\n' && (a = getchar()) != EOF );
        printf("\n");
    }while(command != 'X'); 
    return 0;
}
