#include "ftp.h"

int change_directory(char *directory) {

    /*
        Objective:      To change the working directory when Ftp-Client requests
                                CWD <path-of-directory>
        Return Type:    Integer
                            return 339: Permission Denied(Path can't be changed).
                            return 340: Invalid directory
                            return 341: could not change directory.
                            return 0  : Path changed successfully.
        Parameter:      
            char *directory: path of directory to be changed.
        Approach:       changing the currently working directory using 'chdir-function'
    */          

    // ENOENT : No such directory entry

    strtok(directory, "\n");
    if(chdir(directory) == -1) {
        if(errno == EACCES) 
            return 339;
        else if(errno == ENOTDIR || errno == ENOENT) 
            return 340;
        
        else 
            return 341;
    }
    return 0;
}