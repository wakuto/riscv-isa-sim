// vssra.vi vd, vs2, simm5
VRM xrm = P.VU.get_vround_mode();
VI_VI_ULOOP
({
  uint64_t v2 = vs2;
  INT_ROUNDING(v2, xrm, 1);
  vd = v2 >> (simm5 & ((1u << log2(sew * 2)) - 1) & 0x1f);
})
VI_CHECK_1905
