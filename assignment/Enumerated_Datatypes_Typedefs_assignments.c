Enumerated Datatypes and Typedefs assignments

Mandatory

1. WAP to define an enum to store designations in an organization. List of possible values are

{E2F=1, E2, E3, E4, E5}

Prompt and read a designation from the user. Then display his designation string such as

Designation Designation String

E2F Software Fresher

E2 Software Engineer

E3 Senior Software Engineer

E4 Team Lead

E5 Senior Team Lead.

#include <stdio.h>

// Define enum for designations
enum Designation {
    E2F = 1, // Software Fresher
    E2,       // Software Engineer
    E3,       // Senior Software Engineer
    E4,       // Team Lead
    E5        // Senior Team Lead
};

// Function to get designation string
const char* getDesignationString(enum Designation designation) {
    switch(designation) {
        case E2F: return "Software Fresher";
        case E2: return "Software Engineer";
        case E3: return "Senior Software Engineer";
        case E4: return "Team Lead";
        case E5: return "Senior Team Lead";
        default: return "Unknown";
    }
}

int main() {
    int inputDesignation;
    
    // Prompt and read the designation from the user
    printf("Enter designation number (1 for E2F, 2 for E2, 3 for E3, 4 for E4, 5 for E5): ");
    scanf("%d", &inputDesignation);
    
    // Validate input
    if (inputDesignation >= E2F && inputDesignation <= E5) {
        enum Designation userDesignation = (enum Designation)inputDesignation;
        printf("Designation: %d\n", userDesignation);
        printf("Designation String: %s\n", getDesignationString(userDesignation));
    } else {
        printf("Invalid designation number!\n");
    }

    return 0;
}





------------------------------------------------------------------------------------------------------------






2. Define a typedef structure to keep the configuration of putty server.
   Identify and place all the required members.
   Create a structure variable and initialize it with user defined values and finally display the contents.

#include <stdio.h>

// Define a typedef structure for Putty server configuration
typedef struct {
    char serverName[100];
    char ipAddress[15];    // IP address in the format x.x.x.x
    int port;              // Port number
    int connectionTimeout; // Timeout in seconds
    char protocol[10];     // Protocol type (e.g., SSH, Telnet)
} PuttyServerConfig;

int main() {
    // Create a structure variable and initialize with user-defined values
    PuttyServerConfig config = {
        "PuttyServer01",      // Server name
        "192.168.1.10",       // IP address
        22,                   // Port number
        60,                   // Connection timeout (in seconds)
        "SSH"                 // Protocol type
    };

    // Display the configuration
    printf("Putty Server Configuration:\n");
    printf("Server Name: %s\n", config.serverName);
    printf("IP Address: %s\n", config.ipAddress);
    printf("Port: %d\n", config.port);
    printf("Connection Timeout: %d seconds\n", config.connectionTimeout);
    printf("Protocol: %s\n", config.protocol);

    return 0;
}
