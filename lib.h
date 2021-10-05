#include <time.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define DEF_NAME "Usr_"

// main.c functions
extern void print_help();
extern void graceful_exit();
extern void graceful_exit();
extern void set_name();

extern char *modes[];
extern char *descr[];
extern char name[];


// scanner.c functions
extern int scanner_main();
extern int display_IP();
extern int init_socket();

extern int sock_fd;


// transfer.c functions

