/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}


int do_socket(int domain, int type, int protocol){
    int sockfd;

    sockfd = socket(domain, type, protocol);

    if (sockfd ==-1)
        error("ERROR Socket");
    return sockfd;
}

void init_serv_addr(const char* port, struct sockaddr_in * serv_addr){
    int portno;

    memset(serv_addr, 0, sizeof(*serv_addr));

    portno = atoi(port);

    serv_addr->sin_family = AF_INET;
    serv_addr->sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr->sin_port = htons(portno);
}


void do_bind(int sock, const struct sockaddr_in *serv_addr, socklen_t addrlen){
    int res = bind(sock, (struct sockaddr *) &serv_addr, addrlen);
    if (res == -1)
        error("ERROR Bindage");
}


int do_accept(int sock, struct sockaddr * addr, socklen_t addrlen){
    int new_sock = accept(sock, addr, &addrlen);
    if (new_sock == -1)
        error("ERROR Accept");
    return new_sock;
}

void do_read(int sockfd, char* buffer){
    read(sockfd, buffer, 256);
}

int do_write(int sockfd, const void* buf, int len){
    int to_send = write(sockfd, buf, len);
    if (to_send == -1)
        error("ERROR Envoi");
    return to_send;
}
    

int main(int argc, char** argv)
{

    struct sockaddr_in * serv_addr, addr;

    //create the socket, check for validity!
    int sockfd = do_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    //init the serv_add structure
    init_serv_addr("33971", serv_addr);

    //perform the binding
    //we bind on the tcp port specified
    do_bind(sockfd, serv_addr, sizeof(serv_addr));

    //specify the socket to be a server socket and listen for at most 20 concurrent client
    if (listen(sockfd, 20) == -1)
        error("ERROR Listen");

    for (;;)
    {

        //accept connection from client
        socklen_t addrlen = (socklen_t) sizeof(addr);
        int new_sockfd = do_accept(sockfd,(struct sockaddr *) &addr, addrlen);

        //read what the client has to say
        char* buffer = malloc(256);
        memset(buffer, 0,256);
        do_read(new_sockfd, buffer);

        //we write back to the client
        do_write(new_sockfd,"ACK",sizeof("ACK"));

        //clean up client socket
        close(new_sockfd);
    }

    //clean up server socket
    close(sockfd);

    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char** argv)
{

   

    struct sockaddr_in serv_addr;
    struct sockaddr_in * addr;
    int sockfd;

    //create the socket, check for validity!
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    //init the serv_add structure
    memset((struct sockaddr_in *) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(4000);

    //perform the binding
    //we bind on the tcp port specified
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    //specify the socket to be a server socket and listen for at most 20 concurrent client
    if (listen(sockfd, 20) == -1)
        error("ERROR Listen");
//accept connection from client
        int new_sockfd = accept(sockfd,(struct sockaddr *) addr, (socklen_t *) sizeof(addr));

    for (;;)
    {

        
        //read what the client has to say
        char* buffer[256];
        read(new_sockfd, buffer, sizeof(buffer));

        //we write back to the client
        write(new_sockfd,"ACK",sizeof("ACK"));

        //clean up client socket
        close(new_sockfd);
    }

    //clean up server socket
    close(sockfd);

    return 0;
}*/


