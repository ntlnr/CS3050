
#include <stdio.h>
#include <stdlib.h>


#define Red 0
#define Black 1
struct RBTreeNode{
    struct RBTreeNode* left;
    struct RBTreeNode* right;
    struct RBTreeNode* parent;
    int color;
    int val;
};

struct RBTreeNode* root = NULL;

RBTreeNode* CreateNode(int val){
    RBTreeNode* Node1;
    Node1 = (RBTreeNode*)malloc(sizeof(struct RBTreeNode));
     Node1->left = NULL;
    Node1->right = NULL;
    Node1->parent = NULL;
    Node1->val = val;
    Node1->color = Red;
    return Node1;
};

void left_rotate(struct  RBTreeNode* treeNode){
	
    RBTreeNode* node1 = treeNode->right;
    treeNode->right = node1->left;
    
    if(node1->left != NULL){
    	 node1-left->parent = x;
	}    
    node1->parent = treeNode->parent;
    
    if(!treeNode->parent){
    	 root = node1;
	}else{
        if(treeNode == treeNode->parent->left){
        	 treeNode->parent->left = node1;
		}
        else{
        	treeNode->parent->right = node1;
		}       
    }
    node1->left = treeNode;
    treeNode->parent = node1;
}

void right_rotate(RBTreeNode* treeNode){
	
    RBTreeNode* node1 = treeNode->left;
    treeNode->left = node1->right;
    
    if(node1->right != NULL){
    	 node1->right->parent = treeNode;
	} 
    node1->parent = treeNode->parent;
    
    if(treeNode->parent != NULL){
    	if(treeNode == treeNode->parent->right){
        	treeNode->parent->right = node1;
		}else{
        	treeNode->Parent->Left = node1;
		}
	}else {
        root = node1;
    }
    node1->right = treeNode;
    treeNode->Parent = node1;
}


void insert (RBTreeNode* treeNode){
    RBTreeNode* node1 = root;
    RBTreeNode* node2 = NULL;
    
    while (node1 != NULL){
        node2 = node1;
        if(treeNode->val < node1->val){
        	 node1 = node1->left;
		}else{
			node1 = node1->right;
		} 
    }
    
    treeNode->parent = node2;
    if(node2 == NULL){
        root = treeNode;
        treeNode->color = Black;
    }
    else {
        if(treeNode->val < node2->val)
            node2->left = treeNode;
        else
            node2->right = treeNode;
    }
    node->color = Red;
    
    fixup(treeNode);
}

void fixup(RBTreeNode* treeNode){
	 struct Node* grandParent = NULL;
    while(treeNode->parent && treeNode->parent->color == Red){
        if(treeNode->parent == treeNode->parent->parent->Left){
           
            grandParent = treeNode->parent->parent->right;
            if(grandParent && grandParent->color == Red){
                treeNode->parent->color = Black;
                y1->color = Black;
                treeNode->parent->parent->color = Red;
                treeNode = treeNode->parent->parent;
            }
        
            else {
                
                if(z == z->Parent->right){
                    z = z->Parent;
                    LeftRotate(Tree, z);
                }
                
                z->Parent->color = 'B';
                z->Parent->Parent->color = 'R';
                rightRotate(Tree, z->Parent->Parent);
            }
        }
        
        else if(z->Parent && z->Parent == z->Parent->Parent->right){
            y1 = z->Parent->Parent->Left;
            // case1
            if(y1 && y1->color == 'R'){
                z->Parent->color = 'B';
                y1->color = 'B';
                z->Parent->Parent->color = 'R';
                z = z->Parent->Parent;
            }
            
            else {
                // transfer case2 to case3
                if(z == z->Parent->Left){
                    z = z->Parent;
                    rightRotate(Tree, z);
                }
                
                z->Parent->color = 'B';
                z->Parent->Parent->color = 'R';
                LeftRotate(Tree, z->Parent->Parent);
            }
        }
    }//while
    Tree->Root->color = 'B';
}
void InOrderTraversa(struct Node* Node){
    if(Node!= NULL){
        InOrderTraversa(Node->Left);
        printf("%d - %c; ",Node->val,Node->color);
        InOrderTraversa(Node->right);
    }
}

int Max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}


int TreeHeight(struct Node* Node){
    if(Node == NULL)
        return 0;
    else
        return 1 + Max(TreeHeight(Node->Left),TreeHeight(Node->right));
}

int BlackTreeHeight(struct Node* Node){
    if(Node==NULL)
        return 0;
    else{
        if(Node->color == 'R')
            return Max(BlackTreeHeight(Node->Left), BlackTreeHeight(Node->right));
        else
            return 1 + Max(BlackTreeHeight(Node->Left),BlackTreeHeight(Node->right));
    }
    
}

struct Node* MaximumElement(struct Node* Node){
    struct Node* y = Node;
    while(Node){
        y = Node;
        Node = Node->right;
    }
    return y;
}

struct Node* SecondLargestNode(struct T* Tree){
    struct Node* x = MaximumElement(Tree->Root);
    if(x->right)
        return MaximumElement(x->left);
    struct Node* y = NULL;
    y = x->Parent;
    while(y && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

void PrintTree(struct T* Tree){
    InOrderTraversa(Tree->Root);
}

int main() {
    int input;
    printf("Please give a value for a node: (Press non-number to finish input)\n");
    while(scanf("%d",&input)!=0){
        struct Node* node = CreateNode(input);
        Insert(root, node);
        printf("Please input anothervalue:\n");
    }
    
    printf("In-order traversal of the tree:\n");
    PrintTree(rbTree);
    printf("\nThe height of the red and black tree is %d\n", TreeHeight(root));
    printf("The black height of the red and black tree is %d\n", BlackTreeHeight(root));
    printf("The second largest node of the red and black tree is %d\n", SecondLargestNode(rbTree)->val);
    return 0;
}
