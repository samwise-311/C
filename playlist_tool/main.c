#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "PlaylistNode.h"

void NewLineTrim(char * line);

char playlistName[50] = "";


void PrintMenu(char userName[])
{
   //charCount = GetNumOfNonWSCharacters(userString);
   //wordCount = GetNumOfWords(userString);
   

   printf("\n%s PLAYLIST MENU\n", userName);
   printf("a - Add song\n");
   printf("r - Remove Song\n");
   printf("c - Change position of song\n");
   printf("s - Ouput songs by specific artist\n");
   printf("t - Output total time of playlist (in seconds)\n");
   printf("o - Output full playlist\n");
   printf("o - Output full playlist\n");
   printf("q - Quit\n\n");
   printf("Choose an option:\n");
}

int main(void) {

    char menuChoice;
    const int NUM_SONGS = 5;
    char songName[50] = "";
    char artistName[50] = "";
    char id[50] = "";
    int length = 0;
   PlaylistNode * headNode = NULL;
    //PlaylistNode * tailNode = NULL;
    PlaylistNode * currentNode = NULL;

    printf("Enter playlist's title:\n");
    fgets(playlistName, 50, stdin);
    NewLineTrim(playlistName);

    PrintMenu(playlistName);
    scanf("%c", &menuChoice);


/* while statements declaring menu option choices */
while (menuChoice != 'q') {
   switch (menuChoice) {
      case 'q':
         return 0;
         break;

      case 'a':
        printf("ADD SONG\n");
        printf("Enter song's unique ID:\n");
        scanf(" %c", id);
        fgets(id, 50, stdin);
        NewLineTrim(id);

        printf("Enter song's name:\n");
        fgets(songName, 50, stdin);
        NewLineTrim(songName);

        printf("Enter artist's name:\n");
        fgets(artistName, 50, stdin);
        NewLineTrim(artistName);

        printf("Enter song's length:\n");
        scanf(" %d", &length);
        
       currentNode = CreatePlaylistNode(id, songName, artistName, length);

        PrintMenu(playlistName);
        scanf(" %c", &menuChoice);        
        break;
    
      case'r':
      currentNode = headNode;
        printf("REMOVE SONG\n");
        printf("Enter song's unique ID:\n");
        fgets(id, 50, stdin);
        DestroyPlaylistNode(currentNode);
        printf("destroyed!");
        PrintMenu(playlistName);
        scanf(" %c", &menuChoice);
        break;
      
      case 'c':
         printf("c chosen");
         PrintMenu(playlistName);
         scanf(" %c", &menuChoice);
         break;

      case 's':
         printf("s chosen");
         PrintMenu(playlistName);
         scanf(" %c", &menuChoice);
         break;

      case 't':
         printf("t chosen");
         PrintMenu(playlistName);
         scanf(" %c", &menuChoice);
         break;
        
      case 'o':
        printf("JAMZ - OUPUT FULL PLAYLIST\n");
        currentNode = CreatePlaylistNode(id, songName, artistName, length);

        if (length == 0){
            printf("Playlist is empty\n\n");
            PrintMenu(playlistName);
            scanf(" %c", &menuChoice);
            break;
        }
            for (int i = 0; i < NUM_SONGS; i++) {
                printf("%d.\n", i+1);
                PrintPlaylistNode(currentNode);
                i++;
                printf("\n\n");
        }
        PrintMenu(playlistName);
        scanf(" %c", &menuChoice);
        break;

      default:
        printf("Error: Unknown option selected\nTRY AGAIN\n");
        PrintMenu(playlistName);
        scanf("%c", &menuChoice);
      break;
    }
}

}

/*NewLineTrim: Remove the trailing newLine
 * character from strings returned from fgets.
 * line - NULL terminated string
 */
 void NewLineTrim(char * line) {
    size_t lineLength;

    /* validate parameter */
    if (line == NULL) {
       return;
    }
    lineLength = strlen(line);
    if (line[lineLength - 1] == '\n') {
       line[lineLength - 1] = '\0';
    }
 }
