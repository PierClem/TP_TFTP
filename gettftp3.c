#include "header.h"

char ipv4[INET_ADDRSTRLEN];
struct addrinfo hints;
struct addrinfo *res;
struct sockaddr_in*_address;
int sockette;

void TFTPGetRequest(int argc,char const* argv[])
{
	memset(&hints,0,sizeof(hints));
	hints.ai_family=AF_INET;
	hints.ai_socktype=SOCK_DGRAM;
	hints.ai_flags = 0;
	hints.ai_protocol = IPPROTO_UDP;
	getaddrinfo(argv[1], argv[2], &hints, &res);
	sockette = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockette < 0)
        return;
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
