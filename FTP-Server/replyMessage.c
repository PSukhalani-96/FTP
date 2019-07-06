#include "ftp.h"

char *reply_message(int status) {

    /*
        Objective:      To generate replies that will be sent to the Ftp-Client depending on 
                        type of command.
        Return Type:    Character Pointer
                            returns the reply message.
        Parameter:      
            status:     specifies the status in response to the command/functionality requested
                        by the Ftp-client.
        Approach:       simple comparison 
    */

    if(status == -1)
        return "Reply[450]: Invalid Arguments.";

    if (status == 300)
        return "Reply[300]: Username is not correct.";
    
    if (status == 331)
        return "Reply[200]: Command is Okay.\nReply[331]: Username Okay, Need Password.";

    if (status == 332)
        return "Reply[332]: User already logged in.";

    if (status == 333)
        return "Reply[200]: Command is Okay.\nReply[333]: Password Okay, You are Logged In.";

    if (status == 334)
        return "Reply[334]: Incorrect Password.";

    if (status == 335)
        return "Reply[335]: Need Username before Password.";

    if (status == 336)
        return "Reply[200]: Command is Okay.\nReply[336]: Directory is successfully created.";

    if (status == 337)
        return "Reply[337]: Directory already exists.";

    if (status == 338)
        return "Reply[338]: Directory can't be created. Try again.";

    if (status == 503)
        return "Reply[503]: Bad sequence of Commands.";

    if (status == 530)
        return "Reply[530]: No user logged in.";

    if (status == 339)
        return "Reply[339]: EACCES: Permission Denied.";

    if (status == 340)
        return "Reply[340]: ENOTDIR OR ENOENT: Invalid Directory";

    if (status == 341)
        return "Reply[341]: Could not change Directories.";

    if (status == 342)
        return "Reply[342]: Error in getting the current working directory.";

    if (status == 343) {
        
        static char buf[256];
        char mssg[256] = "Reply[200]: Command is Okay.\nReply[343]: Remote Working Directory: ";
        split(pwdbuf);
        strcat(mssg,pwdbuf);
        strcpy(buf, mssg);
        strcat(buf, "\nCurrent-Working-Directory-Name is : ");
        strcat(buf, file_name);
        return buf;
    }

    if (status == 344)
        return "Reply[200]: Command is Okay.\nReply[344]: Directory successfully removed.";

    if (status == 345)
        return "Reply[345]: Directory can't be removed(Directory may not exists).";

    if (status == 346)
        return "Reply[346]: Error in opening directory.";

    if (status == 347)
        return "Reply[347]: Invalid Filename: File does not exist.";

    if (status == 348)
        return "Reply[348]: Error opening file.";

    if (status == 349)
        return "Reply[349]: Error writing to data socket.";

    if (status == 350)
        return "Reply[350]: Error reading from file.";

    if (status == 226)
        return "Reply[100]: User Logged Out.\nReply[226]: Abort command is successfully processed.";

    if (status == 426)
        return "Reply[551]: Request Action Aborted.\nReply[100]: User Logged Out.\nReply[426]: Service requested aborted abnormally.\nReply[226]: Abort command is successfully processed.";

    if (status == 351)
        return "Reply[351]: Terminate Successfully...Logged Out...Good Bye!!!"; 

    if (status == 352)
        return "Reply[352]: Data Transfer In Progress.\nWaiting...\nWaiting...\nWaiting...\nReply[351]: Terminate Successfully...Logged Out...Good Bye!!!";

    if (status == 502)  
        return "Reply[502]: Command not implemented.";

    if (status == 600)
        return "Reply[600]: Need Password.";

    if (status == 535)
        return "Reply[530]: No user logged in.\nReply[535]: Terminating Session !!!";

    return "Reply[504]: Command not implemented for this parameter.";

}