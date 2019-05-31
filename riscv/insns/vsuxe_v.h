// vsxe.v and vsxseg[2-8]e.v
const reg_t sew = p->VU.vsew;
const reg_t vl = p->VU.vl;
require(sew >= e8 && sew <= e64);
reg_t baseAddr = RS1;
reg_t stride = insn.rs2();
reg_t vs3 = insn.rd();
reg_t vlmax = p->VU.vlmax;
DUPLICATE_VREG(stride, vlmax);
for (reg_t i = 0; i < vlmax && vl != 0; ++i) {
  bool is_valid = true;
  V_ELEMENT_SKIP(i);
  STRIP(i)

  switch (sew) {
  case e8:
    if (is_valid)
      MMU.store_uint8(baseAddr + index[i],
                      p->VU.elt<uint8_t>(vs3, vreg_inx));
    break;
  case e16:
    if (is_valid)
      MMU.store_uint16(baseAddr + index[i],
                       p->VU.elt<uint16_t>(vs3, vreg_inx));
    break;
  case e32:
    if (is_valid)
      MMU.store_uint32(baseAddr + index[i],
                       p->VU.elt<uint32_t>(vs3, vreg_inx));
    break;
  case e64:
    if (is_valid)
      MMU.store_uint64(baseAddr + index[i],
                       p->VU.elt<uint64_t>(vs3, vreg_inx));
    break;
  }
}
p->VU.vstart = 0;
VI_CHECK_1905
