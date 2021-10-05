#include "lib.h"


int display_IP()
{

	char *IP, *IP2, host[100];
	struct hostent *hen;
	if(gethostname(host, sizeof(host)) == -1)
	{
        perror("Host Name ERROR");
        return -1;
	}

	if((hen = gethostbyname(host))==NULL)
	{
        perror("Host IP ERROR");
        return -1;
	}

    struct ifaddrs *ifaddr, *ifa;
    if(getifaddrs(&ifaddr)==-1)
    {
        perror("IP Interface ERROR");
        return -1;
    }

    printf("\nInstalled interfaces for \'%s\':-\n",host);

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
                printf("Name Info ERROR: %s\n", gai_strerror(s));
                return -1;
            }
            
            char* st = ":";
            printf("%10s   %s   %s\n", ifa->ifa_name, st, host);
        }
    }

    return 1;

}


int scanner_main()
{
    printf("-----------------------  SCANNER  ------------------------\n");
    display_IP();

    return 1;
}