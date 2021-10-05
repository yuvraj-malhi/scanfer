#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

// main.c functions
extern void print_help();
extern void graceful_exit();
extern void graceful_exit();

extern char *modes[];
extern char *descr[];



// scanner.c functions
extern int scanner_main();
extern int display_IP();


// transfer.c functions

