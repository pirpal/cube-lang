#ifndef _CUBE_ABSTRACT_H
#define _CUBE_ABSTRACT_H


typedef enum CubeType { // _cbT_*
  //               +------------+--------------------+-----------------+
  //               | Cube <T>   | primitive C <T>    | <stdint.h> <T>  |
  //               |------------+--------------------+-----------------|
  _cbT_Bool,    // | Bool       | 1 0                |                 |
  _cbT_Char,    // | Char       | char               |                 |
  _cbT_uInt8,   // | uInt8      | unsigned short     | uint8_t         |
  _cbT_uInt16,  // | uInt16     | unsigned int       | uint16_t        |
  _cbT_uInt32,  // | uInt32     | unsigned long      | uint32_t        |
  _cbT_uInt64,  // | uint64     | unsigned long long | uint64_t        |
  _cbT_Int8,    // | Int8       | short              | int8_t          |
  _cbT_Int16,   // | Int16      | int                | int16_t         |
  _cbT_Int32,   // | Int32      | long               | int32_t         |
  _cbT_Int64,   // | Int64      | long long          | int64_t         |
  _cbT_String,  // | String     | char*, char[]      |                 |
  _cbT_Symbol,  // | Symbol     | Enum + char** (sort of)              |
  _cbT_Path,    // | Path       |
  _cbT_Buffer,
  _cbT_Charset


} CbType;



typedef enum CubeToken { // _tok_*
  // _T is for Type
  _tok_OpenParen,    // '('
  _tok_CloseParen,   // ')' 
  _tok_CloseBracket, // '[' 
  _tok_CloseBrcketa, // ']' 
  _tok_CloseCurly,   // '{' 
  _tok_CloseCurly,   // '}' 
  _tok_VarLeftV,     // "var_name"
  _tok_ConstLeftV,   // "CONST_NAME" | "_cOnsTNamE"
  _tok_uInt,         // 0, 1, 1500, 1_500, 10_000, 10e5 (-> 100_000) 
  _tok_sInt,         // -0.024, -1, -100_000, -1.733334e3
  _tok_Double,       // 3.14, 10f, 0.001, -12, -1.2, 0.17e2 (-> 17)
  _tok_ListT,        // (T) 
  _tok_HashT,        // (T*:T) ; *: restricted_to: Char and uInt(8|16)
  _tok_T,            // Bool Char (u)Int(8|16|32|64) Double String Path Symbol Buffer DateTime Charset
  _tok_Keyword,      // var each if else elsif unless break_if ignore_if times
  _tok_Operator      // + - * / % << >> | & ^ ~
} CbToken;



typedef enum CubeScope { // _scp_*
  _scp_If,       // if, elsif, else, unless, ignore_if, break_if
  _scp_Elsif,
  _scp_Else,
  _scp_Unless,
  _scp_Loop,     // each, each_line, times
  _scp_FuncDecl, // fname (arg:T arg:T ...) -> T
  _scp_CubeDecl, // [CubeName sym: T  ... ]
  _scp_OpenFile
} CbScope;


typedef enum CubeLoopGuard { // _lp_*
  _lp_IgnoreIf,
  _lp_BreakIf,
  _lp_ExitIf
} CubeLoopGuard;

// if EXPR:        _scp_If_open
// elsif EXPR:     IfScope
// else:           IfScope
// unless EXPR:    IfScope
// ignore_if: EXPR IfClause (inside: LoopScope)
// break_if: EXPR  IfClause (inside: LoopScope)
// each_line { ... FileLineScope (inside: FileOpeningScope)
// each LEFTV @(T): ListLoopScope

typedef struct CubeHash {
  uint16_t i_index;
  char     c_index;
} CbHash;



typedef struct CubeExpr {
  
} CubeExpr;




#endif // _CUBE_ABSTRACT_H
