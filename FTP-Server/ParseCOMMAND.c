#include "ftp.h"

int command = INVALID;
char arg[1024];

void parseCommand(char *buf) {

    /*
        Objective:      To Parse Ftp-Client specified command.
        Return Type:    void(null)
        Parameter:  
            char *buf:  contains user-command.
        Approach:       buf is divided into two parts:
                        1st part:   <command-name>
                        2nd part:   <argument-name>
                        
                        this function parses the whole command,
                        -   if <command-name> matches with valid command as specified 
                            above(#define), command = <command-name>
                        -   else 
                                command = INVALID.
                        If command name is Valid remaining part of the buf becomes 
                        argument.
                            arg = buf.

    */
    
    command = INVALID;

	while(*buf == ' ' || *buf == '\t') {
        buf++;
    }

	if( strncmp(buf,"USER ",5) == 0  || strncmp(buf,"user ",5) == 0  ||
    	strncmp(buf,"USER\t",5) == 0 || strncmp(buf,"user\t",5) == 0 ||
    	strncmp(buf,"USER\n",5) == 0 || strncmp(buf,"user\n",5) == 0  )  {
        	
        	buf = buf + 4;
        	command = USER;
    }  

    else if(strncmp(buf,"PASS ",5) == 0  || strncmp(buf,"pass ",5) == 0  ||
    		strncmp(buf,"PASS\t",5) == 0 || strncmp(buf,"pass\t",5) == 0 ||
    		strncmp(buf,"PASS\n",5) == 0 || strncmp(buf,"pass\n",5) == 0  )  {
        	
        	buf = buf + 4;
        	command = PASS;
    }  

    else if(strncmp(buf,"MKD ",4) == 0  || strncmp(buf,"mkd ",4) == 0  ||
    		strncmp(buf,"MKD\t",4) == 0 || strncmp(buf,"mkd\t",4) == 0 ||
    		strncmp(buf,"MKD\n",4) == 0 || strncmp(buf,"mkd\n",4) == 0  )  {
        	
        	buf = buf + 3;
        	command = MKD;
    } 

    else if(strncmp(buf,"CWD ",4) == 0  || strncmp(buf,"cwd ",4) == 0  ||
    		strncmp(buf,"CWD\t",4) == 0 || strncmp(buf,"cwd\t",4) == 0 ||
    		strncmp(buf,"CWD\n",4) == 0 || strncmp(buf,"cwd\n",4) == 0  )  {
        	
        	buf = buf + 3;
        	command = CWD;
    }  

    else if(strncmp(buf,"RMD ",4) == 0  || strncmp(buf,"rmd ",4) == 0  ||
    		strncmp(buf,"RMD\t",4) == 0 || strncmp(buf,"rmd\t",4) == 0 ||
    		strncmp(buf,"RMD\n",4) == 0 || strncmp(buf,"rmd\n",4) == 0  )  {
        	
        	buf = buf + 3;
        	command = RMD;
    } 

    else if(strncmp(buf,"PWD ",4) == 0  || strncmp(buf,"pwd ",4) == 0  ||
    		strncmp(buf,"PWD\t",4) == 0 || strncmp(buf,"pwd\t",4) == 0 ||
    		strncmp(buf,"PWD\n",4) == 0 || strncmp(buf,"pwd\n",4) == 0  )  {
        	
        	buf = buf + 3;
        	command = PWD;
    } 

    else if(strncmp(buf,"RETR ",5) == 0  || strncmp(buf,"retr ",5) == 0  ||
    		strncmp(buf,"RETR\t",5) == 0 || strncmp(buf,"retr\t",5) == 0 ||
    		strncmp(buf,"RETR\n",5) == 0 || strncmp(buf,"retr\n",5) == 0  )  {
        	
        	buf = buf + 4;
        	command = RETR;
    } 

    else if(strncmp(buf,"STOR ",5) == 0  || strncmp(buf,"stor ",5) == 0  ||
    		strncmp(buf,"STOR\t",5) == 0 || strncmp(buf,"stor\t",5) == 0 ||
    		strncmp(buf,"STOR\n",5) == 0 || strncmp(buf,"stor\n",5) == 0  )  {
        	
        	buf = buf + 4;
        	command = STOR;
    } 

	else if(strncmp(buf,"LIST ",5) == 0  || strncmp(buf,"list ",5) == 0  ||
    	    strncmp(buf,"LIST\t",5) == 0 || strncmp(buf,"list\t",5) == 0 ||
    	    strncmp(buf,"LIST\n",5) == 0 || strncmp(buf,"list\n",5) == 0  )  {
        	
            buf = buf + 4;
        	command = LIST;
    }   

    else if(strncmp(buf,"ABOR ",5) == 0  || strncmp(buf,"abor ",5) == 0  ||
    		strncmp(buf,"ABOR\t",5) == 0 || strncmp(buf,"abor\t",5) == 0 ||
    		strncmp(buf,"ABOR\n",5) == 0 || strncmp(buf,"abor\n",5) == 0  )  {
        	
        	buf = buf + 4;
        	command = ABOR;
    } 

    else if(strncmp(buf,"QUIT ",5) == 0  || strncmp(buf,"quit ",5) == 0  ||
    		strncmp(buf,"QUIT\t",5) == 0 || strncmp(buf,"quit\t",5) == 0 ||
    		strncmp(buf,"QUIT\n",5) == 0 || strncmp(buf,"quit\n",5) == 0  )  {
        	
        	buf = buf + 4;
        	command = QUIT;
    }
    else if(strncmp(buf,"DELE",4) == 0)
        command = DELE;

    else if(strncmp(buf,"HELP",4) == 0)
        command = HELP;

    else if(strncmp(buf,"CDUP",4) == 0)
        command = CDUP;

    else if(strncmp(buf,"NOOP",4) == 0)
        command = NOOP;

    while(*buf == ' ' || *buf == '\t') {
        buf++;
    }
    
    strcpy(arg,buf);
}