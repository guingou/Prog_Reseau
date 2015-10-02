#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void get_addr_info(const char* address, const char* port,
        struct addrinfo** res) {

    int status;
    struct addrinfo hints, p;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(address, port, &hints, res);

    if (status != 0) {
        perror("Erreur client address info  ");
    }
}

int do_socket(){
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1)
        error("ERROR socket");
    return sockfd;
}

void do_connect(int sock, const struct sockaddr* addr, socklen_t addr_len){
	 int c;

    c = connect(sock, addr, addr_len);

    if (c != 0) {
        perror("Erreur client connect : ");
    }
}

/*char * readline(size_t maxlen)      {
    int offset = 0;
    do {
        offset = read(fd, str + offset, maxlen - offset);
            if (offset == -1){
                printf("Message non reçu");
                exit(EXIT_FAILURE);
            }
        } 
    while (offset != maxlen);

    return offset;
}*/

void handle_client_message(int sock, void * buffer, int maxlen){
	memset(buffer, 0, maxlen);
	printf ("Tapez le message à envoyer (moins de %d caractères) : \n",maxlen);
	fgets((char *) buffer,maxlen, stdin);
	
    int offset = 0;
    int maxlen2 = strlen((char *) buffer);

    while(offset < maxlen2){
        offset += write(sock, buffer + offset, maxlen2 - offset);
        if (offset == -1){
            fprintf(stderr,"Message non envoyé\n");
            exit(EXIT_FAILURE);            
        }
    } 
}



int main(int argc,char** argv)
{


    if (argc != 3)
    {
        fprintf(stderr,"usage: RE216_CLIENT hostname port\n");
        return 1;
    }

//get address info from the server
    struct addrinfo addr;
    struct addrinfo * add = &addr;
    struct addrinfo ** res = &add;
    int sockfd;

	get_addr_info(argv[2], argv[1], res);
	add = *res;
	addr= *add;

	//get the socket
	sockfd = do_socket();

	//connect to remote socket
	do_connect(sockfd,addr.ai_addr, addr.ai_addrlen);

    for(;;){
    	char buffer[256];
    	memset(&buffer, 0, 256);

        fprintf (stdout,"Tapez le message à envoyer (moins de 256 caractères) : \n");
        fgets((char *) buffer, 256, stdin);
        int ecrit = write(sockfd, buffer, strlen((char *) buffer));
    	
    	//handle_client_message(sockfd, &buffer, (int) 256);

        memset(&buffer, 0, (int) 256);
        read(sockfd, buffer, (int) 256);
        fprintf(stdout, "[SERVER] : %s", buffer);
        if(strcmp(buffer, "You will be terminated\n") == 0){
            fprintf(stdout, "Connection terminated\n\n");
            break;
        }
    }

    close(sockfd);


    return 0;


}