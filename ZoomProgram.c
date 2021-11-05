/* A program that stores Zoom ID's so you can later join through this program */

#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "windows.h"

#define ZOOMPATH "start C:\\Users\\Santiago\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Zoom\\Zoom.exe"

const int nameLength=25;
const int maxTopics=8;
const char *filename="topics.txt";
const char *idtopics="IDS.txt";


void editClasses(char (*ptr)[nameLength],int *tCount, char (*idptr)[nameLength], int *idCount);
int countClasses(FILE *ptr);
void printTopics(char (*ptr)[nameLength],int *tCount);
void selectClass(char (*ptr)[nameLength],int *tCount, char (*idptr)[nameLength], int *idCount);

int main(){

    int counter=0;
    FILE *pfile=NULL;
    FILE *idfile=NULL;

    restart:
    //Opening the topics.txt
    pfile=fopen(filename,"r");
    if (pfile==NULL){
        pfile=fopen(filename,"w+");
    }

    //Opening the IDS.txt
    idfile=fopen(idtopics,"r");
    if (idfile==NULL){
        idfile=fopen(idtopics,"w+");
    }

    //Reading in the topics stored
    int IDcount=countClasses(idfile);
    int *pIDcount=&IDcount;


    //Storing the current IDs in memory
    fseek(idfile,0,SEEK_SET);
    char ids[maxTopics][nameLength]; //Array that stores the IDs in strings.
    char (*pids)[nameLength];
    pids=ids; //Pointer to the IDs' array
    for(int x=0;x<IDcount;x++){
        fscanf(idfile,"%s",&ids[x]);
    }
    

    //Reading in the topics stored
    int topicCount=countClasses(pfile);
    int *ptopicCount=&topicCount;

    system("clear");
    printf("You have %d topics stored: \n",topicCount);

    //Storing the current topics in memory
    fseek(pfile,0,SEEK_SET);
    char topics[maxTopics][nameLength]; //Array that stores the topics in strings.
    char (*ptopics)[nameLength];
    ptopics=topics; //Pointer to the topic's array
    for(int x=0;x<topicCount;x++){
        fscanf(pfile,"%s",&topics[x]);
    }


    printTopics(ptopics,ptopicCount);

    
    //Choosing to edit or not
    printf("Do you want to edit the list? (y/n): \n");
    char answer;
    scanf("%c",&answer);
    if (counter>0) scanf("%c",&answer);
    answer=tolower(answer);
    if (answer=='y'){
        fclose(pfile);
        pfile=NULL;
        fclose(idfile);
        idfile=NULL;

        system("clear");

        editClasses(ptopics,ptopicCount,pids,pIDcount);

        //Apply Changes
        pfile=fopen(filename,"w");
        idfile=fopen(idtopics,"w");

        for (int x=0;x<topicCount;x++){
            if(x!=0){ 
                fputc('\n',pfile);
                fputc('\n',idfile);
            }
            fputs((*(ptopics+x)),pfile);
            fputs((*(pids+x)),idfile);
        }
        fclose(pfile);
        pfile=NULL;
        fclose(idfile);
        idfile=NULL;

        counter+=1;
        goto restart;
    }

    else{
        system("clear");
        selectClass(ptopics,ptopicCount,pids,pIDcount);

        INPUT ip;
    
    //#############OPENING ZOOM##############
        (void)system("C:/Users/Santiago/AppData/Roaming/Zoom/bin/Zoom.exe");

   /* //#############SELECTING JOIN MEETING##########

    for (int j=0;j<8;j++){
        //Press "Tab" key
        ip.ki.wVk = 0x09; // virtual-key code for the "CTRL" key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));


        //Release "Tab" Key
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));
    }

        //Press "Enter" key
        ip.ki.wVk = 0x0D; // virtual-key code for the "CTRL" key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));


        //Release "Enter" Key
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));


    //#########PRESSING KEYS#############

        Sleep(5000);
        ip.type=INPUT_KEYBOARD;
        ip.ki.wScan=0;
        ip.ki.time=0;
        ip.ki.dwExtraInfo=0;

        //Press "Ctrl" key
        ip.ki.wVk = 0x11; // virtual-key code for the "CTRL" key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        Sleep(500);

        //Press "V" key
        ip.ki.wVk = 0x56; // virtual-key code for the "V" key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));

        //Releasing "V" key
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT));

        //Press "Ctrl" key
        ip.ki.wVk = 0x11; // virtual-key code for the "CTRL" key
        ip.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &ip, sizeof(INPUT));


        //Release "Ctrl" Key
        ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &ip, sizeof(INPUT)); */
    } 

}



//Function to select a topic
void selectClass(char (*ptr)[nameLength],int *tCount, char (*idptr)[nameLength], int *idCount){

    select:
    printf("Choose the class you want to join: \n");
    printTopics(ptr,tCount);

    int selection=0;
    scanf("%d",&selection);
    selection-=1;

    system("clear");

    printf("You've chosen: %s\nAre you sure you want to join? (y/n)\n",*(ptr+selection));
    char nswer;
    scanf("%c",&nswer);
    scanf("%c",&nswer);
    nswer=tolower(nswer);

    if (nswer=='y'){

        //############COPYING ID TO CLIPBOARD############
        HANDLE hData;//For the data to send to the clipboard
        char szData[15],//phrase
        *ptrData = NULL;//pointer to allow char copying
        strcpy(szData,*(idptr+selection));
        int nStrLen = strlen(szData);//length of phrase
        hData = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE,
        nStrLen + 1);//get handle to memory to hold phrase
        ptrData = (char*)GlobalLock(hData);//get pointer from handle
        memcpy(ptrData,szData,nStrLen + 1);//copy over the phrase
        GlobalUnlock(hData);//free the handle
        OpenClipboard(NULL);//allow you to work with clipboard
        EmptyClipboard();//clear previous contents
        SetClipboardData(CF_TEXT,hData);//set our data
        CloseClipboard();//finished!!
        //#############COPIED########################


    }

    else goto select;

}







//Function to count the amount of topics stored
int countClasses(FILE *ptr){

    int topicCount=0;
    for(char ch=fgetc(ptr);ch!=EOF;ch=fgetc(ptr)){
        if(ch=='\n'){
            topicCount++;

        }
    }

    topicCount+=1;
    return topicCount;

}

//Function to print the topics
void printTopics(char (*ptr)[nameLength],int *tCount){

    for(int x=0;x<(*tCount);x++){
        printf("%d)",(x+1));
        printf("%s\n",*(ptr+x));
    }

}

//Function to edit classes
void editClasses(char (*ptr)[nameLength],int *tCount, char (*idptr)[nameLength], int *idCount){
    int option=0;
    printf("To edit a topic type \"1\", to add a topic type \"2\", to delete a topic type \"3\": \n");
    scanf("%d",&option);

    //Edit a topic
    if(option==1){
        printf("Choose one of the %d topics to rename or change ID: \n",(*tCount));
        printTopics(ptr,tCount);

        int selection=0;
        scanf("%d",&selection);
        selection-=1;

        //Editing topic name
        printf("You've chosen: %s\n",*(ptr+selection));
        printf("Type in the new name: \n");
        scanf("%s",(ptr+selection));
        printf("The name has changed to: %s\n",*(ptr+selection));

        //Editing topic ID
        printf("Type in the new ID: \n");
        scanf("%s",(idptr+selection));
        printf("The ID has changed to: %s\n",*(idptr+selection));
    }

    //Add a topic
    else if(option==2){
        //Adding the topic name
        printf("Type in the name of the new topic: \n");
        scanf("%s",(ptr+(*tCount)));
        (*tCount)+=1;

        //Adding the ID
        printf("Type in the ID of the new topic: \n");
        scanf("%s",(idptr+(*idCount)));
        (*idCount)+=1;
    }

    //Delete a topic
    else if(option==3){


        //Deleting the topic
        printf("Choose one of the %d topics to delete: \n",(*tCount));
        printTopics(ptr,tCount);

        int selection=0;
        scanf("%d",&selection);
        selection-=1;
        printf("You've chosen to delete: %s\n",*(ptr+selection));

        char temp[maxTopics][nameLength];
        char tempid[maxTopics][nameLength];
        char (*ptemp)[nameLength];
        char (*ptempid)[nameLength];
        ptemp=temp;
        ptempid=tempid;

        for(int x=0,j=0;x<(*tCount);x++,j++){

            if (x==selection){
                j-=1;
                continue;
            }
            strcpy((*(ptemp+j)),(*(ptr+x)));
            strcpy((*(ptempid+j)),(*(idptr+x)));
        }

        (*tCount)-=1;
        (*idCount)-=1;

        for(int x=0;x<(*tCount);x++){
            strcpy((*(ptr+x)),(*(ptemp+x)));
            strcpy((*(idptr+x)),(*(ptempid+x)));
        }


    }
}