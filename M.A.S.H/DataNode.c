/* 
 * File: DataNode.c
 * Author: Samuel Wasko
 * Date: 31 Oct 2021
 * Description: Represents a DataNode for the game M.A.S.H.
 * This is the implementation of the Methods that come with a DataNode*
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "DataNode.h"

DataNode* CreateDataNode(const char data[]) {
    // exit and tell user if empty string
    if (data == NULL) {
        fprintf(stderr, "Empty String\n");
        return NULL;
    }

    DataNode* newNode = (DataNode*)malloc(sizeof(DataNode));
    if (newNode == NULL) {return NULL;}
    
    //populate node. verify string allocated correctly
    newNode->nextNodePtr = NULL;
    newNode->dataSize = strlen(data);
    int stringSize = newNode->dataSize + 1;
    newNode->dataValue = (char*)malloc(stringSize * sizeof(char));
    
    if (newNode->dataValue == NULL) {
        return NULL;
    }
    strcpy(newNode->dataValue, data);

    return newNode;
}

int InsertDataNodeAfter(DataNode* nodeInList, DataNode* newNode) {
    //if either node is null, non-zero exit
    if (nodeInList == NULL || newNode == NULL) {
        return -1;
    }

    //insert into list
    newNode->nextNodePtr = nodeInList->nextNodePtr;
    nodeInList->nextNodePtr = newNode;
    return 0;
}

int SetNextDataNode(DataNode* nodeInList, DataNode* newNode) {
    //make sure exists
    if (nodeInList == NULL) {
        return -1;
    }
    nodeInList->nextNodePtr = newNode;
    return 0;
}

DataNode* GetNextDataNode(DataNode* nodeInList) {
    //make sure exists
    if (nodeInList == NULL) {
        return NULL;
    }
    return nodeInList->nextNodePtr;
}

void PrintDataNode(DataNode* thisNode) {
    //make sure exists
    if (thisNode == NULL) {
        return;
    }
    printf("%s", thisNode->dataValue);
}

void DestroyDataNode(DataNode* thisNode) {
    free(thisNode->dataValue);
    free(thisNode);
}

DataNode* BuildDataList(char * data[], int numElements) {
    DataNode* headNode = NULL;
    DataNode* newNode = NULL;
    DataNode* currNode = NULL;

    //loop to build list
    for (int i = 0; i < numElements; i++) {
        //create node
        newNode = CreateDataNode(data[i]);
        //make sure exists
        if(newNode == NULL) {
            DestroyDataList(headNode);
            return NULL;
        }
        //if first node, set as head and skip to next iteration
        if (i == 0) {
            headNode = newNode;
            currNode = newNode;
            continue;
        }
        //add to end of list (next iterations)
        SetNextDataNode(currNode, newNode);
        currNode = newNode;
    }
    //ptr to headNode
    return headNode;
}

int GetDataListSize(DataNode* listHead) {
    int listSize = 0;
    DataNode* currNode = listHead;
    
    if (listHead == NULL) {
        return -1;
    }
    while (currNode != NULL) {
        listSize++;
        currNode = currNode->nextNodePtr;
    }
    return listSize;
}

void PrintDataList(DataNode *listHead) {
    DataNode* currNode = listHead;
    while(currNode != NULL) {
        PrintDataNode(currNode);
        //format "," or new-line
        currNode = currNode->nextNodePtr;
        if (currNode == NULL) {
            printf("\n");
        }
        else {
            printf(", ");
        }
    }
}

DataNode* GetRandomDataNode(DataNode *listHead) {
    int randNode = -1;
    int listSize = GetDataListSize(listHead);

    if (listHead == NULL) {
        return NULL;
    }

    randNode = rand() % listSize;
    //check if valid node
    if(randNode < 0 || randNode >= listSize) {
        return NULL;
    }
    //check if index zero
    if (randNode == 0) {
        return listHead;
    }

    DataNode* currNode = listHead;
    for (int i = 0; i < randNode; i++) {
        currNode = currNode->nextNodePtr;
    }
    return currNode;
}

void DestroyDataList(DataNode* listHead) {
    DataNode* currNode = listHead;
    // destroy nodes
    while (listHead != NULL) {
        listHead = listHead->nextNodePtr;
        DestroyDataNode(currNode);
        currNode = listHead;
    }
}