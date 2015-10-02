/*#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>




int main(int argc,char** argv)
{

   /* if (argc != 3)
    {
        fprintf(stderr,"usage: RE216_CLIENT hostname port\n");
        return 1;
    }*/

//get address info from the server
//get_addr_info()


//get the socket

       
/*
    int sockfd;
    int yes = 1;

    //create the socket
    sockfd = socket(domain, type, protocol);

    //check for socket validity
	
	if (sockfd == -1)  {

		printf("Socket no created\n");
        exit(EXIT_FAILURE);
    }

    // set socket option, to prevent "already in use" issue when rebooting the server right on

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)  {
        printf("ERROR setting socket options");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

   
//s = do_socket()

	int s = do_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

//connect to remote socket

void do_connect(int sockfd, const struct sockaddr *addr, int addrlen) {

    int res = connect(sockfd, addr, addrlen);
    if (res != 0) {

	   printf("Connexion no established\n");
       exit(EXIT_FAILURE);  
    }
}

// Creation de l'adresse du host (le serveur)

     struct sockaddr_in
    {

        short    sin_family;
        u_short    sin_port;
        struct  in_addr  sin_addr;
        char    sin_zero[8];

    };

    struct sockaddr_in sock_host;

    memset(&sock_host, 0, sizeof(sock_host));

    //sock_host.sin_addr.s_addr = htonl(INADDR_ANY);
    inet_aton("127.0.0.1", & sock_host.sin_addr);
    sock_host.sin_family = AF_INET;
    sock_host.sin_port = htons(4000);

   

//do_connect()

do_connect(s, (struct sockaddr *) & sock_host, sizeof(struct sockaddr));


//get user input
//readline()

ssize_t readline(int fd, char *str, size_t maxlen)      {

    int offset = 0;

    
    do {
        
        offset = read(fd, str + offset, maxlen - offset);
            if (offset == -1)   {

                printf("Message non reçu");
                exit(EXIT_FAILURE);
            }
        } 
    while (offset != maxlen);

    return offset;

}

//send message to the server

//ssize_t sendline(int fd, char *str, size_t maxlen)  syntaxe professeur

ssize_t sendline(int fd)        {

    printf ("Tapez le message à envoyer (moins de 20 caractères) : \n");

    char pointeur[21];

    size_t maxlen = sizeof(pointeur);

    memset(&pointeur,' ', maxlen);

    scanf("%20s", pointeur);

    int offset = 0;


    do {
        
        offset = write(fd, pointeur + offset, maxlen - offset);

        if (offset == -1)   {

                fprintf(stderr,"Message non reçu\n");
                exit(EXIT_FAILURE);
            }
        } 
    while (offset != maxlen);

    return offset;

}

//handle_client_message()

sendline(s);



    return 0;

}*/

