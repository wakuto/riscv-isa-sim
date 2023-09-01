reg_t tmp = npc;
set_pc((RS1 + insn.i_imm()) & ~reg_t(1));
WRITE_RD(tmp);

#include "cfi_common.h"
CFI_IS_LP_EXPECTED
