// vssrl.vv vd, vs2, vs1
VRM xrm = P.VU.get_vround_mode();
VI_VV_ULOOP
({
  uint64_t v2 = vs2;
  INT_ROUNDING(v2, xrm, 1);
  int sh = vs1 & ((1u << log2(sew * 2)) - 1);

  if (sh > 63)
    vd = (v2 >> 63) >> 1;
  else
    vd = v2 >> sh;
})
VI_CHECK_1905
