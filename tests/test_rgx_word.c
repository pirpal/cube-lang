#include <criterion/criterion.h>
#include "../src/cube_parser.h"


#define WORD1 "word"
#define WORD2 "WORD"
#define WORD3 "word_word"
#define WORD4 "WORD_WORD"
#define WORD5 "_word_word"
#define WORD6 "_wordWord"
#define WORD7 "word-word"

#define NOT_WORD1 "*word"
#define NOT_WORD2 "/word/"
#define NOT_WORD3 "01word"


// § Tests IS_WORD
Test (test_cube_regexes, test_word1) {
  cr_expect(is_word(WORD1) == true,
	    "[test_word] '%s' should match rgx_WORD\n", WORD1);
}

Test (test_cube_regexes, test_word2) {
  cr_expect(is_word(WORD2) == true,
	    "[test_word] '%s' should match rgx_WORD\n", WORD2);
}

Test (test_cube_regexes, test_word3) {
  cr_expect(is_word(WORD3) == true,
	    "[test_word] '%s' should match rgx_WORD\n", WORD3);
}

Test (test_cube_regexes, test_word4) {
  cr_expect(is_word(WORD4) == true,
	    "[test_word] '%s' should match rgx_WORD\n", WORD4);
}

Test (test_cube_regexes, test_word5) {
  cr_expect(is_word(WORD5) == true,
	    "[test_word] '%s' should match rgx_WORD\n", WORD5);
}

Test (test_cube_regexes, test_word6) {
  cr_expect(is_word(WORD6) == true,
	    "[test_word] '%s' should match rgx_WORD\n", WORD6);
}

Test (test_cube_regexes, test_word7) {
  cr_expect(is_word(NOT_WORD1) == false,
            "[test_word] '%s' should not match rgx_WORD\n", NOT_WORD1);
}

Test (test_cube_regexes, test_word8) {
  cr_expect(is_word(NOT_WORD2) == false,
            "[test_word] '%s' should not match rgx_WORD\n", NOT_WORD2);
}

Test (test_cube_regexes, test_word9) {
  cr_expect(is_word(NOT_WORD3) == false,
            "[test_word] '%s' should not match rgx_WORD\n", NOT_WORD3);
}
