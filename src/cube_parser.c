#include "cube_parser.h"
#include <regex.h>


//--------------------------------------------------------------
// § CUBE_PARSE_REGEX.C


//--------------------------------------------------------------
// $ Static functions
//--------------------------------------------------------------
static void
err_exit(const char *msg) {
  fprintf(stderr, "[ERR] %s\n", msg);
  exit(EXIT_FAILURE);
}


static regex_t
build_rgx (const char *regex) {
  // Returns a struct regex_t if it can compile REGEX
  // Encapsulation for regcomp()
  regex_t rgx;
  if ((regcomp(&rgx, regex, REG_EXTENDED)) != 0)
    err_exit("build_rgx");
  return rgx;
}


static bool
regex_match(regex_t *rgx, const char *str, uint8_t match_nb)
{
  if ((regexec(rgx, str, match_nb, NULL, 0)) == 0) {
    return true;
  }
  return false;
}

//--------------------------------------------------------------
// § Functions definitions
//--------------------------------------------------------------
bool
is_word(const char *tok) {
  regex_t rgx = build_rgx(rgx_WORD);
  bool res = regex_match(&rgx, tok, 0);
  regfree(&rgx);
  return res;
}


bool
is_number(const char *tok) {
  regex_t rgx = build_rgx(rgx_NUMBER);
  bool res = regex_match(&rgx, tok, 0);
  regfree(&rgx);
  return res;
}


bool
is_integer(const char *tok) {
  regex_t rgx = build_rgx(rgx_NUMBER);
  bool res = regex_match(&rgx, tok, 0);
  regfree(&rgx);
  return res;
}
