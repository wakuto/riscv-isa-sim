require_extension(EXT_ZCA);
require(insn.rvc_rs1() != 0);
set_pc(RVC_RS1 & ~reg_t(1));

#include "cfi_common.h"
CFI_IS_LP_EXPECTED
