# FTP
Simulation of File Transfer Protocol

# Description
The aim of this project is to implement FTP application between a server and a client. The application is a console based application and is implemented using Unix Sockets. The project is developed in C/C++ language.

File Transfer Protocol (FTP) is an application layer protocol which moves files between local and remote file systems. 
When a FTP session is started between a client and a server, the client initiates a TCP connection with the server side. 
The client has to do FTP login, FTP login uses normal username and password scheme for granting access. The username is 
sent to the server using the USER command, and the password is sent using the PASS command. If the information provided 
by the client is accepted by the server, the server will send a greeting to the client and the session will commence.

Note: Fork() is used to create multiclient environment.

**Implemented commands are**
	
	1.  USER – This command sends the user identification to the server.
	2.  PASS – This command sends the user password to the server.
	3.  MKD  – This command causes the directory specified in the path name to be created as a directory.
	4.  CWD  – This command allows the user to change the current working directory to the path specified with the 
			   command.
	5.  RMD  – This command causes the directory specified in the path-name to be removed as a directory.
	6.  PWD  – This command causes the name of the current working directory to be returned in the reply.
	7.  RETR – This command send the requested file over the data connection.
	8.  STOR – This command causes to store a file into the current directory of the remote host.
	9.  LIST – Sends a request to display the list of all the files present in the directory.
	10. ABOR – This command tells the server to abort the previous FTP service command and any associated transfer 
			   of data.
	11. QUIT – This command terminates a USER and if file transfer is not in progress, the server closes the connection.

**Some of FTP replies used are**

	1.  200	-  Command okay.
	2.  530 -  Not logged in.
	3.  331 -  User name okay, need password.
	4.  225 -  Data connection open; no transfer in progress.
	5.  551 -  Requested action aborted: page type unknown.
	6.  502 -  Command not implemented.
	7.  503 -  Bad sequence of commands.

# Download and run
    $ git clone https://github.com/PSukhalani-96/FTP.git
	$ cd FTP
	
#### Terminal-1
	$ cd FTP-Server
	$ make
	$ ./ftpserver	

#### Terminal-2(Can Open Multiple Terminals-as the simulation supports multi-client environment)
	$ cd FTP-Client
	$ make
	$ ./ftpclient 127.0.0.1
	
# Sample Screenshots

![1](https://user-images.githubusercontent.com/50991324/60759638-43f81f00-a046-11e9-84c9-553fe49f02e0.png)

![2](https://user-images.githubusercontent.com/50991324/60759671-c08afd80-a046-11e9-9f84-b798664394a2.png)

![3](https://user-images.githubusercontent.com/50991324/60759837-0648c580-a049-11e9-9820-e40853535b1e.png)

![4](https://user-images.githubusercontent.com/50991324/60759734-70f90180-a047-11e9-83e5-852a9b31e496.png)

![5](https://user-images.githubusercontent.com/50991324/60759838-08128900-a049-11e9-9f17-3a2d3533bb7a.png)

![6](https://user-images.githubusercontent.com/50991324/60759840-0fd22d80-a049-11e9-944e-5fece7223f56.png)

![7](https://user-images.githubusercontent.com/50991324/60759885-d0581100-a049-11e9-8e32-6f8e00fcafa9.png)

![8](https://user-images.githubusercontent.com/50991324/60759933-73108f80-a04a-11e9-8426-2086ea00a3a9.png)

You can try other commands...
