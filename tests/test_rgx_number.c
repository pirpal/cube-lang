#include <criterion/criterion.h>

#include "../src/cube_parser.h"


#define UINT0 "0"
#define UINT1 "1"
#define UINT2 "230"
#define UINT3 "405"
#define UINT4 "678"
#define UINT5 "9000"


Test(test_numbers, test_uint) {
  cr_expect(is_number(UINT0) == true,
	    "'%s' should match rgx_NUMBER\n", UINT0);
  cr_expect(is_number(UINT1) == true,
            "'%s' should match rgx_NUMBER\n", UINT1);
  cr_expect(is_number(UINT2) == true,
            "'%s' should match rgx_NUMBER\n", UINT2);
  cr_expect(is_number(UINT3) == true,
            "'%s' should match rgx_NUMBER\n", UINT3);
  cr_expect(is_number(UINT4) == true,
            "'%s' should match rgx_NUMBER\n", UINT4);
  cr_expect(is_number(UINT5) == true,
            "'%s' should match rgx_NUMBER\n", UINT5);

}
