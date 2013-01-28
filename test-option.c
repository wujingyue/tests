#include <stdio.h>
#include <stdlib.h>

struct cmdline_option {
  const char *long_name;
  char short_name;
  enum {
    OPT_VALUE,
    OPT_BOOLEAN,
    OPT_FUNCALL,
    /* Non-standard options that have to be handled specially in
     *        main().  */
    OPT__APPEND_OUTPUT,
    OPT__CLOBBER,
    OPT__DONT_REMOVE_LISTING,
    OPT__EXECUTE,
    OPT__NO,
    OPT__PARENT
  } type;
  const void *data;             /* for standard options */
  int argtype;                  /* for non-standard options */
};

static struct cmdline_option option_data[] =
{
  { "accept", 'A', OPT_VALUE, "accept", -1 },
  { "adjust-extension", 'E', OPT_BOOLEAN, "adjustextension", -1 }
};

int main() {
  size_t i;
  for (i = 0; i < sizeof(option_data) / sizeof(struct cmdline_option); ++i) {
    struct cmdline_option *opt = &option_data[i];
    if (!opt->long_name)
      continue;
    printf("%s\n", opt->long_name);
  }
  return 0;
}
