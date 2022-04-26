//
//  main.c
//  Binary Search Tree
//
//  Created by  👻 on 20/04/2022.

#include<stdio.h>
#include<stdlib.h>

struct NODE
{
        int Data;
        struct NODE *leftChild;
        struct NODE *rightChild;
};
//========================================================
//==========  I N S E R T   V A L U E    =================
//========================================================
struct NODE *INSERT(struct NODE *pointer_, int inputData)
{
        if(pointer_==NULL)
        {
                pointer_ = (struct NODE *) malloc(sizeof(struct NODE));
                pointer_->Data = inputData;
                pointer_->leftChild = NULL;
                pointer_->rightChild = NULL;
        }
        else if(inputData < pointer_->Data)//-------> Recursively calling left subtree
                pointer_->leftChild = INSERT(pointer_->leftChild, inputData);
        else if(inputData >= pointer_->Data)//-------> Recursively calling right subtree
                pointer_->rightChild = INSERT(pointer_->rightChild, inputData);
        else
                printf("\nError Error\n");
        return pointer_;
}
//=======================================================
//==========   S E A R C H      P A R E N T   ===========
//=======================================================
void PARENT(struct NODE* ptr,int val, int parent)
{
    if (ptr == NULL)
        return;
    if (ptr->Data == val) {
        if (parent==-1)
        {
        printf("%d is root node",val);
        }
        else
        printf("The parent of %d is %d",val,parent);
    }
    else {
        PARENT(ptr->leftChild, val, ptr->Data);
        PARENT(ptr->rightChild, val, ptr->Data);
    }
}
//=======================================================
//============ BONUS TASK : DELETE NODE =================
//=======================================================
struct NODE *DELETE(struct NODE *pointer_, int inputData)
{
        struct NODE *duumyPTR, *yesFound;
        if( pointer_ == NULL)
        {
                printf("\nError Error\n");
                return(pointer_);
        }
        if( inputData < pointer_->Data )//-------> Recursively calling left subtree
                pointer_->leftChild = DELETE(pointer_->leftChild, inputData);
        else if( inputData > pointer_->Data )//-------> Recursively calling right subtree
                pointer_->rightChild = DELETE(pointer_->rightChild, inputData);
        else
        {
                if( pointer_->leftChild!=NULL  &&  pointer_->rightChild!=NULL )
                    //------>found will be deleted
                {
                        yesFound=pointer_->rightChild;
                        while(yesFound->leftChild)
                                yesFound=yesFound->leftChild;
                        pointer_->Data=yesFound->Data;
                        pointer_->rightChild = DELETE(pointer_->rightChild, yesFound->Data);
                }
                else
                {
                        duumyPTR = pointer_;
                        if( pointer_->leftChild != NULL )
                                pointer_ = pointer_->leftChild;
                        else if( pointer_->rightChild != NULL)
                                pointer_ = pointer_->rightChild;
                        else
                                pointer_ = NULL;
                        free(duumyPTR);
                }
        }
        return pointer_;
}

void LIST(struct NODE *ptr)
{
        if(ptr == NULL )
                return;
        LIST(ptr->leftChild);
        printf("%d  ",ptr->Data);
        LIST(ptr->rightChild);
}


int main( )
{
        struct NODE *root=NULL;
        int choice,k;
    
//        UNIT TESTING
//        root = INSERT(root, 31);
//        root = INSERT(root, 65);
//        root = INSERT(root, 3);
//        root = INSERT(root, 10);
//        root = INSERT(root, 5);
//        root = INSERT(root, 100);
//        root = INSERT(root, 3);
//        root = INSERT(root, 12);
//        printf("\n");
//        LIST(root);
//        printf("\n");
//        root = INSERT(root, 55);
//        printf("\n");
//        PARENT(root, 100, -1);
//        printf("\n");
//        LIST(root);
//        printf("\n");
//        root = DELETE(root, 65);
    
    
        while(1)
        {
                printf("\n\n\n\t<=====BINARY SEARCH TREE=====>\n");
                printf("\t1.Construct List\n");
                printf("\t2.Insert a single Element\n");
                printf("\t3.LIST values\n");
                printf("\t4.Search Parent\n");
                printf("\t5.Delete Element\n");
                printf("\t6.Exit\n");
                printf("\n\tInput your choice : ");
                scanf("%d",&choice);

            if (choice==1){
                printf("\nhow many elements you want to construct tree : ");
                scanf("%d",&k);
                int val=0;
                int i=0;
                for (i=0; i<k; i++) {
                    printf("\nEnter value : ");
                    scanf("%d",&val);
                    root=INSERT(root, val);
                }
                printf("Tree Constructed Successfully");
            }
            else if (choice==2)
            {
                printf("\nEnter the key to insert: ");
                scanf("%d",&k);
                INSERT(root, k);
                PARENT(root, k, -1);
            }
            else if (choice==3)
            {
                LIST(root);
            }
            else if (choice==4)
            {
                printf("\nEnter the key to search its parent: ");
                scanf("%d",&k);
                PARENT(root, k, -1);//-1 to start from root node
                
            }
            else if (choice==5)
            {
                printf("\nEnter the key to be deleted : ");
                scanf("%d",&k);
                root = DELETE(root,k);
                printf("Deleted Successfully");
            }
            else if (choice==6)
            {
                exit(1);
            }
            else
            printf("\nWrong choice\n");
        }
        return 0;
}
