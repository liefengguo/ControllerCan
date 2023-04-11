#include "ecar.h"


uint8_t checksum(uint64_t* data) {
    uint8_t sum = 0;
    uint8_t* bytes = reinterpret_cast<uint8_t*>(data);
    for (int i = 0; i < 7; i++) {
        sum += bytes[i];
    }
    sum ^= 0xFF;

    return sum;
}

static inline uint64_t reverse_byte_order(uint64_t x) {
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8  | (x & 0xFF00FF00FF00FF00) >> 8;
	return x;
}
static inline int print_helper(int r, int print_return_value) {
	return ((r >= 0) && (print_return_value >= 0)) ? r + print_return_value : -1;
}
int decode_can_0x118_ADCU_Cld_TgtStrAngle(const CldDrv_118_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Cld_TgtStrAngle);
	rval *= 0.1;
	rval += -1000;
	if (rval <= 5553.5) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x118_ADCU_Cld_TgtStrAngle(CldDrv_118_t *o, double in) {
	assert(o);
	o->ADCU_Cld_TgtStrAngle = 0;
	if (in > 5553.5)
		return -1;
	in += 1000;
	in *= 10;
	o->ADCU_Cld_TgtStrAngle = in;
	return 0;
}

int decode_can_0x118_ADCU_Cld_TgtThrotVal(const CldDrv_118_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Cld_TgtThrotVal);
	rval *= 0.4;
	if (rval <= 102) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x118_ADCU_Cld_TgtThrotVal(CldDrv_118_t *o, double in) {
	assert(o);
	o->ADCU_Cld_TgtThrotVal = 0;
	if (in > 102)
		return -1;
	in *= 2.5;
	o->ADCU_Cld_TgtThrotVal = in;
	return 0;
}

int decode_can_0x118_ADCU_Cld_TgtBrkVal(const CldDrv_118_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Cld_TgtBrkVal);
	rval *= 0.4;
	if (rval <= 102) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x118_ADCU_Cld_TgtBrkVal(CldDrv_118_t *o, double in) {
	assert(o);
	o->ADCU_Cld_TgtBrkVal = 0;
	if (in > 102)
		return -1;
	in *= 2.5;
	o->ADCU_Cld_TgtBrkVal = in;
	return 0;
}

int decode_can_0x118_ADCU_CldDrvCmd_Checksum(const CldDrv_118_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldDrvCmd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x118_ADCU_CldDrvCmd_Checksum(CldDrv_118_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldDrvCmd_Checksum = in;
	return 0;
}

int decode_can_0x118_ADCU_Cld_TgtGear(const CldDrv_118_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_TgtGear);
	*out = rval;
	return 0;
}

int encode_can_0x118_ADCU_Cld_TgtGear(CldDrv_118_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_TgtGear = in;
	return 0;
}

int decode_can_0x118_ADCU_CldDrvCmd_RollCnt(const CldDrv_118_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldDrvCmd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x118_ADCU_CldDrvCmd_RollCnt(CldDrv_118_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldDrvCmd_RollCnt = in;
	return 0;
}

int decode_can_0x118_ADCU_Cld_DriveMode(const CldDrv_118_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_DriveMode);
	*out = rval;
	return 0;
}

int encode_can_0x118_ADCU_Cld_DriveMode(CldDrv_118_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_DriveMode = in;
	return 0;
}

int decode_can_0x118_ADCU_Cld_PrkEnable(const CldDrv_118_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_PrkEnable);
	*out = rval;
	return 0;
}

int encode_can_0x118_ADCU_Cld_PrkEnable(CldDrv_118_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_PrkEnable = in;
	return 0;
}

int decode_can_0x118_ADCU_Cld_CtrlActive(const CldDrv_118_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_CtrlActive);
	*out = rval;
	return 0;
}

int encode_can_0x118_ADCU_Cld_CtrlActive(CldDrv_118_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_CtrlActive = in;
	return 0;
}



int pack_can_0x118_ADCU_CldDrvCmd(CldDrv_118_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t m = 0;
	/* ADCU_Cld_TgtStrAngle: start-bit 31, length 16, endianess motorola, scaling 0.1, offset -1000 */
	x = ((uint16_t)(o->ADCU_Cld_TgtStrAngle)) & 0xffff;
	x <<= 24; 
	m |= x;
	/* ADCU_Cld_TgtThrotVal: start-bit 15, length 8, endianess motorola, scaling 0.4, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_TgtThrotVal)) & 0xff;
	x <<= 48; 
	m |= x;
	/* ADCU_Cld_TgtBrkVal: start-bit 23, length 8, endianess motorola, scaling 0.4, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_TgtBrkVal)) & 0xff;
	x <<= 40; 
	m |= x;
	/* ADCU_CldDrvCmd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldDrvCmd_Checksum)) & 0xff;
	m |= x;
	/* ADCU_Cld_TgtGear: start-bit 3, length 4, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_TgtGear)) & 0xf;
	x <<= 56; 
	m |= x;
	/* ADCU_CldDrvCmd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldDrvCmd_RollCnt)) & 0xf;
	x <<= 8; 
	m |= x;
	/* ADCU_Cld_DriveMode: start-bit 5, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_DriveMode)) & 0x3;
	x <<= 60; 
	m |= x;
	/* ADCU_Cld_PrkEnable: start-bit 6, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_PrkEnable)) & 0x1;
	x <<= 62; 
	m |= x;
	/* ADCU_Cld_CtrlActive: start-bit 7, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_CtrlActive)) & 0x1;
	x <<= 63; 
	m |= x;
	*data = reverse_byte_order(m);
	return 8;
}


int decode_can_0x119_ADCU_CldBodyCmd_Checksum(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldBodyCmd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_CldBodyCmd_Checksum(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldBodyCmd_Checksum = in;
	return 0;
}

int decode_can_0x119_ADCU_CldBodyCmd_RollCnt(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldBodyCmd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_CldBodyCmd_RollCnt(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldBodyCmd_RollCnt = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_FogLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_FogLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_FogLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_FogLamp_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_BrkLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_BrkLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_BrkLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_BrkLamp_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_WidthLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_WidthLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_WidthLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_WidthLamp_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_RunLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_RunLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_RunLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_RunLamp_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_Horn_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_Horn_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_Horn_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_Horn_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_Buzzer_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_Buzzer_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_Buzzer_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_Buzzer_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_BackLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_BackLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_BackLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_BackLamp_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_TurnRLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_TurnRLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_TurnRLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_TurnRLamp_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_TurnLLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_TurnLLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_TurnLLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_TurnLLamp_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_DblFlashLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_DblFlashLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_DblFlashLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_DblFlashLamp_Cmd = in;
	return 0;
}

int decode_can_0x119_ADCU_Cld_HeadLamp_Cmd(const CldBoby_119_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld_HeadLamp_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x119_ADCU_Cld_HeadLamp_Cmd(CldBoby_119_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld_HeadLamp_Cmd = in;
	return 0;
}


int decode_can_0x11a_ADCU_CldPwrCmd_Checksum(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldPwrCmd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_CldPwrCmd_Checksum(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldPwrCmd_Checksum = in;
	return 0;
}

int decode_can_0x11a_ADCU_CldPwrCmd_RollCnt(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldPwrCmd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_CldPwrCmd_RollCnt(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldPwrCmd_RollCnt = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld12VRCPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld12VRCPwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld12VRCPwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld12VRCPwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld12VMCPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld12VMCPwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld12VMCPwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld12VMCPwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_CldChasPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldChasPwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_CldChasPwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldChasPwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_CldVehPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldVehPwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_CldVehPwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldVehPwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld12VSC1Pwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld12VSC1Pwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld12VSC1Pwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld12VSC1Pwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_CldPA24VPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldPA24VPwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_CldPA24VPwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldPA24VPwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_CldPA12VPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldPA12VPwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_CldPA12VPwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldPA12VPwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld24VMCPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld24VMCPwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld24VMCPwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld24VMCPwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld12VSC3Pwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld12VSC3Pwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld12VSC3Pwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld12VSC3Pwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld12VSC2Pwrup_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld12VSC2Pwrup_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld12VSC2Pwrup_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld12VSC2Pwrup_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_CldPA24VPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldPA24VPwrdownCnfm_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_CldPA24VPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldPA24VPwrdownCnfm_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_CldPA12VPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_CldPA12VPwrdownCnfm_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_CldPA12VPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_CldPA12VPwrdownCnfm_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld24VMCPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld24VMCPwrdownCnfm_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld24VMCPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld24VMCPwrdownCnfm_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld12VRCPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld12VRCPwrdownCnfm_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld12VRCPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld12VRCPwrdownCnfm_Cmd = in;
	return 0;
}

int decode_can_0x11a_ADCU_Cld12VMCPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Cld12VMCPwrdownCnfm_Cmd);
	*out = rval;
	return 0;
}

int encode_can_0x11a_ADCU_Cld12VMCPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Cld12VMCPwrdownCnfm_Cmd = in;
	return 0;
}


int pack_can_0x119_ADCU_CldBodyCmd(CldBoby_119_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t m = 0;
	/* ADCU_CldBodyCmd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldBodyCmd_Checksum)) & 0xff;
	m |= x;
	/* ADCU_CldBodyCmd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldBodyCmd_RollCnt)) & 0xf;
	x <<= 8; 
	m |= x;
	/* ADCU_Cld_FogLamp_Cmd: start-bit 32, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_FogLamp_Cmd)) & 0x1;
	x <<= 24; 
	m |= x;
	/* ADCU_Cld_BrkLamp_Cmd: start-bit 33, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_BrkLamp_Cmd)) & 0x1;
	x <<= 25; 
	m |= x;
	/* ADCU_Cld_WidthLamp_Cmd: start-bit 34, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_WidthLamp_Cmd)) & 0x1;
	x <<= 26; 
	m |= x;
	/* ADCU_Cld_RunLamp_Cmd: start-bit 40, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_RunLamp_Cmd)) & 0x1;
	x <<= 16; 
	m |= x;
	/* ADCU_Cld_Horn_Cmd: start-bit 41, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_Horn_Cmd)) & 0x1;
	x <<= 17; 
	m |= x;
	/* ADCU_Cld_Buzzer_Cmd: start-bit 42, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_Buzzer_Cmd)) & 0x1;
	x <<= 18; 
	m |= x;
	/* ADCU_Cld_BackLamp_Cmd: start-bit 43, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_BackLamp_Cmd)) & 0x1;
	x <<= 19; 
	m |= x;
	/* ADCU_Cld_TurnRLamp_Cmd: start-bit 44, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_TurnRLamp_Cmd)) & 0x1;
	x <<= 20; 
	m |= x;
	/* ADCU_Cld_TurnLLamp_Cmd: start-bit 45, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_TurnLLamp_Cmd)) & 0x1;
	x <<= 21; 
	m |= x;
	/* ADCU_Cld_DblFlashLamp_Cmd: start-bit 46, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_DblFlashLamp_Cmd)) & 0x1;
	x <<= 22; 
	m |= x;
	/* ADCU_Cld_HeadLamp_Cmd: start-bit 47, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld_HeadLamp_Cmd)) & 0x1;
	x <<= 23; 
	m |= x;
	*data = reverse_byte_order(m);
	return 8;
}

int pack_can_0x11a_ADCU_CldPowerCmd(CldPower_11a_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t m = 0;
	/* ADCU_CldPwrCmd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldPwrCmd_Checksum)) & 0xff;
	m |= x;
	/* ADCU_CldPwrCmd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldPwrCmd_RollCnt)) & 0xf;
	x <<= 8; 
	m |= x;
	/* ADCU_Cld12VRCPwrup_Cmd: start-bit 1, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld12VRCPwrup_Cmd)) & 0x3;
	x <<= 56; 
	m |= x;
	/* ADCU_Cld12VMCPwrup_Cmd: start-bit 3, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld12VMCPwrup_Cmd)) & 0x3;
	x <<= 58; 
	m |= x;
	/* ADCU_CldChasPwrup_Cmd: start-bit 5, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldChasPwrup_Cmd)) & 0x3;
	x <<= 60; 
	m |= x;
	/* ADCU_CldVehPwrup_Cmd: start-bit 7, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldVehPwrup_Cmd)) & 0x3;
	x <<= 62; 
	m |= x;
	/* ADCU_Cld12VSC1Pwrup_Cmd: start-bit 9, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld12VSC1Pwrup_Cmd)) & 0x3;
	x <<= 48; 
	m |= x;
	/* ADCU_CldPA24VPwrup_Cmd: start-bit 11, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldPA24VPwrup_Cmd)) & 0x3;
	x <<= 50; 
	m |= x;
	/* ADCU_CldPA12VPwrup_Cmd: start-bit 13, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldPA12VPwrup_Cmd)) & 0x3;
	x <<= 52; 
	m |= x;
	/* ADCU_Cld24VMCPwrup_Cmd: start-bit 15, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld24VMCPwrup_Cmd)) & 0x3;
	x <<= 54; 
	m |= x;
	/* ADCU_Cld12VSC3Pwrup_Cmd: start-bit 21, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld12VSC3Pwrup_Cmd)) & 0x3;
	x <<= 44; 
	m |= x;
	/* ADCU_Cld12VSC2Pwrup_Cmd: start-bit 23, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld12VSC2Pwrup_Cmd)) & 0x3;
	x <<= 46; 
	m |= x;
	/* ADCU_CldPA24VPwrdownCnfm_Cmd: start-bit 35, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldPA24VPwrdownCnfm_Cmd)) & 0x1;
	x <<= 27; 
	m |= x;
	/* ADCU_CldPA12VPwrdownCnfm_Cmd: start-bit 36, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_CldPA12VPwrdownCnfm_Cmd)) & 0x1;
	x <<= 28; 
	m |= x;
	/* ADCU_Cld24VMCPwrdownCnfm_Cmd: start-bit 37, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld24VMCPwrdownCnfm_Cmd)) & 0x1;
	x <<= 29; 
	m |= x;
	/* ADCU_Cld12VRCPwrdownCnfm_Cmd: start-bit 38, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld12VRCPwrdownCnfm_Cmd)) & 0x1;
	x <<= 30; 
	m |= x;
	/* ADCU_Cld12VMCPwrdownCnfm_Cmd: start-bit 39, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Cld12VMCPwrdownCnfm_Cmd)) & 0x1;
	x <<= 31; 
	m |= x;
	*data = reverse_byte_order(m);
	return 8;
}
int unpack_can_0x215_CDCU_SteerStatus(can_0x215_CDCU_SteerStatus_t *o, uint64_t data, uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	register uint64_t x;
	register uint64_t m = reverse_byte_order(data);
	if (dlc < 8)
		return -1;
	/* CDCU_EPS_StrWhlAngle: start-bit 23, length 16, endianess motorola, scaling 0.005, offset -90 */
	x = (m >> 32) & 0xffff;
	o->CDCU_EPS_StrWhlAngle = x;
	/* CDCU_EPS_WhlSpd: start-bit 39, length 16, endianess motorola, scaling 0.01, offset -180 */
	x = (m >> 16) & 0xffff;
	o->CDCU_EPS_WhlSpd = x;
	/* CDCU_EPS_StrTrq: start-bit 15, length 8, endianess motorola, scaling 0.1, offset -12.8 */
	x = (m >> 48) & 0xff;
	o->CDCU_EPS_StrTrq = x;
	/* CDCU_StrSt_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = m & 0xff;
	o->CDCU_StrSt_Checksum = x;
	/* CDCU_EPS_WorkMode: start-bit 7, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 60) & 0xf;
	o->CDCU_EPS_WorkMode = x;
	/* CDCU_StrSt_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 8) & 0xf;
	o->CDCU_StrSt_RollCnt = x;
	/* CDCU_EPS_ErrLevel: start-bit 55, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 12) & 0xf;
	o->CDCU_EPS_ErrLevel = x;

	return 8;
}

int unpack_can_0x217_CDCU_DriveStatus(can_0x217_CDCU_DriveStatus_t *o, uint64_t data, uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	register uint64_t x;
	register uint64_t m = reverse_byte_order(data);
	if (dlc < 8)
		return -1;
	/* CDCU_MCU_MtrCurt: start-bit 23, length 16, endianess motorola, scaling 0.1, offset 0 */
	x = (m >> 32) & 0xffff;
	o->CDCU_MCU_MtrCurt = x;
	/* CDCU_MCU_MtrSpd: start-bit 39, length 16, endianess motorola, scaling 1, offset 0 */
	x = (m >> 16) & 0xffff;
	o->CDCU_MCU_MtrSpd = x;
	/* CDCU_MCU_ThrotAct: start-bit 15, length 8, endianess motorola, scaling 0.4, offset 0 */
	x = (m >> 48) & 0xff;
	o->CDCU_MCU_ThrotAct = x;
	/* CDCU_DrvSt_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = m & 0xff;
	o->CDCU_DrvSt_Checksum = x;
	/* CDCU_MCU_WorkMode: start-bit 7, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 60) & 0xf;
	o->CDCU_MCU_WorkMode = x;
	/* CDCU_DrvSt_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 8) & 0xf;
	o->CDCU_DrvSt_RollCnt = x;
	/* CDCU_MCU_ErrLevel: start-bit 55, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 12) & 0xf;
	o->CDCU_MCU_ErrLevel = x;
	/* CDCU_MCU_RunDir: start-bit 1, length 2, endianess motorola, scaling 1, offset 0 */
	x = (m >> 56) & 0x3;
	o->CDCU_MCU_RunDir = x;
	/* CDCU_MCU_GearAct: start-bit 3, length 2, endianess motorola, scaling 1, offset 0 */
	x = (m >> 58) & 0x3;
	o->CDCU_MCU_GearAct = x;

	return 8;
}

int unpack_can_0x250_CDCU_VehDyncState(can_0x250_CDCU_VehDyncState_t *o, uint64_t data, uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	register uint64_t x;
	register uint64_t m = reverse_byte_order(data);
	if (dlc < 8)
		return -1;
	/* CDCU_Veh_LongtdnalAccSpd: start-bit 7, length 16, endianess motorola, scaling 0.01, offset -40 */
	x = (m >> 48) & 0xffff;
	o->CDCU_Veh_LongtdnalAccSpd = x;
	/* CDCU_Veh_LongtdnalSpd: start-bit 23, length 16, endianess motorola, scaling 0.00390625, offset 0 */
	x = (m >> 32) & 0xffff;
	o->CDCU_Veh_LongtdnalSpd = x;
	/* CDCU_Veh_Curvture: start-bit 39, length 16, endianess motorola, scaling 0.0001, offset -3 */
	x = (m >> 16) & 0xffff;
	o->CDCU_Veh_Curvture = x;
	/* CDCU_VehDync_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = m & 0xff;
	o->CDCU_VehDync_Checksum = x;
	/* CDCU_VehDync_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 8) & 0xf;
	o->CDCU_VehDync_RollCnt = x;
	/* CDCU_Veh_RunDir: start-bit 55, length 2, endianess motorola, scaling 1, offset 0 */
	x = (m >> 14) & 0x3;
	o->CDCU_Veh_RunDir = x;

	return 8;
}

int unpack_can_0x251_CDCU_VehFtWhlSpd(can_0x251_CDCU_VehFtWhlSpd_t *o, uint64_t data, uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	register uint64_t x;
	register uint64_t m = reverse_byte_order(data);
	if (dlc < 8)
		return -1;
	/* CDCU_Veh_LfFtWhlSpd: start-bit 7, length 16, endianess motorola, scaling 0.01, offset 0 */
	x = (m >> 48) & 0xffff;
	o->CDCU_Veh_LfFtWhlSpd = x;
	/* CDCU_Veh_RtFtWhlSpd: start-bit 23, length 16, endianess motorola, scaling 0.01, offset 0 */
	x = (m >> 32) & 0xffff;
	o->CDCU_Veh_RtFtWhlSpd = x;
	/* CDCU_FtWhlSpd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = m & 0xff;
	o->CDCU_FtWhlSpd_Checksum = x;
	/* CDCU_FtWhlSpd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 8) & 0xf;
	o->CDCU_FtWhlSpd_RollCnt = x;
	/* CDCU_Veh_RtFtWhlSpdValid: start-bit 54, length 1, endianess motorola, scaling 1, offset 0 */
	x = (m >> 14) & 0x1;
	o->CDCU_Veh_RtFtWhlSpdValid = x;
	/* CDCU_Veh_LfFtWhlSpdValid: start-bit 55, length 1, endianess motorola, scaling 1, offset 0 */
	x = (m >> 15) & 0x1;
	o->CDCU_Veh_LfFtWhlSpdValid = x;
	return 8;
}

int unpack_can_0x252_CDCU_VehRrWhlSpd(can_0x252_CDCU_VehRrWhlSpd_t *o, uint64_t data, uint8_t dlc) {
	assert(o);
	assert(dlc <= 8);
	register uint64_t x;
	register uint64_t m = reverse_byte_order(data);
	if (dlc < 8)
		return -1;
	/* CDCU_Veh_LfRrWhlSpd: start-bit 7, length 16, endianess motorola, scaling 0.01, offset 0 */
	x = (m >> 48) & 0xffff;
	o->CDCU_Veh_LfRrWhlSpd = x;
	/* CDCU_Veh_RtRrWhlSpd: start-bit 23, length 16, endianess motorola, scaling 0.01, offset 0 */
	x = (m >> 32) & 0xffff;
	o->CDCU_Veh_RtRrWhlSpd = x;
	/* CDCU_RrWhlSpd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = m & 0xff;
	o->CDCU_RrWhlSpd_Checksum = x;
	/* CDCU_RrWhlSpd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = (m >> 8) & 0xf;
	o->CDCU_RrWhlSpd_RollCnt = x;
	/* CDCU_Veh_RtRrWhlSpdValid: start-bit 54, length 1, endianess motorola, scaling 1, offset 0 */
	x = (m >> 14) & 0x1;
	o->CDCU_Veh_RtRrWhlSpdValid = x;
	/* CDCU_Veh_LfRrWhlSpdValid: start-bit 55, length 1, endianess motorola, scaling 1, offset 0 */
	x = (m >> 15) & 0x1;
	o->CDCU_Veh_LfRrWhlSpdValid = x;

	return 8;
}


int decode_can_0x215_CDCU_EPS_StrWhlAngle(const can_0x215_CDCU_SteerStatus_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_EPS_StrWhlAngle);
	rval *= 0.005;
	rval += -90;
	if (rval <= 237.675) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x215_CDCU_EPS_StrWhlAngle(can_0x215_CDCU_SteerStatus_t *o, double in) {
	assert(o);
	o->CDCU_EPS_StrWhlAngle = 0;
	if (in > 237.675)
		return -1;
	in += 90;
	in *= 200;
	o->CDCU_EPS_StrWhlAngle = in;
	return 0;
}

int decode_can_0x215_CDCU_EPS_WhlSpd(const can_0x215_CDCU_SteerStatus_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_EPS_WhlSpd);
	rval *= 0.01;
	rval += -180;
	if (rval <= 475.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x215_CDCU_EPS_WhlSpd(can_0x215_CDCU_SteerStatus_t *o, double in) {
	assert(o);
	o->CDCU_EPS_WhlSpd = 0;
	if (in > 475.35)
		return -1;
	in += 180;
	in *= 100;
	o->CDCU_EPS_WhlSpd = in;
	return 0;
}

int decode_can_0x215_CDCU_EPS_StrTrq(const can_0x215_CDCU_SteerStatus_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_EPS_StrTrq);
	rval *= 0.1;
	rval += -12.8;
	if (rval <= 12.7) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x215_CDCU_EPS_StrTrq(can_0x215_CDCU_SteerStatus_t *o, double in) {
	assert(o);
	o->CDCU_EPS_StrTrq = 0;
	if (in > 12.7)
		return -1;
	in += 12.8;
	in *= 10;
	o->CDCU_EPS_StrTrq = in;
	return 0;
}

int decode_can_0x215_CDCU_StrSt_Checksum(const can_0x215_CDCU_SteerStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_StrSt_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x215_CDCU_StrSt_Checksum(can_0x215_CDCU_SteerStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_StrSt_Checksum = in;
	return 0;
}

int decode_can_0x215_CDCU_EPS_WorkMode(const can_0x215_CDCU_SteerStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_EPS_WorkMode);
	*out = rval;
	return 0;
}

int encode_can_0x215_CDCU_EPS_WorkMode(can_0x215_CDCU_SteerStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_EPS_WorkMode = in;
	return 0;
}

int decode_can_0x215_CDCU_StrSt_RollCnt(const can_0x215_CDCU_SteerStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_StrSt_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x215_CDCU_StrSt_RollCnt(can_0x215_CDCU_SteerStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_StrSt_RollCnt = in;
	return 0;
}

int decode_can_0x215_CDCU_EPS_ErrLevel(const can_0x215_CDCU_SteerStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_EPS_ErrLevel);
	*out = rval;
	return 0;
}

int encode_can_0x215_CDCU_EPS_ErrLevel(can_0x215_CDCU_SteerStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_EPS_ErrLevel = in;
	return 0;
}

int print_can_0x215_CDCU_SteerStatus(const can_0x215_CDCU_SteerStatus_t *o, FILE *output) {
	assert(o);
	assert(output);
	int r = 0;
	r = print_helper(r, fprintf(output, "CDCU_EPS_StrWhlAngle = (wire: %.0f)\n", (double)(o->CDCU_EPS_StrWhlAngle)));
	r = print_helper(r, fprintf(output, "CDCU_EPS_WhlSpd = (wire: %.0f)\n", (double)(o->CDCU_EPS_WhlSpd)));
	r = print_helper(r, fprintf(output, "CDCU_EPS_StrTrq = (wire: %.0f)\n", (double)(o->CDCU_EPS_StrTrq)));
	r = print_helper(r, fprintf(output, "CDCU_StrSt_Checksum = (wire: %.0f)\n", (double)(o->CDCU_StrSt_Checksum)));
	r = print_helper(r, fprintf(output, "CDCU_EPS_WorkMode = (wire: %.0f)\n", (double)(o->CDCU_EPS_WorkMode)));
	r = print_helper(r, fprintf(output, "CDCU_StrSt_RollCnt = (wire: %.0f)\n", (double)(o->CDCU_StrSt_RollCnt)));
	r = print_helper(r, fprintf(output, "CDCU_EPS_ErrLevel = (wire: %.0f)\n", (double)(o->CDCU_EPS_ErrLevel)));
	return r;
}


int decode_can_0x217_CDCU_MCU_MtrCurt(const can_0x217_CDCU_DriveStatus_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_MCU_MtrCurt);
	rval *= 0.1;
	if (rval <= 6553.5) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x217_CDCU_MCU_MtrCurt(can_0x217_CDCU_DriveStatus_t *o, double in) {
	assert(o);
	o->CDCU_MCU_MtrCurt = 0;
	if (in > 6553.5)
		return -1;
	in *= 10;
	o->CDCU_MCU_MtrCurt = in;
	return 0;
}

int decode_can_0x217_CDCU_MCU_MtrSpd(const can_0x217_CDCU_DriveStatus_t *o, uint16_t *out) {
	assert(o);
	assert(out);
	uint16_t rval = (uint16_t)(o->CDCU_MCU_MtrSpd);
	*out = rval;
	return 0;
}

int encode_can_0x217_CDCU_MCU_MtrSpd(can_0x217_CDCU_DriveStatus_t *o, uint16_t in) {
	assert(o);
	o->CDCU_MCU_MtrSpd = in;
	return 0;
}

int decode_can_0x217_CDCU_MCU_ThrotAct(const can_0x217_CDCU_DriveStatus_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_MCU_ThrotAct);
	rval *= 0.4;
	if (rval <= 102) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x217_CDCU_MCU_ThrotAct(can_0x217_CDCU_DriveStatus_t *o, double in) {
	assert(o);
	o->CDCU_MCU_ThrotAct = 0;
	if (in > 102)
		return -1;
	in *= 2.5;
	o->CDCU_MCU_ThrotAct = in;
	return 0;
}

int decode_can_0x217_CDCU_DrvSt_Checksum(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_DrvSt_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x217_CDCU_DrvSt_Checksum(can_0x217_CDCU_DriveStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_DrvSt_Checksum = in;
	return 0;
}

int decode_can_0x217_CDCU_MCU_WorkMode(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_MCU_WorkMode);
	*out = rval;
	return 0;
}

int encode_can_0x217_CDCU_MCU_WorkMode(can_0x217_CDCU_DriveStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_MCU_WorkMode = in;
	return 0;
}

int decode_can_0x217_CDCU_DrvSt_RollCnt(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_DrvSt_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x217_CDCU_DrvSt_RollCnt(can_0x217_CDCU_DriveStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_DrvSt_RollCnt = in;
	return 0;
}

int decode_can_0x217_CDCU_MCU_ErrLevel(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_MCU_ErrLevel);
	*out = rval;
	return 0;
}

int encode_can_0x217_CDCU_MCU_ErrLevel(can_0x217_CDCU_DriveStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_MCU_ErrLevel = in;
	return 0;
}

int decode_can_0x217_CDCU_MCU_RunDir(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_MCU_RunDir);
	*out = rval;
	return 0;
}

int encode_can_0x217_CDCU_MCU_RunDir(can_0x217_CDCU_DriveStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_MCU_RunDir = in;
	return 0;
}

int decode_can_0x217_CDCU_MCU_GearAct(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_MCU_GearAct);
	*out = rval;
	return 0;
}

int encode_can_0x217_CDCU_MCU_GearAct(can_0x217_CDCU_DriveStatus_t *o, uint8_t in) {
	assert(o);
	o->CDCU_MCU_GearAct = in;
	return 0;
}

int print_can_0x217_CDCU_DriveStatus(const can_0x217_CDCU_DriveStatus_t *o, FILE *output) {
	assert(o);
	assert(output);
	int r = 0;
	r = print_helper(r, fprintf(output, "CDCU_MCU_MtrCurt = (wire: %.0f)\n", (double)(o->CDCU_MCU_MtrCurt)));
	r = print_helper(r, fprintf(output, "CDCU_MCU_MtrSpd = (wire: %.0f)\n", (double)(o->CDCU_MCU_MtrSpd)));
	r = print_helper(r, fprintf(output, "CDCU_MCU_ThrotAct = (wire: %.0f)\n", (double)(o->CDCU_MCU_ThrotAct)));
	r = print_helper(r, fprintf(output, "CDCU_DrvSt_Checksum = (wire: %.0f)\n", (double)(o->CDCU_DrvSt_Checksum)));
	r = print_helper(r, fprintf(output, "CDCU_MCU_WorkMode = (wire: %.0f)\n", (double)(o->CDCU_MCU_WorkMode)));
	r = print_helper(r, fprintf(output, "CDCU_DrvSt_RollCnt = (wire: %.0f)\n", (double)(o->CDCU_DrvSt_RollCnt)));
	r = print_helper(r, fprintf(output, "CDCU_MCU_ErrLevel = (wire: %.0f)\n", (double)(o->CDCU_MCU_ErrLevel)));
	r = print_helper(r, fprintf(output, "CDCU_MCU_RunDir = (wire: %.0f)\n", (double)(o->CDCU_MCU_RunDir)));
	r = print_helper(r, fprintf(output, "CDCU_MCU_GearAct = (wire: %.0f)\n", (double)(o->CDCU_MCU_GearAct)));
	return r;
}

int decode_can_0x250_CDCU_Veh_LongtdnalAccSpd(const can_0x250_CDCU_VehDyncState_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_Veh_LongtdnalAccSpd);
	rval *= 0.01;
	rval += -40;
	if (rval <= 615.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x250_CDCU_Veh_LongtdnalAccSpd(can_0x250_CDCU_VehDyncState_t *o, double in) {
	assert(o);
	o->CDCU_Veh_LongtdnalAccSpd = 0;
	if (in > 615.35)
		return -1;
	in += 40;
	in *= 100;
	o->CDCU_Veh_LongtdnalAccSpd = in;
	return 0;
}

int decode_can_0x250_CDCU_Veh_LongtdnalSpd(const can_0x250_CDCU_VehDyncState_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_Veh_LongtdnalSpd);
	rval *= 0.00390625;
	if (rval <= 255.996) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x250_CDCU_Veh_LongtdnalSpd(can_0x250_CDCU_VehDyncState_t *o, double in) {
	assert(o);
	o->CDCU_Veh_LongtdnalSpd = 0;
	if (in > 255.996)
		return -1;
	in *= 256;
	o->CDCU_Veh_LongtdnalSpd = in;
	return 0;
}

int decode_can_0x250_CDCU_Veh_Curvture(const can_0x250_CDCU_VehDyncState_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_Veh_Curvture);
	rval *= 0.0001;
	rval += -3;
	if (rval <= 3.5535) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x250_CDCU_Veh_Curvture(can_0x250_CDCU_VehDyncState_t *o, double in) {
	assert(o);
	o->CDCU_Veh_Curvture = 0;
	if (in > 3.5535)
		return -1;
	in += 3;
	in *= 10000;
	o->CDCU_Veh_Curvture = in;
	return 0;
}

int decode_can_0x250_CDCU_VehDync_Checksum(const can_0x250_CDCU_VehDyncState_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_VehDync_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x250_CDCU_VehDync_Checksum(can_0x250_CDCU_VehDyncState_t *o, uint8_t in) {
	assert(o);
	o->CDCU_VehDync_Checksum = in;
	return 0;
}

int decode_can_0x250_CDCU_VehDync_RollCnt(const can_0x250_CDCU_VehDyncState_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_VehDync_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x250_CDCU_VehDync_RollCnt(can_0x250_CDCU_VehDyncState_t *o, uint8_t in) {
	assert(o);
	o->CDCU_VehDync_RollCnt = in;
	return 0;
}

int decode_can_0x250_CDCU_Veh_RunDir(const can_0x250_CDCU_VehDyncState_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_Veh_RunDir);
	*out = rval;
	return 0;
}

int encode_can_0x250_CDCU_Veh_RunDir(can_0x250_CDCU_VehDyncState_t *o, uint8_t in) {
	assert(o);
	o->CDCU_Veh_RunDir = in;
	return 0;
}

int print_can_0x250_CDCU_VehDyncState(const can_0x250_CDCU_VehDyncState_t *o, FILE *output) {
	assert(o);
	assert(output);
	int r = 0;
	r = print_helper(r, fprintf(output, "CDCU_Veh_LongtdnalAccSpd = (wire: %.0f)\n", (double)(o->CDCU_Veh_LongtdnalAccSpd)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_LongtdnalSpd = (wire: %.0f)\n", (double)(o->CDCU_Veh_LongtdnalSpd)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_Curvture = (wire: %.0f)\n", (double)(o->CDCU_Veh_Curvture)));
	r = print_helper(r, fprintf(output, "CDCU_VehDync_Checksum = (wire: %.0f)\n", (double)(o->CDCU_VehDync_Checksum)));
	r = print_helper(r, fprintf(output, "CDCU_VehDync_RollCnt = (wire: %.0f)\n", (double)(o->CDCU_VehDync_RollCnt)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_RunDir = (wire: %.0f)\n", (double)(o->CDCU_Veh_RunDir)));
	return r;
}


int decode_can_0x251_CDCU_Veh_LfFtWhlSpd(const can_0x251_CDCU_VehFtWhlSpd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_Veh_LfFtWhlSpd);
	rval *= 0.01;
	if (rval <= 655.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x251_CDCU_Veh_LfFtWhlSpd(can_0x251_CDCU_VehFtWhlSpd_t *o, double in) {
	assert(o);
	o->CDCU_Veh_LfFtWhlSpd = 0;
	if (in > 655.35)
		return -1;
	in *= 100;
	o->CDCU_Veh_LfFtWhlSpd = in;
	return 0;
}

int decode_can_0x251_CDCU_Veh_RtFtWhlSpd(const can_0x251_CDCU_VehFtWhlSpd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_Veh_RtFtWhlSpd);
	rval *= 0.01;
	if (rval <= 655.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x251_CDCU_Veh_RtFtWhlSpd(can_0x251_CDCU_VehFtWhlSpd_t *o, double in) {
	assert(o);
	o->CDCU_Veh_RtFtWhlSpd = 0;
	if (in > 655.35)
		return -1;
	in *= 100;
	o->CDCU_Veh_RtFtWhlSpd = in;
	return 0;
}

int decode_can_0x251_CDCU_FtWhlSpd_Checksum(const can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_FtWhlSpd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x251_CDCU_FtWhlSpd_Checksum(can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t in) {
	assert(o);
	o->CDCU_FtWhlSpd_Checksum = in;
	return 0;
}

int decode_can_0x251_CDCU_FtWhlSpd_RollCnt(const can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_FtWhlSpd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x251_CDCU_FtWhlSpd_RollCnt(can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t in) {
	assert(o);
	o->CDCU_FtWhlSpd_RollCnt = in;
	return 0;
}

int decode_can_0x251_CDCU_Veh_RtFtWhlSpdValid(const can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_Veh_RtFtWhlSpdValid);
	*out = rval;
	return 0;
}

int encode_can_0x251_CDCU_Veh_RtFtWhlSpdValid(can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t in) {
	assert(o);
	o->CDCU_Veh_RtFtWhlSpdValid = in;
	return 0;
}

int decode_can_0x251_CDCU_Veh_LfFtWhlSpdValid(const can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_Veh_LfFtWhlSpdValid);
	*out = rval;
	return 0;
}

int encode_can_0x251_CDCU_Veh_LfFtWhlSpdValid(can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t in) {
	assert(o);
	o->CDCU_Veh_LfFtWhlSpdValid = in;
	return 0;
}

int print_can_0x251_CDCU_VehFtWhlSpd(const can_0x251_CDCU_VehFtWhlSpd_t *o, FILE *output) {
	assert(o);
	assert(output);
	int r = 0;
	r = print_helper(r, fprintf(output, "CDCU_Veh_LfFtWhlSpd = (wire: %.0f)\n", (double)(o->CDCU_Veh_LfFtWhlSpd)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_RtFtWhlSpd = (wire: %.0f)\n", (double)(o->CDCU_Veh_RtFtWhlSpd)));
	r = print_helper(r, fprintf(output, "CDCU_FtWhlSpd_Checksum = (wire: %.0f)\n", (double)(o->CDCU_FtWhlSpd_Checksum)));
	r = print_helper(r, fprintf(output, "CDCU_FtWhlSpd_RollCnt = (wire: %.0f)\n", (double)(o->CDCU_FtWhlSpd_RollCnt)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_RtFtWhlSpdValid = (wire: %.0f)\n", (double)(o->CDCU_Veh_RtFtWhlSpdValid)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_LfFtWhlSpdValid = (wire: %.0f)\n", (double)(o->CDCU_Veh_LfFtWhlSpdValid)));
	return r;
}

int decode_can_0x252_CDCU_Veh_LfRrWhlSpd(const can_0x252_CDCU_VehRrWhlSpd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_Veh_LfRrWhlSpd);
	rval *= 0.01;
	if (rval <= 655.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x252_CDCU_Veh_LfRrWhlSpd(can_0x252_CDCU_VehRrWhlSpd_t *o, double in) {
	assert(o);
	o->CDCU_Veh_LfRrWhlSpd = 0;
	if (in > 655.35)
		return -1;
	in *= 100;
	o->CDCU_Veh_LfRrWhlSpd = in;
	return 0;
}

int decode_can_0x252_CDCU_Veh_RtRrWhlSpd(const can_0x252_CDCU_VehRrWhlSpd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->CDCU_Veh_RtRrWhlSpd);
	rval *= 0.01;
	if (rval <= 655.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x252_CDCU_Veh_RtRrWhlSpd(can_0x252_CDCU_VehRrWhlSpd_t *o, double in) {
	assert(o);
	o->CDCU_Veh_RtRrWhlSpd = 0;
	if (in > 655.35)
		return -1;
	in *= 100;
	o->CDCU_Veh_RtRrWhlSpd = in;
	return 0;
}

int decode_can_0x252_CDCU_RrWhlSpd_Checksum(const can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_RrWhlSpd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x252_CDCU_RrWhlSpd_Checksum(can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t in) {
	assert(o);
	o->CDCU_RrWhlSpd_Checksum = in;
	return 0;
}

int decode_can_0x252_CDCU_RrWhlSpd_RollCnt(const can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_RrWhlSpd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x252_CDCU_RrWhlSpd_RollCnt(can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t in) {
	assert(o);
	o->CDCU_RrWhlSpd_RollCnt = in;
	return 0;
}

int decode_can_0x252_CDCU_Veh_RtRrWhlSpdValid(const can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_Veh_RtRrWhlSpdValid);
	*out = rval;
	return 0;
}

int encode_can_0x252_CDCU_Veh_RtRrWhlSpdValid(can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t in) {
	assert(o);
	o->CDCU_Veh_RtRrWhlSpdValid = in;
	return 0;
}

int decode_can_0x252_CDCU_Veh_LfRrWhlSpdValid(const can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->CDCU_Veh_LfRrWhlSpdValid);
	*out = rval;
	return 0;
}

int encode_can_0x252_CDCU_Veh_LfRrWhlSpdValid(can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t in) {
	assert(o);
	o->CDCU_Veh_LfRrWhlSpdValid = in;
	return 0;
}

int print_can_0x252_CDCU_VehRrWhlSpd(const can_0x252_CDCU_VehRrWhlSpd_t *o, FILE *output) {
	assert(o);
	assert(output);
	int r = 0;
	r = print_helper(r, fprintf(output, "CDCU_Veh_LfRrWhlSpd = (wire: %.0f)\n", (double)(o->CDCU_Veh_LfRrWhlSpd)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_RtRrWhlSpd = (wire: %.0f)\n", (double)(o->CDCU_Veh_RtRrWhlSpd)));
	r = print_helper(r, fprintf(output, "CDCU_RrWhlSpd_Checksum = (wire: %.0f)\n", (double)(o->CDCU_RrWhlSpd_Checksum)));
	r = print_helper(r, fprintf(output, "CDCU_RrWhlSpd_RollCnt = (wire: %.0f)\n", (double)(o->CDCU_RrWhlSpd_RollCnt)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_RtRrWhlSpdValid = (wire: %.0f)\n", (double)(o->CDCU_Veh_RtRrWhlSpdValid)));
	r = print_helper(r, fprintf(output, "CDCU_Veh_LfRrWhlSpdValid = (wire: %.0f)\n", (double)(o->CDCU_Veh_LfRrWhlSpdValid)));
	return r;
}


int pack_can_0x111_ADCU_BrakeCmd(can_0x111_ADCU_BrakeCmd_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t m = 0;
	/* ADCU_Brk_TgtPress: start-bit 23, length 16, endianess motorola, scaling 0.01, offset 0 */
	x = ((uint16_t)(o->ADCU_Brk_TgtPress)) & 0xffff;
	x <<= 32; 
	m |= x;
	/* ADCU_Brk_TgtAccSpd: start-bit 39, length 16, endianess motorola, scaling 0.01, offset -20 */
	x = ((uint16_t)(o->ADCU_Brk_TgtAccSpd)) & 0xffff;
	x <<= 16; 
	m |= x;
	/* ADCU_Brk_TgtPedpos: start-bit 15, length 8, endianess motorola, scaling 0.4, offset 0 */
	x = ((uint8_t)(o->ADCU_Brk_TgtPedpos)) & 0xff;
	x <<= 48; 
	m |= x;
	/* ADCU_BrkCmd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_BrkCmd_Checksum)) & 0xff;
	m |= x;
	/* ADCU_BrkCmd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_BrkCmd_RollCnt)) & 0xf;
	x <<= 8; 
	m |= x;
	/* ADCU_Brk_CtrlMode: start-bit 6, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Brk_CtrlMode)) & 0x3;
	x <<= 61; 
	m |= x;
	/* ADCU_Brk_Active: start-bit 7, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Brk_Active)) & 0x1;
	x <<= 63; 
	m |= x;
	*data = reverse_byte_order(m);
	return 8;
}

int decode_can_0x111_ADCU_Brk_TgtPress(const can_0x111_ADCU_BrakeCmd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Brk_TgtPress);
	rval *= 0.01;
	if (rval <= 655.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x111_ADCU_Brk_TgtPress(can_0x111_ADCU_BrakeCmd_t *o, double in) {
	assert(o);
	o->ADCU_Brk_TgtPress = 0;
	if (in > 655.35)
		return -1;
	in *= 100;
	o->ADCU_Brk_TgtPress = in;
	return 0;
}

int decode_can_0x111_ADCU_Brk_TgtAccSpd(const can_0x111_ADCU_BrakeCmd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Brk_TgtAccSpd);
	rval *= 0.01;
	rval += -20;
	if (rval <= 635.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x111_ADCU_Brk_TgtAccSpd(can_0x111_ADCU_BrakeCmd_t *o, double in) {
	assert(o);
	o->ADCU_Brk_TgtAccSpd = 0;
	if (in > 635.35)
		return -1;
	in += 20;
	in *= 100;
	o->ADCU_Brk_TgtAccSpd = in;
	return 0;
}

int decode_can_0x111_ADCU_Brk_TgtPedpos(const can_0x111_ADCU_BrakeCmd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Brk_TgtPedpos);
	rval *= 0.4;
	if (rval <= 102) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x111_ADCU_Brk_TgtPedpos(can_0x111_ADCU_BrakeCmd_t *o, double in) {
	assert(o);
	o->ADCU_Brk_TgtPedpos = 0;
	if (in > 102)
		return -1;
	in *= 2.5;
	o->ADCU_Brk_TgtPedpos = in;
	return 0;
}

int decode_can_0x111_ADCU_BrkCmd_Checksum(const can_0x111_ADCU_BrakeCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_BrkCmd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x111_ADCU_BrkCmd_Checksum(can_0x111_ADCU_BrakeCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_BrkCmd_Checksum = in;
	return 0;
}

int decode_can_0x111_ADCU_BrkCmd_RollCnt(const can_0x111_ADCU_BrakeCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_BrkCmd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x111_ADCU_BrkCmd_RollCnt(can_0x111_ADCU_BrakeCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_BrkCmd_RollCnt = in;
	return 0;
}

int decode_can_0x111_ADCU_Brk_CtrlMode(const can_0x111_ADCU_BrakeCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Brk_CtrlMode);
	*out = rval;
	return 0;
}

int encode_can_0x111_ADCU_Brk_CtrlMode(can_0x111_ADCU_BrakeCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Brk_CtrlMode = in;
	return 0;
}

int decode_can_0x111_ADCU_Brk_Active(const can_0x111_ADCU_BrakeCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Brk_Active);
	*out = rval;
	return 0;
}

int encode_can_0x111_ADCU_Brk_Active(can_0x111_ADCU_BrakeCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Brk_Active = in;
	return 0;
}
int pack_can_0x112_ADCU_ParkCmd(can_0x112_ADCU_ParkCmd_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t m = 0;
	/* ADCU_PrkCmd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_PrkCmd_Checksum)) & 0xff;
	m |= x;
	/* ADCU_PrkCmd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_PrkCmd_RollCnt)) & 0xf;
	x <<= 8; 
	m |= x;
	/* ADCU_Prk_Enable: start-bit 6, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Prk_Enable)) & 0x1;
	x <<= 62; 
	m |= x;
	/* ADCU_Prk_Active: start-bit 7, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Prk_Active)) & 0x1;
	x <<= 63; 
	m |= x;
	*data = reverse_byte_order(m);
	return 8;
}


int decode_can_0x112_ADCU_PrkCmd_Checksum(const can_0x112_ADCU_ParkCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_PrkCmd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x112_ADCU_PrkCmd_Checksum(can_0x112_ADCU_ParkCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_PrkCmd_Checksum = in;
	return 0;
}

int decode_can_0x112_ADCU_PrkCmd_RollCnt(const can_0x112_ADCU_ParkCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_PrkCmd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x112_ADCU_PrkCmd_RollCnt(can_0x112_ADCU_ParkCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_PrkCmd_RollCnt = in;
	return 0;
}

int decode_can_0x112_ADCU_Prk_Enable(const can_0x112_ADCU_ParkCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Prk_Enable);
	*out = rval;
	return 0;
}

int encode_can_0x112_ADCU_Prk_Enable(can_0x112_ADCU_ParkCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Prk_Enable = in;
	return 0;
}

int decode_can_0x112_ADCU_Prk_Active(const can_0x112_ADCU_ParkCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Prk_Active);
	*out = rval;
	return 0;
}

int encode_can_0x112_ADCU_Prk_Active(can_0x112_ADCU_ParkCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Prk_Active = in;
	return 0;
}

int pack_can_0x113_ADCU_SteerCmd(can_0x113_ADCU_SteerCmd_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t m = 0;
	/* ADCU_Str_TgtAngle: start-bit 15, length 16, endianess motorola, scaling 0.005, offset -90 */
	x = ((uint16_t)(o->ADCU_Str_TgtAngle)) & 0xffff;
	x <<= 40; 
	m |= x;
	/* ADCU_Str_TgtCurvature: start-bit 31, length 16, endianess motorola, scaling 0.0001, offset -3 */
	x = ((uint16_t)(o->ADCU_Str_TgtCurvature)) & 0xffff;
	x <<= 24; 
	m |= x;
	/* ADCU_Str_TgtAngleSpd: start-bit 47, length 8, endianess motorola, scaling 0.2, offset 0 */
	x = ((uint8_t)(o->ADCU_Str_TgtAngleSpd)) & 0xff;
	x <<= 16; 
	m |= x;
	/* ADCU_StrCmd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_StrCmd_Checksum)) & 0xff;
	m |= x;
	/* ADCU_StrCmd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_StrCmd_RollCnt)) & 0xf;
	x <<= 8; 
	m |= x;
	/* ADCU_Str_CtrlMode: start-bit 6, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Str_CtrlMode)) & 0x3;
	x <<= 61; 
	m |= x;
	/* ADCU_Str_Active: start-bit 7, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Str_Active)) & 0x1;
	x <<= 63; 
	m |= x;
	*data = reverse_byte_order(m);
	return 8;
}

int decode_can_0x113_ADCU_Str_TgtAngle(const can_0x113_ADCU_SteerCmd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Str_TgtAngle);
	rval *= 0.005;
	rval += -90;
	if (rval <= 237.675) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x113_ADCU_Str_TgtAngle(can_0x113_ADCU_SteerCmd_t *o, double in) {
	assert(o);
	o->ADCU_Str_TgtAngle = 0;
	if (in > 237.675)
		return -1;
	in += 90;
	in *= 200;
	o->ADCU_Str_TgtAngle = in;
	return 0;
}

int decode_can_0x113_ADCU_Str_TgtCurvature(const can_0x113_ADCU_SteerCmd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Str_TgtCurvature);
	rval *= 0.0001;
	rval += -3;
	if (rval <= 3.5535) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x113_ADCU_Str_TgtCurvature(can_0x113_ADCU_SteerCmd_t *o, double in) {
	assert(o);
	o->ADCU_Str_TgtCurvature = 0;
	if (in > 3.5535)
		return -1;
	in += 3;
	in *= 10000;
	o->ADCU_Str_TgtCurvature = in;
	return 0;
}

int decode_can_0x113_ADCU_Str_TgtAngleSpd(const can_0x113_ADCU_SteerCmd_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Str_TgtAngleSpd);
	rval *= 0.2;
	if (rval <= 51) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x113_ADCU_Str_TgtAngleSpd(can_0x113_ADCU_SteerCmd_t *o, double in) {
	assert(o);
	o->ADCU_Str_TgtAngleSpd = 0;
	if (in > 51)
		return -1;
	in *= 5;
	o->ADCU_Str_TgtAngleSpd = in;
	return 0;
}

int decode_can_0x113_ADCU_StrCmd_Checksum(const can_0x113_ADCU_SteerCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_StrCmd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x113_ADCU_StrCmd_Checksum(can_0x113_ADCU_SteerCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_StrCmd_Checksum = in;
	return 0;
}

int decode_can_0x113_ADCU_StrCmd_RollCnt(const can_0x113_ADCU_SteerCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_StrCmd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x113_ADCU_StrCmd_RollCnt(can_0x113_ADCU_SteerCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_StrCmd_RollCnt = in;
	return 0;
}

int decode_can_0x113_ADCU_Str_CtrlMode(const can_0x113_ADCU_SteerCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Str_CtrlMode);
	*out = rval;
	return 0;
}

int encode_can_0x113_ADCU_Str_CtrlMode(can_0x113_ADCU_SteerCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Str_CtrlMode = in;
	return 0;
}

int decode_can_0x113_ADCU_Str_Active(const can_0x113_ADCU_SteerCmd_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Str_Active);
	*out = rval;
	return 0;
}

int encode_can_0x113_ADCU_Str_Active(can_0x113_ADCU_SteerCmd_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Str_Active = in;
	return 0;
}
int pack_can_0x114_ADCU_DriveCmd0(can_0x114_ADCU_DriveCmd0_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t m = 0;
	/* ADCU_Drv_TgtVehSpd0: start-bit 23, length 16, endianess motorola, scaling 0.01, offset -100 */
	x = ((uint16_t)(o->ADCU_Drv_TgtVehSpd0)) & 0xffff;
	x <<= 32; 
	m |= x;
	/* ADCU_Drv_TgtPedpos: start-bit 15, length 8, endianess motorola, scaling 1, offset -100 */
	x = ((uint8_t)(o->ADCU_Drv_TgtPedpos)) & 0xff;
	x <<= 48; 
	m |= x;
	/* ADCU_Drv_TgtVehAccSpd: start-bit 39, length 8, endianess motorola, scaling 0.1, offset -15 */
	x = ((uint8_t)(o->ADCU_Drv_TgtVehAccSpd)) & 0xff;
	x <<= 24; 
	m |= x;
	/* ADCU_Drv_VehSpdLimit: start-bit 47, length 8, endianess motorola, scaling 0.4, offset 0 */
	x = ((uint8_t)(o->ADCU_Drv_VehSpdLimit)) & 0xff;
	x <<= 16; 
	m |= x;
	/* ADCU_DrvCmd_Checksum: start-bit 63, length 8, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_DrvCmd_Checksum)) & 0xff;
	m |= x;
	/* ADCU_DrvCmd_RollCnt: start-bit 51, length 4, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_DrvCmd_RollCnt)) & 0xf;
	x <<= 8; 
	m |= x;
	/* ADCU_Drv_TgtGear: start-bit 1, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Drv_TgtGear)) & 0x3;
	x <<= 56; 
	m |= x;
	/* ADCU_Drv_CtrlMode: start-bit 6, length 2, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Drv_CtrlMode)) & 0x3;
	x <<= 61; 
	m |= x;
	/* ADCU_Drv_Active: start-bit 7, length 1, endianess motorola, scaling 1, offset 0 */
	x = ((uint8_t)(o->ADCU_Drv_Active)) & 0x1;
	x <<= 63; 
	m |= x;
	*data = reverse_byte_order(m);
	return 8;
}


int decode_can_0x114_ADCU_Drv_TgtVehSpd0(const can_0x114_ADCU_DriveCmd0_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Drv_TgtVehSpd0);
	rval *= 0.01;
	rval += -100;
	if (rval <= 555.35) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x114_ADCU_Drv_TgtVehSpd0(can_0x114_ADCU_DriveCmd0_t *o, double in) {
	assert(o);
	o->ADCU_Drv_TgtVehSpd0 = 0;
	if (in > 555.35)
		return -1;
	in += 100;
	in *= 100;
	o->ADCU_Drv_TgtVehSpd0 = in;
	return 0;
}

int decode_can_0x114_ADCU_Drv_TgtPedpos(const can_0x114_ADCU_DriveCmd0_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Drv_TgtPedpos);
	rval += -100;
	if (rval <= 155) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x114_ADCU_Drv_TgtPedpos(can_0x114_ADCU_DriveCmd0_t *o, double in) {
	assert(o);
	o->ADCU_Drv_TgtPedpos = 0;
	if (in > 155)
		return -1;
	in += 100;
	o->ADCU_Drv_TgtPedpos = in;
	return 0;
}

int decode_can_0x114_ADCU_Drv_TgtVehAccSpd(const can_0x114_ADCU_DriveCmd0_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Drv_TgtVehAccSpd);
	rval *= 0.1;
	rval += -15;
	if (rval <= 10.5) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x114_ADCU_Drv_TgtVehAccSpd(can_0x114_ADCU_DriveCmd0_t *o, double in) {
	assert(o);
	o->ADCU_Drv_TgtVehAccSpd = 0;
	if (in > 10.5)
		return -1;
	in += 15;
	in *= 10;
	o->ADCU_Drv_TgtVehAccSpd = in;
	return 0;
}

int decode_can_0x114_ADCU_Drv_VehSpdLimit(const can_0x114_ADCU_DriveCmd0_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->ADCU_Drv_VehSpdLimit);
	rval *= 0.4;
	if (rval <= 102) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x114_ADCU_Drv_VehSpdLimit(can_0x114_ADCU_DriveCmd0_t *o, double in) {
	assert(o);
	o->ADCU_Drv_VehSpdLimit = 0;
	if (in > 102)
		return -1;
	in *= 2.5;
	o->ADCU_Drv_VehSpdLimit = in;
	return 0;
}

int decode_can_0x114_ADCU_DrvCmd_Checksum(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_DrvCmd_Checksum);
	*out = rval;
	return 0;
}

int encode_can_0x114_ADCU_DrvCmd_Checksum(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in) {
	assert(o);
	o->ADCU_DrvCmd_Checksum = in;
	return 0;
}

int decode_can_0x114_ADCU_DrvCmd_RollCnt(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_DrvCmd_RollCnt);
	*out = rval;
	return 0;
}

int encode_can_0x114_ADCU_DrvCmd_RollCnt(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in) {
	assert(o);
	o->ADCU_DrvCmd_RollCnt = in;
	return 0;
}

int decode_can_0x114_ADCU_Drv_TgtGear(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Drv_TgtGear);
	*out = rval;
	return 0;
}

int encode_can_0x114_ADCU_Drv_TgtGear(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Drv_TgtGear = in;
	return 0;
}

int decode_can_0x114_ADCU_Drv_CtrlMode(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Drv_CtrlMode);
	*out = rval;
	return 0;
}

int encode_can_0x114_ADCU_Drv_CtrlMode(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Drv_CtrlMode = in;
	return 0;
}

int decode_can_0x114_ADCU_Drv_Active(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out) {
	assert(o);
	assert(out);
	uint8_t rval = (uint8_t)(o->ADCU_Drv_Active);
	*out = rval;
	return 0;
}

int encode_can_0x114_ADCU_Drv_Active(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in) {
	assert(o);
	o->ADCU_Drv_Active = in;
	return 0;
}
