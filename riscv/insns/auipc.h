if (!p->extension_enabled(EXT_ZICFILP) ||
   (p->extension_enabled(EXT_ZICFILP) && (insn.rd() != 0))) { // auipc
  WRITE_RD(sext_xlen(insn.u_imm() + pc));
} else {
#include "cfi_common.h"

  require_extension(EXT_ZICFILP);
  bool xLPE = false;
  switch(STATE.prv) {
    case PRV_M: {
      xLPE = get_field(STATE.mseccfg->read(), MSECCFG_MLPE);
      break;
    }
    case PRV_S:
    case PRV_HS: {
      if (STATE.v) {  // VS-mode
        xLPE = get_field(STATE.henvcfg->read(), HENVCFG_LPE);
      } else {        // S or HS-mode
        xLPE = get_field(STATE.menvcfg->read(), MENVCFG_LPE);
      }
      break;
    }
    case PRV_U: {
        xLPE = get_field(STATE.senvcfg->read(), SENVCFG_LPE);
      break;
    }
    default: break;
  }

  uint32_t x7_31_12 = STATE.XPR[7] & 0xFFFFF000;
  uint32_t lpl = insn.u_imm();
  // printf("RUNNING LANDPAD!!!, xLPE=%d, is_aligned=%d, elp=%d, lpl=%x, x7[31:12]=%x\n", xLPE, is_aligned(pc, 4), STATE.elp, lpl, x7_31_12);
  // lpad operation
  if (xLPE) {
    // If PC not 4-byte aligned then software integrity fault
    if (!is_aligned(pc, 4))
      throw trap_software_error_exception(CFI_LANDING_PAD_FAULT);
    // If landing pad label not matched -> software integrity fault
    else if (lpl != x7_31_12 && lpl != 0 && STATE.elp == CFI_LP_EXPECTED)
      throw trap_software_error_exception(CFI_LANDING_PAD_FAULT);
    else
      p->set_elp(CFI_NO_LP_EXPECTED);
  }
}
