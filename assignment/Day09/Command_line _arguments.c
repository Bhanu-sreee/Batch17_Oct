        Command Line Argument, Variable Argument Handling Assignment

1. Write a program to

a. read a name(of max length 40 characters), ip address (as char * string in dotted notation) and port number (unsigned short) of the cloud server as command line arguments.

b. Validate if the required number of arguments have been received before proceeding. Else report error and return.

c. Validate every argument received for valid range of values. [Refer ip address range, port range to do validations]

d. Store the values in a data structure and display using a function passing data structure

void display(struct server *servercfg);

e. Implement a function update() to prompt user, to modify all the server attributes and to display the updated configuration.

// to read, update configuration and return status as SUCCESS/FAILURE

Int update(struct server *servercfg);

/* DESCRIPTION : Program to handle server configuration using command-line arguments and update functionality
   Date : 12-11-2024
   Name : N.Bhanu sree
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define SUCCESS 0
#define FAILURE -1
#define MAX_NAME_LEN 40
#define PORT_MIN 1024
#define PORT_MAX 65535

// Structure to hold server configuration
struct server {
    char name[MAX_NAME_LEN];
    char ip[INET_ADDRSTRLEN];
    unsigned short port;
};

// Function to display the server configuration
void display(struct server *servercfg) {
    printf("\nServer Configuration:\n");
    printf("Name: %s\n", servercfg->name);
    printf("IP Address: %s\n", servercfg->ip);
    printf("Port: %u\n", servercfg->port);
}

// Function to update server configuration
int update(struct server *servercfg) {
    printf("\nUpdating Server Configuration:\n");

    printf("Enter new name: ");
    if (scanf("%39s", servercfg->name) != 1) return FAILURE;

    printf("Enter new IP address: ");
    if (scanf("%15s", servercfg->ip) != 1 || inet_pton(AF_INET, servercfg->ip, NULL) != 1) return FAILURE;

    printf("Enter new port number: ");
    if (scanf("%hu", &servercfg->port) != 1 || servercfg->port < PORT_MIN || servercfg->port > PORT_MAX) return FAILURE;

    return SUCCESS;
}

// Function to validate the command-line arguments
int validate_arguments(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <name> <IP address> <port number>\n", argv[0]);
        return FAILURE;
    }

    if (strlen(argv[1]) >= MAX_NAME_LEN) {
        fprintf(stderr, "Error: Name exceeds maximum length (%d).\n", MAX_NAME_LEN);
        return FAILURE;
    }

    if (inet_pton(AF_INET, argv[2], NULL) != 1) {
        fprintf(stderr, "Error: Invalid IP address format.\n");
        return FAILURE;
    }

    int port = atoi(argv[3]);
    if (port < PORT_MIN || port > PORT_MAX) {
        fprintf(stderr, "Error: Port number must be between %d and %d.\n", PORT_MIN, PORT_MAX);
        return FAILURE;
    }

    return SUCCESS;
}

int main(int argc, char *argv[]) {
    struct server servercfg;

    // Validate command-line arguments
    if (validate_arguments(argc, argv) == FAILURE) {
        return FAILURE;
    }

    // Store validated values into the structure
    strncpy(servercfg.name, argv[1], MAX_NAME_LEN - 1);
    servercfg.name[MAX_NAME_LEN - 1] = '\0';
    strncpy(servercfg.ip, argv[2], INET_ADDRSTRLEN - 1);
    servercfg.ip[INET_ADDRSTRLEN - 1] = '\0';
    servercfg.port = (unsigned short)atoi(argv[3]);

    // Display initial configuration
    display(&servercfg);

    // Update configuration
    if (update(&servercfg) == SUCCESS) {
        printf("\nUpdated Configuration:\n");
        display(&servercfg);
    } else {
        fprintf(stderr, "Error updating configuration.\n");
    }

    return SUCCESS;
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


2. Implement a log() with signature as below to display all the input arguments as per their type. [Hint: In log() , use vfprintf() to display the received inputs]

void log(const char *format, …);

For e.g.

int main()

{

int count = 10;

char prefix = ‘h’;

char label[] = “India”;

…

log(“count:%d, prefix:%c, label:%s”, count, prefix, label);

…

}

Expected Output:

count:10,prefix:h,label:India

/* DESCRIPTION : Program to implement a log() function to handle variable arguments and print formatted outputs
   Date : 12-11-2024
   Name : N.Bhanu sree
*/

#include <stdio.h>
#include <stdarg.h>

// Log function to display all input arguments as per their type
void log(const char *format, ...) {
    va_list args;
    va_start(args, format);

    vfprintf(stdout, format, args);
    va_end(args);
}

int main() {
    int count = 10;
    char prefix = 'h';
    char label[] = "India";

    // Example usage of log()
    log("count:%d, prefix:%c, label:%s\n", count, prefix, label);

    return 0;
}



----------------------------------------------------------------------------------

3. Refer the code “find_max.c”. Add a function below to accept variable number of strings and to return the string with maximum length to the caller. In case of strings with same length, return the first string in the input sequence

max_len_string(<variable number of arguments>)

Eg. Code below shoud output “hello”

char *ptr = max_len_string(“hi”, “hello”, “How”, “ Are”, “END”);

printf(“%s”, ptr);

/*************************************************************************
*  FILE NAME    : find_max.c
*  DESCRIPTION  : Finds out the maximum of set arguments. It demonstrates
*                 how stdarg macros are used to implement functions with
*                 variable number of arguments, including finding the
*                 longest string.
*  DATE      NAME    REFERENCE          REASON
*  7-NOV-2024  N.Bhanu sree  Assignment         Added max_len_string
**************************************************************************/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/*****************************************************************************
*                       MACROS
*****************************************************************************/
#define MAX 10
#define END "END"

/*****************************************************************************
*                       FUNCTION PROTOTYPES
*****************************************************************************/
static int args_maximum(int, ...);
char *max_len_string(const char *, ...);

/**************************************************************************
* FUNCTION NAME: args_maximum
* DESCRIPTION: Finds out the maximum of integer arguments
* RETURNS: Maximum integer from the arguments
**************************************************************************/
int args_maximum(int first_val, ...) {
    va_list arg_list; 
    int temp = 0, maximum = first_val;  

    va_start(arg_list, first_val);

    while ((temp = va_arg(arg_list, int)) != END) {
        if (temp > maximum) {
            maximum = temp;
        }
    }

    va_end(arg_list);
    return maximum;
}

/**************************************************************************
* FUNCTION NAME: max_len_string
* DESCRIPTION: Finds the string with the maximum length among variable arguments
* RETURNS: Pointer to the string with maximum length
**************************************************************************/
char *max_len_string(const char *first_str, ...) {
    va_list arg_list;
    const char *current_str = first_str;
    const char *max_str = first_str;

    va_start(arg_list, first_str);

    while (strcmp(current_str, END) != 0) {
        if (strlen(current_str) > strlen(max_str)) {
            max_str = current_str;
        }
        current_str = va_arg(arg_list, const char *);
    }

    va_end(arg_list);
    return (char *)max_str;
}

/******************************************************************************
* FUNCTION NAME   : main
* DESCRIPTION     : Calls the max functions and displays the result 
* RETURNS         : Success or Failure
*******************************************************************************/
int main() {
    char *ptr = max_len_string("hi", "hello", "How", " Are", "END");

    printf("The string with maximum length is: %s\n", ptr);

    return 0;
}
