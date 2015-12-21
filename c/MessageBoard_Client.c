// sunxiaohua
// Compile with:  gcc msg_client.c
// Run with:     ./a.out "54.165.143.235" "sunxiaohua" "hello"

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>

int main(int argc, char ** argv)
{
    struct addrinfo hints, *server;
    int rc;
    int sockfd;
    char* name;
    char* message;
    
    
    if(argc != 4) perror("Illegal Input, please input like <ip> <name> <message>.");
    memset(&hints,0,sizeof(hints));
    char* server_port = "5555";
    char* server_ip = argv[1];
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if((rc = getaddrinfo(server_ip,server_port,&hints,&server)) != 0){
        perror(gai_strerror(rc));
        exit(-1);
    }
    
    sockfd = socket(server->ai_family,server->ai_socktype,server->ai_protocol);
    if(sockfd == -1){
        perror("ERROR opening socket");
        exit(-1);
    }
    
    rc = connect(sockfd,server->ai_addr,server->ai_addrlen);
    if(rc == -1){
        perror("ERROR on connect");
        close(sockfd);
        exit(-1);
    }
    name = argv[2];
    //printf("%s",name);
    send(sockfd,name,strlen(name)+1,0);
    message = argv[3];
    send(sockfd," :",strlen(" :")+1,0);
    send(sockfd,message,strlen(message),0);
   // printf("%s",message);
    
    close(sockfd);
    printf("Done.\n");
    
    return 0;
}

