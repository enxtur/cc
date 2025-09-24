#include <stdio.h>
#include <stdlib.h>
#include "json-parser.h"

struct Token *new_token(int type) {
    struct Token *token = (struct Token *)malloc(sizeof(struct Token));
    token->type = type;
    return token;
}

struct Token *new_token_key(char *value) {
    struct Token *token = new_token(TOKEN_TYPE_KEY);
    token->value_string = value;
    return token;
}

struct Token *new_token_string(char *value) {
    struct Token *token = new_token(TOKEN_TYPE_STRING);
    token->value_string = value;
    return token;
}

struct Token *new_token_int(int value) {
    struct Token *token = new_token(TOKEN_TYPE_STRING);
    token->value_int = value;
    return token;
}
struct Token *new_token_decimal(float value) {
    struct Token *token = new_token(TOKEN_TYPE_STRING);
    token->value_decimal = value;
    return token;
}

struct TokenStackItem *new_token_stack(struct Token *token) {
    struct TokenStackItem *item = (struct TokenStackItem *)malloc(sizeof(struct TokenStackItem));
    item->token = token;
    item->previous = NULL;
    return item;
}


struct TokenStackItem *push_to_token_stack(struct TokenStackItem *stack, struct Token *token) {
    struct TokenStackItem *newItem = new_token_stack(token);
    newItem->previous = stack;
    return newItem;
}

struct TokenStackItem *pop_from_token_stack(struct TokenStackItem *stack) {
    if (stack->previous != NULL) {
        return stack->previous;
    } else {
        return NULL;
    }
}

void print_token_stack(struct TokenStackItem *stack) {
    struct TokenStackItem *currentStack = stack;
    while (currentStack != NULL) {
        switch (currentStack->token->type) {
            case TOKEN_TYPE_BEGIN_OBJECT:
                printf("{ ");
                break;
            case TOKEN_TYPE_END_OBJECT:
                printf("} ");
                break;
            case TOKEN_TYPE_BEGIN_ARRAY:
                printf("[ ");
                break;
            case TOKEN_TYPE_END_ARRAY:
                printf("] ");
                break;
            case TOKEN_TYPE_KEY:
                printf("%s ", currentStack->token->value_string);
                break;
            case TOKEN_TYPE_KEY_VALUE_SEPARATOR:
                printf(": ");
                break;
            case TOKEN_TYPE_VALUE_SEPARATOR:
                printf(", ");
                break;
            case TOKEN_TYPE_STRING:
                printf("%s ", currentStack->token->value_string);
                break;
            case TOKEN_TYPE_NUMBER_INT:
                printf("%d ", currentStack->token->value_int);
                break;
            case TOKEN_TYPE_NUMBER_DECIMAL:
                printf("%f ", currentStack->token->value_decimal);
                break;
            case TOKEN_TYPE_BOOLEAN_TRUE:
                printf("true ");
                break;
            case TOKEN_TYPE_BOOLEAN_FALSE:
                printf("false ");
                break;
            case TOKEN_TYPE_NULL:
                printf("null ");
                break;
            default:
                printf("unrecognized token type!");
                exit(1);
                break;
        }

        currentStack = currentStack->previous;
    }
    printf("\n");
}