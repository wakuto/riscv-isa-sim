// vwmul.vx vd, vs2, rs1
VI_WIDE_CHECK_TWO;
VI_VX_LOOP
({
  V_WIDE_OP_AND_ASSIGN(vs2, rs1, 0, *, +, int);
})
