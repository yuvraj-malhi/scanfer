#include "lib.h"

char *modes[] = {"-s"           ,"-t"            };
char *descr[] = {"Local scan"   ,"File transfer" };


void print_help()
{
    printf("ERROR: Please enter one of the following options:-\n");

    for(int i=0; descr[i]; i++)
        printf("\t%s   :   %s\n", modes[i], descr[i]);

}


void graceful_exit()
{
    printf("\n======================  Thank you!  ======================\n\n");
    exit(0);
}


int mode_parse(char* argv)
{
    for(int i=0; modes[i]; i++)
        if(strcmp(argv,modes[i])==0)
            return i;
    
    return -1;
}


int main(int argc, char *argv[])
{
    printf("\n=================  Welcome to Scanfer!  ==================\n\n");

    if(argc==1)
    {
        print_help();
        graceful_exit();
    }

    int ret = mode_parse(argv[1]);
    int run;

    if(ret==-1)
        print_help();

    if(ret==0)
        run = scanner_main();
    
    if(ret>=1)
        printf("ERROR: Under construction!\n");
        
    
    graceful_exit();
}