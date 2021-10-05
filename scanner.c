#include "lib.h"


int display_IP()
{

	char *IP, *IP2, host[100];
	struct hostent *hen;
	if(gethostname(host, sizeof(host)) == -1)
	{
        perror("Could not display IP");
        return -1;
	}

	if((hen = gethostbyname(host))==NULL)
	{
        perror("Could not display IP");
        return -1;
	}

    struct ifaddrs *ifaddr, *ifa;
    if(getifaddrs(&ifaddr)==-1)
    {
        perror("Could not display IP");
        return -1;
    }

    printf("\nInstalled IPv4 interfaces for \'%s\':-\n",host);

    int s;
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr == NULL)
            continue;  

        s=getnameinfo(ifa->ifa_addr,sizeof(struct sockaddr_in),host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

        if(ifa->ifa_addr->sa_family==AF_INET)
        {
            if (s != 0)
            {
                perror("Could not display IP");
                return -1;
            }
            
            printf("%10s   :   %s\n", ifa->ifa_name, host);
        }
    }

    return 1;

}

int init_socket()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock<0) return -1;

    int enable = -1;
    int ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &enable, sizeof(enable));
    if(ret<0) return -1;



}


int scanner_main()
{
    printf("\n-----------------------  SCANNER  ------------------------\n");
    display_IP();

    int sock_fd = init_socket();
    
    if(sock_fd<-1)
    {
        perror("Socket error");
        return -1;
    }




    return 1;
}