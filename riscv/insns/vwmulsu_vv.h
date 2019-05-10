// vwmulsu.vv vd, vs2, vs1
VI_WIDE_CHECK_TWO;
VI_VV_LOOP
({
  switch(p->VU.vsew) {
  case e8:
    p->VU.elt<uint16_t>(rd_num, i) = (int16_t)(int8_t)vs2 * (int16_t)(uint8_t)vs1;
    break;
  case e16:
    p->VU.elt<uint32_t>(rd_num, i) = (int32_t)(int16_t)vs2 * (int32_t)(uint16_t)vs1;
    break;
  default:
    p->VU.elt<uint64_t>(rd_num, i) = (int64_t)(int32_t)vs2 * (int64_t)(uint32_t)vs1;
    break;
  }
})
