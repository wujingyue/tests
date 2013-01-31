#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>

extern "C" {
#include "xed-interface.h"
}

using namespace std;

static const size_t MAX_INSTR_ASM_LEN = 128;

int main(int argc, char *argv[]) {
  assert(argc == 3);
  xed_uint8_t *start_addr = (xed_uint8_t *)strtol(argv[1], NULL, 16);
  size_t trace_len = strtol(argv[2], NULL, 16);

  xed_uint8_t trace[trace_len];
  if (fseek(stdin, (long)start_addr, SEEK_SET) == -1) {
    perror("fseek");
    exit(1);
  }
  if (fread(trace, 1, trace_len, stdin) < trace_len) {
    perror("fread");
    exit(1);
  }

  xed_state_t xed_state;
  xed_state_init(&xed_state, XED_MACHINE_MODE_LONG_64,
                 XED_ADDRESS_WIDTH_64b, XED_ADDRESS_WIDTH_64b);
  xed_tables_init();

  for (xed_uint8_t *frontier = trace; frontier < trace + trace_len; ) {
    xed_decoded_inst_t xedd;
    xed_decoded_inst_zero_set_mode(&xedd, &xed_state);
    xed_decoded_inst_set_input_chip(&xedd, XED_CHIP_INVALID);

    char code_str[MAX_INSTR_ASM_LEN];
    xed_error_enum_t xed_error = xed_decode(&xedd, (xed_uint8_t *)frontier, 15);
    if (xed_error != XED_ERROR_NONE) {
      cerr << "error\n";
      exit(1);
    }

    if (!xed_format_context(XED_SYNTAX_INTEL,
                            &xedd,
                            code_str, MAX_INSTR_ASM_LEN,
                            (uint64_t)frontier,
                            NULL)) {
      cerr << "error\n";
      exit(1);
    }

    cout << code_str << "\n";

    uint32_t instr_len = xed_decoded_inst_get_length(&xedd);
    frontier += instr_len;
  }

  return 0;
}
