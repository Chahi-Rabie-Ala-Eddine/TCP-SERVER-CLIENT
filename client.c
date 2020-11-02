/*
  CHAHI Rabie Ala Eddine
  C simple TCP client
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

/*Port to listen on*/
#define PORT 8080 

/*Adress*/
#define ADR "127.0.0.1"

/*Structs*/
#define sockAddrIn struct sockaddr_in
#define sockAddr struct sockaddr 

/*Initialization of address*/
void initAddr(int sk){

    sockAddrIn addr;
    bzero(&addr, sizeof(addr)); 
	addr.sin_family = AF_INET;

    if ((inet_aton(ADR, &addr.sin_addr)) < 0) {
        exit(0);
    }    

    addr.sin_port = htons(PORT);
    if ((connect(sk, (struct sockaddr *)&addr, sizeof(addr))) < 0) {
        exit(0);
    }
}

/*Prepare and execute connection to server*/
void connectionMaker(){

    int sk = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sk < 0) {
        return;
    }

    initAddr(sk);

    printf("Connected to %d port ✅\nType ", PORT);

    for(;;){/*To do on server*/}
}

/*Launch connection*/
void serverLauncher(int commandNum){
    if (commandNum == 1)
        connectionMaker();
    else
        puts("❌ It seems that your command line is corrupted !\nYou should type : user@linux:~/user$ ./client\n");
}

int main(int argc, char **argv)
{
    serverLauncher(argc);

    return 0;
}
