#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    node* temp = head;
    int counter = 0;
    if (temp == NULL)
        return 0;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function will return "abc"
char* toCString(node* head) {
    node* temp = head;
    int nodeLength = length(head);
    char* string = (char*) malloc(sizeof(char) * (nodeLength + 1));
    char* error = "error";
    if (temp == NULL)
        return error;
    for (int i = 0; i < nodeLength; i++) {
        string[i] = temp->letter;
        temp = temp->next;
    }
    string[nodeLength] = '\0';
    return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {
    node* temp = *pHead;
    node* NewNode = (node*) malloc(sizeof(node));
    if (NewNode == NULL) 
        return;
    NewNode->letter = c;
    NewNode->next = NULL;
    if(*pHead == NULL){
        *pHead = NewNode;
    }
    else{
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = NewNode;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {
    node* temp = *pHead;
    while (temp != NULL) {
        *pHead = temp->next;
        free(temp);
        temp = *pHead;
    }
    *pHead = NULL;
}

int main(void) {
    int strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);//what does this line do? i understand you're using the input from the entire file input.txt
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);//so, what does this line do?
        for (int i = 0; i < strLen; i++) {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);//from what i'm understanding, it's trying to take each char of the file
        }

        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);

        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
}