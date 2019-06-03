// vfmin vd, vs2, vs1
VFP_VV_LOOP
({
  switch(P.VU.vsew){
  case e32:
    vd = f32_min(vs2, vs1);
    break;
  case e16:
  case e8:
  default:
    softfloat_exceptionFlags = 1;
    break;
  };
})
