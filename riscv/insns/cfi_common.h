#define CFI_LANDING_PAD_FAULT  2
#define CFI_SHADOW_STACK_FAULT 3
#define CFI_LP_EXPECTED true
#define CFI_NO_LP_EXPECTED false

#define CFI_IS_LP_EXPECTED \
  if (p->extension_enabled(EXT_ZICFILP) && insn.rs1() != 1 && insn.rs1() != 5 && insn.rs1() != 7) { \
    p->set_elp(CFI_LP_EXPECTED); \
  }
