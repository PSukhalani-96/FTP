#include "ftp.h"

int exit_service() {

    /*
        Objective:      To exit/stop the service of Ftp-Server.
        Return Type:    Integer
                            return 351:     Terminate Successfully.
                            return 352:     Data Transfer in progress and after completion of transfer
                                            terminate the connection.
        Parameter:      None
        Approach:       perform by choosing a random number,
                            random-No 0: states that no data transfer in progress, directly terminate 
                                         the connection.
                            random-No 1: states that data transfer is in progress, wait for completion
                                         of transfer and then terminate the connection.
    */

    srand(time(NULL)); 
    int no = (rand()%2);
    if (logged_in)
        printf(">> Client %s is successfully logged out.\n", USERNAME[count]);

    logged_in = false;
    user_done = false;
    if (no == 0) 
        return 351;
    return 352;
    
}

int abort_service() {

    /*
        Objective:      To abort the Ftp-Service.
        Return Type:    Integer
                            return 226: abort command is successfully processed.
                            return 426: Request Action Aborted. Data service aborted abnormally.
        Parameter:      None
        Approach:       perform by choosing a random number,
                            random-No 0: states that no data transfer in progress,abnormally terminate 
                                         the connection.
                            random-No 1: states that data transfer is in progress, abnormally abort the
                                         service and terminate the connection.

    */

    srand(time(NULL)); 
    int no = (rand()%2);
    if (logged_in)
        printf(">> Client %s is abnormally logging out.\n", USERNAME[count]);

    logged_in = false;
    user_done = false;
    if (no == 0) 
        return 226;

    return 426;
}