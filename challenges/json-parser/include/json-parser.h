#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#define TOKEN_TYPE_BEGIN_OBJECT 1
#define TOKEN_TYPE_END_OBJECT 2
#define TOKEN_TYPE_BEGIN_ARRAY 3
#define TOKEN_TYPE_END_ARRAY 4
#define TOKEN_TYPE_KEY 5
#define TOKEN_TYPE_KEY_VALUE_SEPARATOR 6
#define TOKEN_TYPE_VALUE_SEPARATOR 7
#define TOKEN_TYPE_STRING 8
#define TOKEN_TYPE_NUMBER_INT 9
#define TOKEN_TYPE_NUMBER_DECIMAL 10
#define TOKEN_TYPE_BOOLEAN_TRUE 11
#define TOKEN_TYPE_BOOLEAN_FALSE 12
#define TOKEN_TYPE_NULL 13

struct Token {
    int type;
    char *value_string;
    int value_int;
    float value_decimal;
};

struct Token *new_token(int type);
struct Token *new_token_key(char *value);
struct Token *new_token_string(char *value);
struct Token *new_token_int(int value);
struct Token *new_token_decimal(float value);

struct TokenStackItem {
    struct Token *token;
    struct TokenStackItem *previous;
};

struct TokenStackItem *new_token_stack(struct Token *token);
struct TokenStackItem *push_to_token_stack(struct TokenStackItem *stack, struct Token *token);
struct TokenStackItem *pop_from_token_stack(struct TokenStackItem *stack);
void print_token_stack(struct TokenStackItem *stack);

#endif
