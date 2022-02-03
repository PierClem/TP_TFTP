#include "header.h"

char ipv4[INET_ADDRSTRLEN];
struct addrinfo hints;
struct addrinfo *res;
struct sockaddr_in*_address;
int sockette;

char* RRQ(char* filename,char* mode,int length)
{
    int i1,i2;
    char* request;
    length = 4+strlen(filename)+strlen(mode);
    char* rrq = malloc(length);
    rrq[0] = 0;
    rrq[1] = 1;
    for(int i = 2; i < strlen(filename)+2;i++)
    {
        rrq[i] = filename[i-2];
        i1 = i;
    }
    rrq[++i1] = 0;
    i1++;
    for(int j = i1; j < strlen(mode)+i1;j++)
    {
        rrq[j] = mode[j-i1];
        i2 = j;
    }
    rrq[++i2] = 0;
    request = rrq;
    return request;
}


void PrintFrameRRQ(char* request, int length)
{
    printf("PACKET [%d bytes]: \n ",length);
    for(int i = 0 ; i < length;i++)
        printf("%c ",request[i]);
    printf("\n");
    for(int i = 0 ; i < length;i++)
        printf("%d ",request[i]);
    printf("\n");
}

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
