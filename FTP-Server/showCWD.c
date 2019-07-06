#include "ftp.h"

char pwdbuf[256];

int show_cwd() {

    /*
        Objective:      To display the current working directory path
        Return Type:    Integer
                            return 342: Error in getting the current working directory.
                            return 343: specifies the current working directory path
        Parameter:      None
        Approach:       perform using getcwd().
    */
    if(getcwd(pwdbuf, 256) == NULL) 
        return 342;
    strtok(pwdbuf, "\n");    
    return 343;
}