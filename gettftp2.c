#include "header.h"

char ipv4[INET_ADDRSTRLEN];
struct addrinfo hints;
struct addrinfo *res;

void TFTPGetRequest(int argc,char const* argv[])
{
	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_INET;
	hints.ai_socktype=SOCK_DGRAM;
	hints.ai_flags = 0;
	hints.ai_protocol = 0;
	getaddrinfo(argv[1], argv[2], &hints, &res);
	inet_ntop(AF_INET,&((struct sockaddr_in *) res->ai_addr)->sin_addr, ipv4, INET_ADDRSTRLEN);
        printf("%s \n",ipv4);
        res = res->ai_next;
}

int main(int argc, char const *argv[])
{
    switch(argc)
    {
        case 4:
        TFTPGetRequest(argc,argv);
        break;
        default :
        printf("Invalid Arguments \n");
        break;
    }
    return 0;
}


