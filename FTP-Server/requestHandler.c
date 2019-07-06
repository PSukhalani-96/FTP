#include "ftp.h"

int request_handler(char *arg) {

    /*  
        Objective:      To handle the command requested by user.
        Return type:    Integer
                            return status which corresponds to a reply.
        Parameter:      None
        Approach:       performed using switch-cases, and calling the appropriate functions to
                        service FTP-client request.   
    */
    
    int status = 503;
    switch(command) {
        case USER:
            if (logged_in) 
                status = 332;                
            
            else {
                char username[100];
                strcpy(username,arg);
                status = verify_username(username);
            }
            break;


        case PASS:
            if (logged_in)
                status = 332;
            
            else{ 
                if (user_done)
                    status = verify_password(arg);
                else
                    status = 335;
            }
            break;

        case MKD:
            if (logged_in) 
                status = make_directory(arg);
            
            else {
                if (user_done)
                    status = 600;
                else
                    status = 530;
            }
            break;

        case CWD:
            if (logged_in) {
                status = change_directory(arg);
                if (status == 0) {
                    status = show_cwd();
                }
            }

           else {
                if (user_done)
                    status = 600;
                else
                    status = 530;
            }
            break;

        case RMD:
            if (logged_in) {
                status = remove_directory(arg);
                if (status == 0)
                    status = 344;
                else if (status == -1)
                    status = 345;
            }

            else {
                if (user_done)
                    status = 600;
                else
                    status = 530;
            }
            break;

        case PWD:
            if (logged_in) 
                status = show_cwd();
            else {
                if (user_done)
                    status = 600;
                else
                    status = 530;
            }
            break;

		case LIST:
			if (logged_in)
				status = list_directories();
			else {
                if (user_done)
                    status = 600;
                else
                    status = 530;
            }
			break;

        case RETR:
            if (logged_in) {
                status = send_file(arg);
            }
            else {
                if (user_done)
                    status = 600;
                else
                    status = 530;
            }
            break;  

        case STOR:
            if (logged_in) {
                if (*arg == '\n' || *arg == '\0')
                    status = 347;
                else
                    status = store_file(arg);
            }
            else {
                if (user_done)
                    status = 600;
                else
                    status = 530;
            }
            break;     

        case ABOR:
            if (logged_in)
                status = abort_service();
            else {
                if (user_done)
                    status = 600;
                else
                    status = 530;
            }
            break;    

        case QUIT:
            if(logged_in)
                status = exit_service();
            else {
                status = 535;
            }
            break;

        case CDUP:
            status = 502;
            break;

        case DELE:
            status = 502;
            break;

        case HELP:
            status = 502;
            break;

        case NOOP:
            status = 502;
            break;    
        
    }
    return status;
}