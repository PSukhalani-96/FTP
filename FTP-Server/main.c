#include "ftp.h"

int newSocket;
int count = 0;

int main() {
    
    /*
        Objective:      To create a socket between FTP-CLIENT and FTP-SERVER & accepting 
                        client commands using recv-line and sending response to client
                        using send-line.

    */
    
    printf("\e]2;FTP-Server\a");
    system("clear");
    
    int ret;
    struct sockaddr_in serverAddr;      // Server Socket Address Structure
    struct sockaddr_in newAddr;         // Client Socket Address Structure
    socklen_t addr_size;                // Value Result Argument.

    int sockfd;
    char buf[MAXLINE];

    /*================================================SOCKET-CREATION================================================*/
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Error in connection.\n");
        exit(1);
    }
    

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;                            // IPv4
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");        //Server IP-address of '127.0.0.1'
    printf("Server Socket is created with IP-address %s.\n", inet_ntoa(serverAddr.sin_addr));

    /*================================================REUSE-SAME-PORT================================================*/
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));  // To reuse same Port multiple times

    /*================================================PERFORM-BINGING================================================*/
    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    
    if(ret < 0){
        printf("Error in binding.\n");
        exit(1);
    }
    printf("Bind to port %d\n", PORT);

    /*===============================================PASSIVE-LISTENING===============================================*/
    if(listen(sockfd, 10) == 0) {
        printf("Listening....\n");
    }
    else {
        printf("Error in binding.\n");
    }

    while(1){
        
        /*================================================ACCEPT-CONNECTIONS================================================*/
        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);     // accept a new connection
        if(newSocket < 0){
            exit(1);
        }
            
        printf(">> Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));  
        printf(">> But Client is not yet Logged In.\n");

        /*==============================================CHILD-PROCESS-CREATION==============================================*/
        if (fork() == 0 ) {
            close(sockfd);                  // Close Socket listening in Child Process

            /*=================================================MENU-FOR-FTP=================================================*/
            bzero(buf, sizeof(buf));
            strcpy(buf, "\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
            strcat(buf, "\t\t\t\t\tWelcome to File Transfer Protocol Services.");
            strcat(buf, "\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
            strcat(buf, "\n\tCommand-Name \t\t\tDescription \t\t\t\t\t\t\t Usage ");
            strcat(buf, "\n\n\t1.  USER \t sends username to the server                             \t USER <username>");
            strcat(buf, "\n\t2.  PASS \t sends password to the server                             \t PASS <password>");
            strcat(buf, "\n\t3.  MKD  \t makes directory specified in path name                   \t MKD  <path-to-new-directory>");
            strcat(buf, "\n\t4.  CWD  \t change the working directory to path specified           \t CWD  <path-of-other-directory>");
            strcat(buf, "\n\t5.  RMD  \t remove directory specified in path name                  \t RMD  <path-of-directory-to-be-removed>");        
            send(newSocket, buf, MAXLINE,0);    // send Menu to the client
            bzero(buf, sizeof(buf));        

            strcpy(buf, "\n\t6.  PWD  \t returns name of current working directory                \t PWD ");
            strcat(buf, "\n\t7.  RETR \t send requested file over data connection                 \t RETR <file-name>");
            strcat(buf, "\n\t8.  STOR \t store file in current working directory                  \t STOR <path-to-file-name>");
            strcat(buf, "\n\t9.  LIST \t display all files present in current directory           \t LIST <path-to-directory> || left-empty" );
            strcat(buf, "\n\t10. ABOR \t abort FTP server services to client                      \t ABOR");
            strcat(buf, "\n\t11. QUIT \t terminates USER and close connection if no file transfer \t QUIT");
            strcat(buf, "\n------------------------------------------------------------------------------------------------------------------------------------------------\n");
            send(newSocket, buf, MAXLINE,0);    // send menu to the client
            bzero(buf, sizeof(buf));            // clear Buffer
            /*===============================================================================================================*/
            
            while(1){

                bzero(buf, sizeof(buf));
                if(recv(newSocket, buf, MAXLINE, 0) < 0) {     
                   char temp[MAXLINE];
                    *temp = '\0';
                    strcat(temp, "Reply[225]: Data Connection Open but No Transfer in progress.");
                    send(newSocket, temp, MAXLINE, 0);
                    continue;

                }

                /*================================================PARSE and Handle Requests================================================*/
                parseCommand(buf);                          
                int status = request_handler(arg);

                /*=======================================================PASS-COMMAND======================================================*/
                if (command == PASS){

                    strcpy(buf, reply_message(status));
                    send(newSocket, buf, MAXLINE, 0);
                    bzero(buf, sizeof(buf));
                    if (status == 333) {
                        char temp[10];
                        strcpy(temp, USERNAME[count]);
                        send(newSocket, temp, 10, 0);
                        printf(">> Client - %s has Successfully Logged In.\n", USERNAME[count]);    
                    }
                    
                }

                /*=======================================================RETR-COMMAND======================================================*/
                else if (command == RETR && status == 0) {
                    
                    char temp[1024];
                    
                    strcpy(temp, "Reply[610]: File is being sent on to the Data Connection.");
                    
                    send(newSocket, temp, MAXLINE, 0);
                    
                    send(newSocket, file, MAXLINE, 0);
                    printf(">> File Sent Successfully.\n");
                    
                    strtok(arg, "\n");
                    send(newSocket, arg, MAXLINE, 0);
                }

                /*======================================================OTHER-COMMAND======================================================*/

                else {
                    bzero(buf, sizeof(buf));
                       
                    /*=======================================================STOR-COMMAND======================================================*/     
                    if (command == STOR && status == 0) {
                        strcpy(buf, "Reply[227]: File successfully stored in remote host.");
                    }

                    /*=======================================================LIST-COMMAND======================================================*/
                    else if (command == LIST && status == 0) {
                        
                        if (list[strlen(list)-1] == '\n')
                            list[strlen(list)-1] = '\0';
                        strcpy(buf, list);
                    }
                    
                    /*=======================================================ABOR-COMMAND======================================================*/
                    else {
                        strcpy(buf, reply_message(status));
                    }
                      
                    send(newSocket, buf, MAXLINE, 0);
                    
                    /*=======================================================QUIT-COMMAND======================================================*/
                    if (command == QUIT ) {
                        printf(">> Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                        break;
                    }
                }
                bzero(buf, sizeof(buf));
            }
            /*================================================================================================================================*/
        }
    }
    close(newSocket);
    return 0;
}