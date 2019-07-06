#include "ftp.h"

char file_name[100];
void split(char *pathname) {

    /*
        Objective:      To extract the filename from the pathname
        Return Type:    void(null)
        Parameter:
            char *pathname: specifes pathname from which filename to be extracted.
        Approach:       perform using string traversal and delimiting it by '/'       
    */

    char splitStrings[10][10]; 
    int i,j,cnt;
    
    j=0; cnt=0;
    for(i=0;i<=(strlen(pathname));i++)
    {
        if( pathname[i]=='/'||pathname[i]=='\0' )
        {
            splitStrings[cnt][j]='\0';
            cnt++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            splitStrings[cnt][j]=pathname[i];
            j++;
        }
    }
    strcpy(file_name, splitStrings[cnt-1]);
    file_name[strlen(file_name)] = '\0';
}

int store_file(char *pathname) {

    /*
        Objective:      To store the file sent by client at the server side.
        Return Type:    Integer
                            return 0:   succesfully stored file at server side.
        Parameter:      
            char *pathname: specifies the path of the file present at client side
                            i.e. to be stored at server side.
        Approach:       performed by opening the file at client side and storing it
                        at the server side(server Directory) by copying the contents.      
    */

    char buf[1024];
    char res[1024];
    recv(newSocket, buf, MAXLINE, 0);

    if (strncmp(buf,"NULL",4) == 0) {
        printf(">> Invalid File-Name to Store.\n");
        return -1;
    }

    strcpy(res, buf);
    bzero(buf, sizeof(buf));

    split(pathname);
    strtok(pathname,"\n");
    char dest[256];
    getcwd(dest,256);
    strcat(dest,"/");
    strtok(file_name,"\n");
    strcat(dest, file_name);
    dest[strlen(dest)] = '\0';

    FILE *fp1;
    fp1 = fopen(dest, "w");
    fprintf(fp1,"%s",res);
    fclose(fp1);
    
    printf("\n-----------------------------------------------------------------------");
    printf("\n>> File Received Successfully by client - %s.", USERNAME[count]);
    printf("\n>> File Saved in Path %s",dest);
    printf("\n>> File Name: %s",file_name);
    printf("\n>> File Size: %ld bytes\n", strlen(res));
    printf("-----------------------------------------------------------------------\n");
    
    return 0;
}