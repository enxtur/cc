#include <stdio.h>
#include <stdlib.h>
#include "json-parser.h"

int main(int argc, char *argv[]) {
    printf("%d %s\n", argc, argv[0]);
    struct TokenStackItem *stack = new_token_stack(new_token(TOKEN_TYPE_BEGIN_OBJECT));
    struct TokenStackItem *stack2 = push_to_token_stack(stack, new_token_key("key"));
    struct TokenStackItem *stack3 = push_to_token_stack(stack2, new_token(TOKEN_TYPE_KEY_VALUE_SEPARATOR));
    struct TokenStackItem *stack4 = push_to_token_stack(stack3, new_token_string("value"));
    struct TokenStackItem *stack5 = push_to_token_stack(stack4, new_token(TOKEN_TYPE_END_OBJECT));
    print_token_stack(stack5);
    return 0;
}
