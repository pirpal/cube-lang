#ifndef CUBE_PARSER_H_
#define CUBE_PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


typedef enum PrimitiveToken {
  WORD, NUMBER, OPERATOR
} PToken;


//--------------------------------------------------------------
// § Regex definitions
//--------------------------------------------------------------
// Primitive Tokens

#define rgx_NUMBER "^-?([0-9]{1}|[1-9]{1}[0-9]+|[0-9]{1}.[0-9]+|[1-9]{1}[0-9]+.[0-9]+)$"
//  -?                    : negative sign
//  [0-9]{1}              : single digit integer
//  [1-9]{1}[0-9]+        : multi digits integer
//  [0-9]{1}.[0-9]+       : single digit + decimal part
//  [1-9]{1}[0-9]+.[0-9]+ : multi digits + decimal part
 
#define rgx_WORD "^[_:@]?([a-zA_Z]|[a-zA-Z_-]+)([0-9_:@]+)?$"
// ^[_:@]?           : _RESERVED_KW_, _namespace_constant, :prefix_symb, @array 
// [a-zA-Z]          : x, y, A, B
// [a-zA-Z_-]+       : any upcase/downcase, with optional underscore or dash separator(s)
// ([0-9]+|[_:@]+)?$ : varname1, suffix_symb:, ignore_if:, unless:, each @array:, array@0, array@_1

#define rgx_OPERATOR "^([-+*/%=<>]|[-+/*=<>!]=)$"
// +, -, /, *, %, =, <, >, <=, >=, ==, !=,  +=, -=, *=, /=




//--------------------------------------------------------------
// § Functions prototypes
//--------------------------------------------------------------

bool is_word(const char *tok);

bool is_number(const char *tok);

bool is_operator(const char *tok);


#endif // CUBE_PARSER_H_
