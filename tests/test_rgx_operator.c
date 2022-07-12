#include <criterion/criterion.h>
#include "../src/cube_parser.h"


const char* OPS[] = {
  "+",  "-",   "*",  "/",
  "%",  "=",   "<",  ">",
  "<=",  ">=", "==", "!=",
  "+=",  "-=", "*=", "/=", NULL
};


Test(test_operators, test_op) {
  int i = 0;
  while (OPS[i] != NULL) {
    cr_expect(is_operator(OPS[i]) == true,
	      "'%s' should match rgx_OPERATOR",
	      OPS[i]);
    i += 1;
  }
}
