#ifndef YICAR_H
#define YICAR_H
#include <inttypes.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#ifndef DBCC_TIME_STAMP
#define DBCC_TIME_STAMP
typedef uint32_t dbcc_time_stamp_t; /* Time stamp for message; you decide on units */
#endif

typedef  struct {
	uint16_t ADCU_Brk_TgtPress; /* scaling 0.0, offset 0.0, units bar  */
	uint16_t ADCU_Brk_TgtAccSpd; /* scaling 0.0, offset -20.0, units mps2  */
	uint8_t ADCU_Brk_TgtPedpos; /* scaling 0.4, offset 0.0, units %  */
	/* ADCU_BrkCmd_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
	/* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_BrkCmd_Checksum;
	uint8_t ADCU_BrkCmd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Brk_CtrlMode; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Brk_Active; /* scaling 1.0, offset 0.0, units none  */
}  can_0x111_ADCU_BrakeCmd_t;

typedef  struct {
	/* ADCU_PrkCmd_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
	/* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_PrkCmd_Checksum;
	uint8_t ADCU_PrkCmd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Prk_Enable; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Prk_Active; /* scaling 1.0, offset 0.0, units none  */
}  can_0x112_ADCU_ParkCmd_t;

typedef  struct {
	uint16_t ADCU_Str_TgtAngle; /* scaling 0.0, offset -90.0, units deg  */
	uint16_t ADCU_Str_TgtCurvature; /* scaling 0.0, offset -3.0, units 1/m  */
	uint8_t ADCU_Str_TgtAngleSpd; /* scaling 0.2, offset 0.0, units deg/s  */
	/* ADCU_StrCmd_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
	/* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_StrCmd_Checksum;
	uint8_t ADCU_StrCmd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Str_CtrlMode; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Str_Active; /* scaling 1.0, offset 0.0, units none  */
}  can_0x113_ADCU_SteerCmd_t;

typedef  struct {
	uint16_t ADCU_Drv_TgtVehSpd0; /* scaling 0.0, offset -100.0, units Kmph  */
	uint8_t ADCU_Drv_TgtPedpos; /* scaling 1.0, offset -100.0, units %  */
	uint8_t ADCU_Drv_TgtVehAccSpd; /* scaling 0.1, offset -15.0, units mps2  */
	uint8_t ADCU_Drv_VehSpdLimit; /* scaling 0.4, offset 0.0, units Kmph  */
	/* ADCU_DrvCmd_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
	/* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_DrvCmd_Checksum;
	uint8_t ADCU_DrvCmd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Drv_TgtGear; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Drv_CtrlMode; /* scaling 1.0, offset 0.0, units none  */
	uint8_t ADCU_Drv_Active; /* scaling 1.0, offset 0.0, units none  */
}  can_0x114_ADCU_DriveCmd0_t;

typedef struct {
	uint16_t CDCU_EPS_StrWhlAngle; /* scaling 0.0, offset -90.0, units deg  */
	uint16_t CDCU_EPS_WhlSpd; /* scaling 0.0, offset -180.0, units deg/s  */
	uint8_t CDCU_EPS_StrTrq; /* scaling 0.1, offset -12.8, units Nm  */
	/* CDCU_StrSt_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
	/* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_StrSt_Checksum;
	uint8_t CDCU_EPS_WorkMode; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_StrSt_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_EPS_ErrLevel; /* scaling 1.0, offset 0.0, units none  */
}  can_0x215_CDCU_SteerStatus_t;
typedef  struct {
	uint16_t CDCU_MCU_MtrCurt; /* scaling 0.1, offset 0.0, units A  */
	uint16_t CDCU_MCU_MtrSpd; /* scaling 1.0, offset 0.0, units rpm  */
	uint8_t CDCU_MCU_ThrotAct; /* scaling 0.4, offset 0.0, units %  */
	uint8_t CDCU_DrvSt_Checksum; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_MCU_WorkMode; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_DrvSt_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_MCU_ErrLevel; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_MCU_RunDir; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_MCU_GearAct; /* scaling 1.0, offset 0.0, units none  */
}  can_0x217_CDCU_DriveStatus_t;
typedef  struct {
	uint16_t CDCU_Veh_LongtdnalAccSpd; /* scaling 0.0, offset -40.0, units mps2  */
	uint16_t CDCU_Veh_LongtdnalSpd; /* scaling 0.0, offset 0.0, units Kmph  */
	uint16_t CDCU_Veh_Curvture; /* scaling 0.0, offset -3.0, units 1/m  */
	/* CDCU_VehDync_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
	/* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_VehDync_Checksum;
	uint8_t CDCU_VehDync_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_Veh_RunDir; /* scaling 1.0, offset 0.0, units none  */
}  can_0x250_CDCU_VehDyncState_t;

typedef struct {
	uint16_t CDCU_Veh_LfFtWhlSpd; /* scaling 0.0, offset 0.0, units Kmph  */
	uint16_t CDCU_Veh_RtFtWhlSpd; /* scaling 0.0, offset 0.0, units Kmph  */
	/* CDCU_FtWhlSpd_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
	/* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_FtWhlSpd_Checksum;
	uint8_t CDCU_FtWhlSpd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_Veh_RtFtWhlSpdValid; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_Veh_LfFtWhlSpdValid; /* scaling 1.0, offset 0.0, units none  */
}  can_0x251_CDCU_VehFtWhlSpd_t;

typedef  struct {
	uint16_t CDCU_Veh_LfRrWhlSpd; /* scaling 0.0, offset 0.0, units Kmph  */
	uint16_t CDCU_Veh_RtRrWhlSpd; /* scaling 0.0, offset 0.0, units Kmph  */
	/* CDCU_RrWhlSpd_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
	/* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_RrWhlSpd_Checksum;
	uint8_t CDCU_RrWhlSpd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_Veh_RtRrWhlSpdValid; /* scaling 1.0, offset 0.0, units none  */
	uint8_t CDCU_Veh_LfRrWhlSpdValid; /* scaling 1.0, offset 0.0, units none  */
}  can_0x252_CDCU_VehRrWhlSpd_t;

typedef struct  {
    uint16_t ADCU_Cld_TgtStrAngle; /* scaling 0.1, offset -1000.0, units deg  */
    uint8_t ADCU_Cld_TgtThrotVal; /* scaling 0.4, offset 0.0, units %  */
    uint8_t ADCU_Cld_TgtBrkVal; /* scaling 0.4, offset 0.0, units %  */
    /* ADCU_CldDrvCmd_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
    /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldDrvCmd_Checksum;
    uint8_t ADCU_Cld_TgtGear; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldDrvCmd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld_DriveMode; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld_PrkEnable; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld_CtrlActive; /* scaling 1.0, offset 0.0, units none  */
}CldDrv_118_t; //can_0x118_ADCU_CldDrvCmd_t; 9
 typedef struct {
     /* ADCU_CldBodyCmd_Checksum: Checksum:Sum(Byte0:Byte6)^0xFF */
     /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_CldBodyCmd_Checksum;
     uint8_t ADCU_CldBodyCmd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_FogLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_BrkLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_WidthLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_RunLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_Horn_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_Buzzer_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_BackLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_TurnRLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_TurnLLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_DblFlashLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
     uint8_t ADCU_Cld_HeadLamp_Cmd; /* scaling 1.0, offset 0.0, units none  */
 } CldBoby_119_t;// can_0x119_ADCU_CldBodyCmd_t; 13
typedef struct {
    /* ADCU_CldPwrCmd_Checksum: Checksum=Sum(Byte0:Byte6)^0xFF */
    /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldPwrCmd_Checksum;
    uint8_t ADCU_CldPwrCmd_RollCnt; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld12VRCPwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld12VMCPwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldChasPwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldVehPwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld12VSC1Pwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldPA24VPwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldPA12VPwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld24VMCPwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld12VSC3Pwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld12VSC2Pwrup_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldPA24VPwrdownCnfm_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_CldPA12VPwrdownCnfm_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld24VMCPwrdownCnfm_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld12VRCPwrdownCnfm_Cmd; /* scaling 1.0, offset 0.0, units none  */
    uint8_t ADCU_Cld12VMCPwrdownCnfm_Cmd; /* scaling 1.0, offset 0.0, units none  */
} CldPower_11a_t;//  can_0x11a_ADCU_CldPowerCmd_t; 17
int pack_can_0x118_ADCU_CldDrvCmd(CldDrv_118_t *o, uint64_t *data);
int pack_can_0x119_ADCU_CldBodyCmd(CldBoby_119_t *o, uint64_t *data);
int pack_can_0x11a_ADCU_CldPowerCmd(CldPower_11a_t *o, uint64_t *data);

uint8_t checksum(uint64_t* data) ;
int pack_can_0x111_ADCU_BrakeCmd(can_0x111_ADCU_BrakeCmd_t *o, uint64_t *data);
int pack_can_0x112_ADCU_ParkCmd(can_0x112_ADCU_ParkCmd_t *o, uint64_t *data);
int pack_can_0x113_ADCU_SteerCmd(can_0x113_ADCU_SteerCmd_t *o, uint64_t *data);
int pack_can_0x114_ADCU_DriveCmd0(can_0x114_ADCU_DriveCmd0_t *o, uint64_t *data);

int unpack_can_0x215_CDCU_SteerStatus(can_0x215_CDCU_SteerStatus_t *o, uint64_t data, uint8_t dlc);
int unpack_can_0x217_CDCU_DriveStatus(can_0x217_CDCU_DriveStatus_t *o, uint64_t data, uint8_t dlc);
int unpack_can_0x250_CDCU_VehDyncState(can_0x250_CDCU_VehDyncState_t *o, uint64_t data, uint8_t dlc);
int unpack_can_0x251_CDCU_VehFtWhlSpd(can_0x251_CDCU_VehFtWhlSpd_t *o, uint64_t data, uint8_t dlc);
int unpack_can_0x252_CDCU_VehRrWhlSpd(can_0x252_CDCU_VehRrWhlSpd_t *o, uint64_t data, uint8_t dlc);

int decode_can_0x111_ADCU_Brk_TgtPress(const can_0x111_ADCU_BrakeCmd_t *o, double *out);
int encode_can_0x111_ADCU_Brk_TgtPress(can_0x111_ADCU_BrakeCmd_t *o, double in);
int decode_can_0x111_ADCU_Brk_TgtAccSpd(const can_0x111_ADCU_BrakeCmd_t *o, double *out);
int encode_can_0x111_ADCU_Brk_TgtAccSpd(can_0x111_ADCU_BrakeCmd_t *o, double in);
int decode_can_0x111_ADCU_Brk_TgtPedpos(const can_0x111_ADCU_BrakeCmd_t *o, double *out);
int encode_can_0x111_ADCU_Brk_TgtPedpos(can_0x111_ADCU_BrakeCmd_t *o, double in);
int decode_can_0x111_ADCU_BrkCmd_Checksum(const can_0x111_ADCU_BrakeCmd_t *o, uint8_t *out);
int encode_can_0x111_ADCU_BrkCmd_Checksum(can_0x111_ADCU_BrakeCmd_t *o, uint8_t in);
int decode_can_0x111_ADCU_BrkCmd_RollCnt(const can_0x111_ADCU_BrakeCmd_t *o, uint8_t *out);
int encode_can_0x111_ADCU_BrkCmd_RollCnt(can_0x111_ADCU_BrakeCmd_t *o, uint8_t in);
int decode_can_0x111_ADCU_Brk_CtrlMode(const can_0x111_ADCU_BrakeCmd_t *o, uint8_t *out);
int encode_can_0x111_ADCU_Brk_CtrlMode(can_0x111_ADCU_BrakeCmd_t *o, uint8_t in);
int decode_can_0x111_ADCU_Brk_Active(const can_0x111_ADCU_BrakeCmd_t *o, uint8_t *out);
int encode_can_0x111_ADCU_Brk_Active(can_0x111_ADCU_BrakeCmd_t *o, uint8_t in);

int decode_can_0x112_ADCU_PrkCmd_Checksum(const can_0x112_ADCU_ParkCmd_t *o, uint8_t *out);
int encode_can_0x112_ADCU_PrkCmd_Checksum(can_0x112_ADCU_ParkCmd_t *o, uint8_t in);
int decode_can_0x112_ADCU_PrkCmd_RollCnt(const can_0x112_ADCU_ParkCmd_t *o, uint8_t *out);
int encode_can_0x112_ADCU_PrkCmd_RollCnt(can_0x112_ADCU_ParkCmd_t *o, uint8_t in);
int decode_can_0x112_ADCU_Prk_Enable(const can_0x112_ADCU_ParkCmd_t *o, uint8_t *out);
int encode_can_0x112_ADCU_Prk_Enable(can_0x112_ADCU_ParkCmd_t *o, uint8_t in);
int decode_can_0x112_ADCU_Prk_Active(const can_0x112_ADCU_ParkCmd_t *o, uint8_t *out);
int encode_can_0x112_ADCU_Prk_Active(can_0x112_ADCU_ParkCmd_t *o, uint8_t in);

int decode_can_0x113_ADCU_Str_TgtAngle(const can_0x113_ADCU_SteerCmd_t *o, double *out);
int encode_can_0x113_ADCU_Str_TgtAngle(can_0x113_ADCU_SteerCmd_t *o, double in);
int decode_can_0x113_ADCU_Str_TgtCurvature(const can_0x113_ADCU_SteerCmd_t *o, double *out);
int encode_can_0x113_ADCU_Str_TgtCurvature(can_0x113_ADCU_SteerCmd_t *o, double in);
int decode_can_0x113_ADCU_Str_TgtAngleSpd(const can_0x113_ADCU_SteerCmd_t *o, double *out);
int encode_can_0x113_ADCU_Str_TgtAngleSpd(can_0x113_ADCU_SteerCmd_t *o, double in);
int decode_can_0x113_ADCU_StrCmd_Checksum(const can_0x113_ADCU_SteerCmd_t *o, uint8_t *out);
int encode_can_0x113_ADCU_StrCmd_Checksum(can_0x113_ADCU_SteerCmd_t *o, uint8_t in);
int decode_can_0x113_ADCU_StrCmd_RollCnt(const can_0x113_ADCU_SteerCmd_t *o, uint8_t *out);
int encode_can_0x113_ADCU_StrCmd_RollCnt(can_0x113_ADCU_SteerCmd_t *o, uint8_t in);
int decode_can_0x113_ADCU_Str_CtrlMode(const can_0x113_ADCU_SteerCmd_t *o, uint8_t *out);
int encode_can_0x113_ADCU_Str_CtrlMode(can_0x113_ADCU_SteerCmd_t *o, uint8_t in);
int decode_can_0x113_ADCU_Str_Active(const can_0x113_ADCU_SteerCmd_t *o, uint8_t *out);
int encode_can_0x113_ADCU_Str_Active(can_0x113_ADCU_SteerCmd_t *o, uint8_t in);

int decode_can_0x114_ADCU_Drv_TgtVehSpd0(const can_0x114_ADCU_DriveCmd0_t *o, double *out);
int encode_can_0x114_ADCU_Drv_TgtVehSpd0(can_0x114_ADCU_DriveCmd0_t *o, double in);
int decode_can_0x114_ADCU_Drv_TgtPedpos(const can_0x114_ADCU_DriveCmd0_t *o, double *out);
int encode_can_0x114_ADCU_Drv_TgtPedpos(can_0x114_ADCU_DriveCmd0_t *o, double in);
int decode_can_0x114_ADCU_Drv_TgtVehAccSpd(const can_0x114_ADCU_DriveCmd0_t *o, double *out);
int encode_can_0x114_ADCU_Drv_TgtVehAccSpd(can_0x114_ADCU_DriveCmd0_t *o, double in);
int decode_can_0x114_ADCU_Drv_VehSpdLimit(const can_0x114_ADCU_DriveCmd0_t *o, double *out);
int encode_can_0x114_ADCU_Drv_VehSpdLimit(can_0x114_ADCU_DriveCmd0_t *o, double in);
int decode_can_0x114_ADCU_DrvCmd_Checksum(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out);
int encode_can_0x114_ADCU_DrvCmd_Checksum(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in);
int decode_can_0x114_ADCU_DrvCmd_RollCnt(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out);
int encode_can_0x114_ADCU_DrvCmd_RollCnt(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in);
int decode_can_0x114_ADCU_Drv_TgtGear(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out);
int encode_can_0x114_ADCU_Drv_TgtGear(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in);
int decode_can_0x114_ADCU_Drv_CtrlMode(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out);
int encode_can_0x114_ADCU_Drv_CtrlMode(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in);
int decode_can_0x114_ADCU_Drv_Active(const can_0x114_ADCU_DriveCmd0_t *o, uint8_t *out);
int encode_can_0x114_ADCU_Drv_Active(can_0x114_ADCU_DriveCmd0_t *o, uint8_t in);


int decode_can_0x118_ADCU_Cld_TgtStrAngle(const CldDrv_118_t *o, double *out);
int encode_can_0x118_ADCU_Cld_TgtStrAngle(CldDrv_118_t *o, double in);
int decode_can_0x118_ADCU_Cld_TgtThrotVal(const CldDrv_118_t *o, double *out);
int encode_can_0x118_ADCU_Cld_TgtThrotVal(CldDrv_118_t *o, double in);
int decode_can_0x118_ADCU_Cld_TgtBrkVal(const CldDrv_118_t *o, double *out);
int encode_can_0x118_ADCU_Cld_TgtBrkVal(CldDrv_118_t *o, double in);
int decode_can_0x118_ADCU_CldDrvCmd_Checksum(const CldDrv_118_t *o, uint8_t *out);
int encode_can_0x118_ADCU_CldDrvCmd_Checksum(CldDrv_118_t *o, uint8_t in);
int decode_can_0x118_ADCU_Cld_TgtGear(const CldDrv_118_t *o, uint8_t *out);
int encode_can_0x118_ADCU_Cld_TgtGear(CldDrv_118_t *o, uint8_t in);
int decode_can_0x118_ADCU_CldDrvCmd_RollCnt(const CldDrv_118_t *o, uint8_t *out);
int encode_can_0x118_ADCU_CldDrvCmd_RollCnt(CldDrv_118_t *o, uint8_t in);
int decode_can_0x118_ADCU_Cld_DriveMode(const CldDrv_118_t *o, uint8_t *out);
int encode_can_0x118_ADCU_Cld_DriveMode(CldDrv_118_t *o, uint8_t in);
int decode_can_0x118_ADCU_Cld_PrkEnable(const CldDrv_118_t *o, uint8_t *out);
int encode_can_0x118_ADCU_Cld_PrkEnable(CldDrv_118_t *o, uint8_t in);
int decode_can_0x118_ADCU_Cld_CtrlActive(const CldDrv_118_t *o, uint8_t *out);
int encode_can_0x118_ADCU_Cld_CtrlActive(CldDrv_118_t *o, uint8_t in);


int decode_can_0x119_ADCU_CldBodyCmd_Checksum(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_CldBodyCmd_Checksum(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_CldBodyCmd_RollCnt(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_CldBodyCmd_RollCnt(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_FogLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_FogLamp_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_BrkLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_BrkLamp_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_WidthLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_WidthLamp_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_RunLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_RunLamp_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_Horn_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_Horn_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_Buzzer_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_Buzzer_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_BackLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_BackLamp_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_TurnRLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_TurnRLamp_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_TurnLLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_TurnLLamp_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_DblFlashLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_DblFlashLamp_Cmd(CldBoby_119_t *o, uint8_t in);
int decode_can_0x119_ADCU_Cld_HeadLamp_Cmd(const CldBoby_119_t *o, uint8_t *out);
int encode_can_0x119_ADCU_Cld_HeadLamp_Cmd(CldBoby_119_t *o, uint8_t in);


int decode_can_0x11a_ADCU_CldPwrCmd_Checksum(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_CldPwrCmd_Checksum(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_CldPwrCmd_RollCnt(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_CldPwrCmd_RollCnt(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld12VRCPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld12VRCPwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld12VMCPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld12VMCPwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_CldChasPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_CldChasPwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_CldVehPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_CldVehPwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld12VSC1Pwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld12VSC1Pwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_CldPA24VPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_CldPA24VPwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_CldPA12VPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_CldPA12VPwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld24VMCPwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld24VMCPwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld12VSC3Pwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld12VSC3Pwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld12VSC2Pwrup_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld12VSC2Pwrup_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_CldPA24VPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_CldPA24VPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_CldPA12VPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_CldPA12VPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld24VMCPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld24VMCPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld12VRCPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld12VRCPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in);
int decode_can_0x11a_ADCU_Cld12VMCPwrdownCnfm_Cmd(const CldPower_11a_t *o, uint8_t *out);
int encode_can_0x11a_ADCU_Cld12VMCPwrdownCnfm_Cmd(CldPower_11a_t *o, uint8_t in);


int decode_can_0x215_CDCU_EPS_StrWhlAngle(const can_0x215_CDCU_SteerStatus_t *o, double *out);
int encode_can_0x215_CDCU_EPS_StrWhlAngle(can_0x215_CDCU_SteerStatus_t *o, double in);
int decode_can_0x215_CDCU_EPS_WhlSpd(const can_0x215_CDCU_SteerStatus_t *o, double *out);
int encode_can_0x215_CDCU_EPS_WhlSpd(can_0x215_CDCU_SteerStatus_t *o, double in);
int decode_can_0x215_CDCU_EPS_StrTrq(const can_0x215_CDCU_SteerStatus_t *o, double *out);
int encode_can_0x215_CDCU_EPS_StrTrq(can_0x215_CDCU_SteerStatus_t *o, double in);
int decode_can_0x215_CDCU_StrSt_Checksum(const can_0x215_CDCU_SteerStatus_t *o, uint8_t *out);
int encode_can_0x215_CDCU_StrSt_Checksum(can_0x215_CDCU_SteerStatus_t *o, uint8_t in);
int decode_can_0x215_CDCU_EPS_WorkMode(const can_0x215_CDCU_SteerStatus_t *o, uint8_t *out);
int encode_can_0x215_CDCU_EPS_WorkMode(can_0x215_CDCU_SteerStatus_t *o, uint8_t in);
int decode_can_0x215_CDCU_StrSt_RollCnt(const can_0x215_CDCU_SteerStatus_t *o, uint8_t *out);
int encode_can_0x215_CDCU_StrSt_RollCnt(can_0x215_CDCU_SteerStatus_t *o, uint8_t in);
int decode_can_0x215_CDCU_EPS_ErrLevel(const can_0x215_CDCU_SteerStatus_t *o, uint8_t *out);
int encode_can_0x215_CDCU_EPS_ErrLevel(can_0x215_CDCU_SteerStatus_t *o, uint8_t in);


int decode_can_0x217_CDCU_MCU_MtrCurt(const can_0x217_CDCU_DriveStatus_t *o, double *out);
int encode_can_0x217_CDCU_MCU_MtrCurt(can_0x217_CDCU_DriveStatus_t *o, double in);
int decode_can_0x217_CDCU_MCU_MtrSpd(const can_0x217_CDCU_DriveStatus_t *o, uint16_t *out);
int encode_can_0x217_CDCU_MCU_MtrSpd(can_0x217_CDCU_DriveStatus_t *o, uint16_t in);
int decode_can_0x217_CDCU_MCU_ThrotAct(const can_0x217_CDCU_DriveStatus_t *o, double *out);
int encode_can_0x217_CDCU_MCU_ThrotAct(can_0x217_CDCU_DriveStatus_t *o, double in);
int decode_can_0x217_CDCU_DrvSt_Checksum(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out);
int encode_can_0x217_CDCU_DrvSt_Checksum(can_0x217_CDCU_DriveStatus_t *o, uint8_t in);
int decode_can_0x217_CDCU_MCU_WorkMode(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out);
int encode_can_0x217_CDCU_MCU_WorkMode(can_0x217_CDCU_DriveStatus_t *o, uint8_t in);
int decode_can_0x217_CDCU_DrvSt_RollCnt(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out);
int encode_can_0x217_CDCU_DrvSt_RollCnt(can_0x217_CDCU_DriveStatus_t *o, uint8_t in);
int decode_can_0x217_CDCU_MCU_ErrLevel(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out);
int encode_can_0x217_CDCU_MCU_ErrLevel(can_0x217_CDCU_DriveStatus_t *o, uint8_t in);
int decode_can_0x217_CDCU_MCU_RunDir(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out);
int encode_can_0x217_CDCU_MCU_RunDir(can_0x217_CDCU_DriveStatus_t *o, uint8_t in);
int decode_can_0x217_CDCU_MCU_GearAct(const can_0x217_CDCU_DriveStatus_t *o, uint8_t *out);
int encode_can_0x217_CDCU_MCU_GearAct(can_0x217_CDCU_DriveStatus_t *o, uint8_t in);


int decode_can_0x250_CDCU_Veh_LongtdnalAccSpd(const can_0x250_CDCU_VehDyncState_t *o, double *out);
int encode_can_0x250_CDCU_Veh_LongtdnalAccSpd(can_0x250_CDCU_VehDyncState_t *o, double in);
int decode_can_0x250_CDCU_Veh_LongtdnalSpd(const can_0x250_CDCU_VehDyncState_t *o, double *out);
int encode_can_0x250_CDCU_Veh_LongtdnalSpd(can_0x250_CDCU_VehDyncState_t *o, double in);
int decode_can_0x250_CDCU_Veh_Curvture(const can_0x250_CDCU_VehDyncState_t *o, double *out);
int encode_can_0x250_CDCU_Veh_Curvture(can_0x250_CDCU_VehDyncState_t *o, double in);
int decode_can_0x250_CDCU_VehDync_Checksum(const can_0x250_CDCU_VehDyncState_t *o, uint8_t *out);
int encode_can_0x250_CDCU_VehDync_Checksum(can_0x250_CDCU_VehDyncState_t *o, uint8_t in);
int decode_can_0x250_CDCU_VehDync_RollCnt(const can_0x250_CDCU_VehDyncState_t *o, uint8_t *out);
int encode_can_0x250_CDCU_VehDync_RollCnt(can_0x250_CDCU_VehDyncState_t *o, uint8_t in);
int decode_can_0x250_CDCU_Veh_RunDir(const can_0x250_CDCU_VehDyncState_t *o, uint8_t *out);
int encode_can_0x250_CDCU_Veh_RunDir(can_0x250_CDCU_VehDyncState_t *o, uint8_t in);


int decode_can_0x251_CDCU_Veh_LfFtWhlSpd(const can_0x251_CDCU_VehFtWhlSpd_t *o, double *out);
int encode_can_0x251_CDCU_Veh_LfFtWhlSpd(can_0x251_CDCU_VehFtWhlSpd_t *o, double in);
int decode_can_0x251_CDCU_Veh_RtFtWhlSpd(const can_0x251_CDCU_VehFtWhlSpd_t *o, double *out);
int encode_can_0x251_CDCU_Veh_RtFtWhlSpd(can_0x251_CDCU_VehFtWhlSpd_t *o, double in);
int decode_can_0x251_CDCU_FtWhlSpd_Checksum(const can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t *out);
int encode_can_0x251_CDCU_FtWhlSpd_Checksum(can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t in);
int decode_can_0x251_CDCU_FtWhlSpd_RollCnt(const can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t *out);
int encode_can_0x251_CDCU_FtWhlSpd_RollCnt(can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t in);
int decode_can_0x251_CDCU_Veh_RtFtWhlSpdValid(const can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t *out);
int encode_can_0x251_CDCU_Veh_RtFtWhlSpdValid(can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t in);
int decode_can_0x251_CDCU_Veh_LfFtWhlSpdValid(const can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t *out);
int encode_can_0x251_CDCU_Veh_LfFtWhlSpdValid(can_0x251_CDCU_VehFtWhlSpd_t *o, uint8_t in);


int decode_can_0x252_CDCU_Veh_LfRrWhlSpd(const can_0x252_CDCU_VehRrWhlSpd_t *o, double *out);
int encode_can_0x252_CDCU_Veh_LfRrWhlSpd(can_0x252_CDCU_VehRrWhlSpd_t *o, double in);
int decode_can_0x252_CDCU_Veh_RtRrWhlSpd(const can_0x252_CDCU_VehRrWhlSpd_t *o, double *out);
int encode_can_0x252_CDCU_Veh_RtRrWhlSpd(can_0x252_CDCU_VehRrWhlSpd_t *o, double in);
int decode_can_0x252_CDCU_RrWhlSpd_Checksum(const can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t *out);
int encode_can_0x252_CDCU_RrWhlSpd_Checksum(can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t in);
int decode_can_0x252_CDCU_RrWhlSpd_RollCnt(const can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t *out);
int encode_can_0x252_CDCU_RrWhlSpd_RollCnt(can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t in);
int decode_can_0x252_CDCU_Veh_RtRrWhlSpdValid(const can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t *out);
int encode_can_0x252_CDCU_Veh_RtRrWhlSpdValid(can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t in);
int decode_can_0x252_CDCU_Veh_LfRrWhlSpdValid(const can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t *out);
int encode_can_0x252_CDCU_Veh_LfRrWhlSpdValid(can_0x252_CDCU_VehRrWhlSpd_t *o, uint8_t in);

int print_can_0x215_CDCU_SteerStatus(const can_0x215_CDCU_SteerStatus_t *o, FILE *output);
int print_can_0x217_CDCU_DriveStatus(const can_0x217_CDCU_DriveStatus_t *o, FILE *output);
int print_can_0x250_CDCU_VehDyncState(const can_0x250_CDCU_VehDyncState_t *o, FILE *output);
int print_can_0x251_CDCU_VehFtWhlSpd(const can_0x251_CDCU_VehFtWhlSpd_t *o, FILE *output);
int print_can_0x252_CDCU_VehRrWhlSpd(const can_0x252_CDCU_VehRrWhlSpd_t *o, FILE *output);

#endif // YICAR_H
