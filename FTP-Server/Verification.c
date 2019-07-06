#include "ftp.h"

/*-----------------------------------------------------------------------------------------------------------------------------*/
char USERNAME[10][100] = {"ABCDEF", "GHIJKL", "MNOPQR", "STUVWX" , "YZABCD", "123456", "234567", "345678", "910111", "121314"};
char PASSWORD[10][100] = {"123456", "ABCDEF", "456789", "GHIJKL" , "987654", "MNOPQR", "151617", "STUVWX", "181920", "YZABCD"};
/*-----------------------------------------------------------------------------------------------------------------------------*/

bool user_done = false;
bool logged_in = false;

int verify_username(char *username) {

    /*
        Objective:      To verify username
        Return Type:    Integer
                            return 331: if username matches with USERNAME
                            return 300: if username does not match with USERNAME
        Parameter:
            char *username: username given by Ftp-Client, when Ftp-Client tries to 
                            logged in(using USER username).
        Approach:       perform using string comparison.
    */   

    for (int i = 0; i < 10; i++) {
        if (strncmp(username,USERNAME[i],6) == 0) {
            user_done = true;
            count = i;
            return 331;
        }
    }
    return 300; 
}

int verify_password(char *password) {

    /*
        Objective:      To verify Password
        Return Type:    Integer
                            return 333: if password matches with PASSWORD
                            return 334: if password does not match with PASSWORD
        Parameter:  
            char *password: password given by Ftp-Client, when Ftp-Client tries to 
                            logged in(using PASS password).
        Approach:       perform using string operator.

    */

    if (strncmp(password, PASSWORD[count],6) == 0) {
        logged_in = true;
        return 333;
    }
    return 334; 
}