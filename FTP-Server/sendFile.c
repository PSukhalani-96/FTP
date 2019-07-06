#include "ftp.h"

char file[1024];

int send_file(char * filename) {

    /*
        Objective:      To send the requested file from Server to Client and storing it in
                        Client-side.
        Return Type:    Integer
                            return 347: file does not exist.
                            return 348: error opening file
                            return 0  : file sent successfully.
        Parameter:
            char *filename: specifies the requested filename
        Approach:       performed by opening the requested file at server side and
                        transferring/storing it to Client side.
    */

    strtok(filename, "\n");
    
    char ch;
	FILE *fp1;
    
    if((fp1 = fopen(filename, "r")) == NULL) {
        if(errno == ENOENT) {
            return 347;
        }
        return 348;
    }
    
    int k = 0;
    ch = fgetc(fp1);
    while (ch != EOF) {
        file[k] = ch;
        k++;
        ch = fgetc(fp1);
    }
    file[k] = '\0';

    return 0;
}