#include "ftp.h"

struct stat st = {0};

int make_directory(char *directory) {

    /*
        Objective:      To make a directory when Ftp-client requests 
                                MKD <path-to-new-directory>
        Return Type:    Integer
                            return 336: Directory Created
                            return 337: Directory already exists
                            return 338: Directory can't be created
        Parameter:      
            char *directory: path of directory to be created
        Approach:       checking existence of directory using 'stat' function
                        and creating directory using 'mkdir' 

    */

    strtok(directory, "\n");    // to remove trailing '\n'
    int status = stat(directory, &st);
    
    if (status == -1) {
        mkdir(directory, 0700);
        return 336;
    }

    if (status == 0) 
        return 337;

    return 338;
}