/*
  CHAHI Rabie Ala Eddine
  C simple TCP server
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

/*Port to listen on*/
#define PORT 8080

/*Structs*/
#define sockAddrIn struct sockaddr_in
#define sockAddr struct sockaddr 

/*Initialization of socket address*/
sockAddrIn initAddr(){

    sockAddrIn addr;
    bzero(&addr, sizeof(addr)); 
	addr.sin_family = AF_INET; 
	addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	addr.sin_port = htons(PORT);

    return addr;
}

/*Prepare and execute server listening*/
void serverMaker(){

    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        puts("Error on creating socket !\n");
        return;
    };

    sockAddrIn addr = initAddr(PORT);
    if (((bind(sock, (sockAddr *)&addr, sizeof(addr))) < 0) || ((listen(sock, 16)) < 0)) {
        puts("Cannot listen");
        system("kill -9 $(lsof -t -i:8080)");
        return;
    }

    printf("👂Listening on port %d...\n\n", PORT);

    for(;;) {
        int conSock = accept(sock, NULL, NULL);

        if (conSock > 0){
            close(sock);
            puts("🌐 Client is connected !\n");
            unsigned int temp = 0;

            for(;;){
                if ((write(conSock, &temp, sizeof(temp))) <= 0)
                    puts("🚫 Client disconnected.\n");
            
                ++temp;
            }
            exit(0);
        }
    }
}

/*Launch server listening*/
void serverLauncher(int commandNum){
    if (commandNum == 1)
        serverMaker();
    else
        puts("❌ It seems that your command line is corrupted !\nYou should type : user@linux:~/user$ ./server\n");
}

int main(int argc, char **argv)
{
    serverLauncher(argc);

    return 0;
}
