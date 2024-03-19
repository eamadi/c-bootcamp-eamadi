#include <stdlib.h>
#include <string.h>
#include "token.h"

// Function to create a token
token_t *create_token(token_type_t type, char *text) {
    token_t *token = (token_t *)malloc(sizeof(token_t));
    if (token == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    token->type = type;
    // Allocate memory for token text and copy the provided text
    token->text = strdup(text);
    if (token->text == NULL) {
        // Handle memory allocation failure
        free(token);
        return NULL;
    }
    return token;
}

// Function to destroy a token
void destroy_token(token_t *token) {
    if (token != NULL) {
        free(token->text);
        free(token);
    }
}
