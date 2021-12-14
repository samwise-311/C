/* 
 * File: PlaylistNode.c
 * Author: Samuel Wasko
 * Date: 24 Oct 2021
 * Description: This is a modified version of the ContactNode lab activity
 *    provided by zyBooks.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "PlaylistNode.h"


#define CONTACT_FIELD_SIZE 50

PlaylistNode* CreatePlaylistNode(char id[], char songName[], char artistName[], int songLength) {

    PlaylistNode * thisNode = (PlaylistNode *) malloc(sizeof(PlaylistNode));

 if(thisNode == NULL) {
      return NULL;
   }

strncpy(thisNode->uniqueID, id,CONTACT_FIELD_SIZE);
strncpy(thisNode->songName, songName,CONTACT_FIELD_SIZE);
strncpy(thisNode->artistName, artistName,CONTACT_FIELD_SIZE);
//strncpy(thisNode->songLength, songLength,CONTACT_FIELD_SIZE);
thisNode->songLength = songLength;
thisNode->nextNodePtr = NULL;

   return thisNode;
}

int InsertPlaylistNodeAfter(PlaylistNode* nodeInList, PlaylistNode* newNode) {
    PlaylistNode* tmpNext = NULL;


   /* Validate parameters */
   if (nodeInList == NULL || newNode == NULL) {
      return -1;
   }

   //splicing new node in
   tmpNext = nodeInList->nextNodePtr;
   nodeInList->nextNodePtr = newNode;
   newNode->nextNodePtr = tmpNext;

   return 0;
}

int SetNextPlaylistNode(PlaylistNode* nodeInList, PlaylistNode* newNode) {
    nodeInList = NULL;
    newNode = NULL;
    InsertPlaylistNodeAfter(nodeInList, newNode);
    printf("TODO: finish function logic!!\n set next playlist node\n");
    return 0;
}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* nodeInList) {
    /* Validate parameters */
   if (nodeInList == NULL) {
      return NULL;
   }
   return nodeInList->nextNodePtr;
}

void PrintPlaylistNode(PlaylistNode* thisNode) {
     /* Validate parameters */
   if (thisNode == NULL) {
      printf("All nodes are NULL");
      return;
   }
   printf("Unique ID: %s\n", thisNode->uniqueID);
   printf("Song Name: %s\n", thisNode->songName);
   printf("Artist Name: %s\n", thisNode->artistName);
   printf("Song Length (in seconds): %d", thisNode->songLength);

   return;
}

void DestroyPlaylistNode(PlaylistNode* thisNode) {
    /* Validate parameters */
    if (thisNode == NULL) {
        return;
    }
    free(thisNode);
}



