#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "osd/osd_logger.h"

// Global variable to hold the message, initialized to "NO LOG"
char *message = "NO LOG";

// Function to get the current message
const char* getOsdMessage(void) {
    return message;
}

// Function to set a new message
void setOsdMessage(const char *newMessage) {
    if (strcmp(message, newMessage) != 0) {
        // Free the previous message if it was dynamically allocated
        if (strcmp(message, "NO LOG") != 0) {
            free(message);
        }
        // Allocate memory for the new message and copy it
        message = (char *)malloc(strlen(newMessage) + 1);
        strcpy(message, newMessage);
    }
}
