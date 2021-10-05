#include "lib.h"

char *modes[] = {"-s"           ,"-t"            };
char *descr[] = {"Local scan"   ,"File transfer" };
char name [50];

void print_help()
{
    printf("ERROR: Please enter one of the following options:-\n");

    for(int i=0; descr[i]; i++)
        printf("%10s   :   %s\n", modes[i], descr[i]);

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

void set_name()
{
    printf("Enter your name (Optional): ");
    fgets(name, sizeof(name), stdin);
    if (name[0]=='\n')
    {
        strcpy(name, DEF_NAME);
        int rd;

        srand(time(0));
        do rd = rand();
        while (rd < 10 || 999 < rd);
        char rd_str[4];
        sprintf(rd_str, "%d", rd);
        strncat(name, rd_str, sizeof(rd_str));
    }
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

    set_name();
    printf("\n                      Hello %s \n",name);

    if(ret==-1)
        print_help();

    if(ret==0)
        run = scanner_main();
    
    if(ret>=1)
        printf("ERROR: Under construction!\n");
        
    
    graceful_exit();
}