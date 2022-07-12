#ifndef CUBE_PARSE_REGEX_H_
#define CUBE_PARSE_REGEX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


typedef enum PrimitiveToken { // §
  WORD, NUMBER, OPERATOR, SCOPE_OPEN, SCOPE_CLOSE, COMMENT
} PToken;


// $ Single non-alphanum characters definitions
typedef enum SingleOtherChr { // §
  oc_ACCESS, // 0
  oc_AFFECT,
  oc_ASSOC,
  oc_CLOSE_BRA,
  oc_CLOSE_CUR,
  oc_CLOSE_PAR,
  oc_DIV,
  oc_DOT,
  oc_MINUS,
  oc_MOD,
  oc_MULT,
  oc_OPEN_BRA,
  oc_OPEN_CUR,
  oc_OPEN_PAR,
  oc_PLUS // 14
} SingleOtherChr;


//--------------------------------------------------------------
// § Regex definitions
//--------------------------------------------------------------
// § primitive Tokens

// NUMBERS
#define rgx_NUMBER "^-?([0-9]{1}|[1-9]{1}[0-9]+|[0-9]{1}.[0-9]+|[1-9]{1}[0-9]+.[0-9]+)$"
//  -?                    : negative sign
//  [0-9]{1}              : single digit integer
//  [1-9]{1}[0-9]+        : multi digits integer
//  [0-9]{1}.[0-9]+       : single digit + decimal part
//  [1-9]{1}[0-9]+.[0-9]+ : multi digits + decimal part
 
// WORDS
#define rgx_WORD "^[_:@]?([a-zA_Z]|[a-zA-Z_-]+)([0-9_:@]+)?$"
// ^[_:@]?           : _RESERVED_KW_, _namespace_constant, :prefix_symb, @array 
// [a-zA-Z]          : x, y, A, B
// [a-zA-Z_-]+       : any upcase/downcase, with optional underscore or dash separator(s)
// ([0-9]+|[_:@]+)?$ : varname1, suffix_symb:, ignore_if:, unless:, each @array:, array@0, array@_1

// OPERATORS
#define rgx_OPERATOR "^([-+*\/%=<>]|[-+\/\*=<>!]=)$"
// +, -, /, *, %, =, <, >, <=, >=, ==, !=,  +=, -=, *=, /=


// TYPES
#define rgx_LIST_T = "^\([A-Z][a-z]+\)$"

#define rgx_VAR_NAME    "^[a-z]+(_[a-z]+)+*$"
#define rgx_CONST_NAME1 "[A-Z]+(_[A-Z]+)+*"
#define rgx_CONST_NAME2 "[A-Z]+(_[A-Z]+)+*"



//--------------------------------------------------------------
// § Functions prototypes
//--------------------------------------------------------------

bool is_word(const char *tok);

bool is_number(const char *tok);


#endif // CUBE_PARSE_REGEX_H_
