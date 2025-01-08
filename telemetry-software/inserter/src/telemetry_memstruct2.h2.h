/* This file was generate by EclipseMemstructGen.py*/
#ifndef TELEMETRY_MEMSTRUCT_H_
#define TELEMETRY_MEMSTRUCT_H_

#include <vector>
#include <algorithm>
#include <array>
#include <string_view>
using namespace std::literals::string_view_literals;

#define CANFRM_EXTENDED_ID  (1<<29)
#define CANFRM_RTR          (1<<30)

#define MAX_SIG_CNT 8

#define L_ENDIAN 0
#define B_ENDIAN 1

enum DATA_TYPE
{
        TYPE_FLOATING = 0x10,
                TYPE_float,
                TYPE_double,
        TYPE_UNSIGNED = 0x20,
                TYPE_uint32_t,
                TYPE_uint16_t,
                TYPE_uint8_t,
        TYPE_SIGNED = 0x40,
                TYPE_int32_t,
                TYPE_int16_t,
                TYPE_int8_t
};

/*Board enum*/
enum{
        ID_OFFSET_DRIVER = 0x100,
        ID_OFFSET_DRIVE = 0x200,
        ID_OFFSET_BMS = 0x300L | CANFRM_EXTENDED_ID,
        ID_OFFSET_DASHBOARD = 0x400L | CANFRM_EXTENDED_ID,
        ID_OFFSET_TELEMETRIE = 0x500L | CANFRM_EXTENDED_ID,
        ID_OFFSET_VOLANT = 0x600L | CANFRM_EXTENDED_ID,
        ID_OFFSET_POWERSUPPLY = 0x700L | CANFRM_EXTENDED_ID,
        ID_OFFSET_IGNITION = 0x800L | CANFRM_EXTENDED_ID,
        ID_OFFSET_FLASHER = 0x900L | CANFRM_EXTENDED_ID,
        ID_OFFSET_MUPPET = 0x1000L | CANFRM_EXTENDED_ID,
        ID_OFFSET_TEMPLATE = 0xFFFFL | CANFRM_EXTENDED_ID,
};

/*Message enum*/
enum CAN_ID
{
/*******************************************************************/
/*      DRIVER      */
/********************************************************************/
        M_DRIVER_MOTOR_CMD = 1+ID_OFFSET_DRIVER,
        M_DRIVER_POWER_CMD,
/*******************************************************************/
/*      DRIVE      */
/********************************************************************/
        M_DRIVE_ID = ID_OFFSET_DRIVE,
        M_DRIVE_STATUS,
        M_DRIVE_BUS,
        M_DRIVE_VELOCITY,
        M_DRIVE_PHASE_CURRENT,
        M_DRIVE_BEMF = 7+ID_OFFSET_DRIVE,
        M_DRIVE_15V,
        M_DRIVE_33V_19V,
        M_DRIVE_HEATSINK_MOTOR_TEMP = 11+ID_OFFSET_DRIVE,
        M_DRIVE_DSP_TEMP,
        M_DRIVE_ODOMETER_AMPHOUR = 14+ID_OFFSET_DRIVE,
/*******************************************************************/
/*      BMS      */
/********************************************************************/
        M_BMS_STATUS = ID_OFFSET_BMS,
        M_BMS_CURRENT,
        M_BMS_VOLTAGE,
        M_BMS_CELL_VOLTAGE,
        M_BMS_TEMP,
        M_BMS_STATE,
        M_BMS_ERRORS,
        M_BMS_CAPACITY,
        M_BMS_DATA,
/*******************************************************************/
/*      DASHBOARD      */
/********************************************************************/
        M_DASHBOARD_STATUS = ID_OFFSET_DASHBOARD,
        M_DASHBOARD_CTRL,
/*******************************************************************/
/*      TELEMETRIE      */
/********************************************************************/
        M_TELEMETRIE_STATUS = ID_OFFSET_TELEMETRIE,
/*******************************************************************/
/*      VOLANT      */
/********************************************************************/
        M_VOLANT_STATUS = ID_OFFSET_VOLANT,
        M_VOLANT_CTRL,
/*******************************************************************/
/*      POWERSUPPLY      */
/********************************************************************/
        M_POWERSUPPLY_STATUS = ID_OFFSET_POWERSUPPLY,
        M_POWERSUPPLY_CAN,
        M_POWERSUPPLY_HP,
        M_POWERSUPPLY_AUX,
/*******************************************************************/
/*      IGNITION      */
/********************************************************************/
        M_IGNITION_ID = ID_OFFSET_IGNITION,
/*******************************************************************/
/*      FLASHER      */
/********************************************************************/
        M_FLASHER_TOP = ID_OFFSET_FLASHER,
        M_FLASHER_BOT,
/*******************************************************************/
/*      MUPPET      */
/********************************************************************/
        M_MUPPET_STATUS_MPPT1 = ID_OFFSET_MUPPET,
        M_MUPPET_I_MPPT1,
        M_MUPPET_U_MPPT1,
        M_MUPPET_STATUS_MPPT2,
        M_MUPPET_I_MPPT2,
        M_MUPPET_U_MPPT2,
        M_MUPPET_STATUS_MPPT3,
        M_MUPPET_I_MPPT3,
        M_MUPPET_U_MPPT3,
        M_MUPPET_STATUS_MPPT4,
        M_MUPPET_I_MPPT4,
        M_MUPPET_U_MPPT4,
/*******************************************************************/
/*      TEMPLATE      */
/********************************************************************/
        TEMPLATE_STATUS = ID_OFFSET_TEMPLATE,
};

/*Signal enum*/
enum SIGNAL_ID
{
/*******************************************************************/
/*      DRIVER      */
/********************************************************************/
        S_DRIVER_MOTOR_VELOCITY,
        S_DRIVER_MOTOR_CURRENT,
        S_DRIVER_POWER_OFFSET,
        S_DRIVER_BUS_CURRENT,
/*******************************************************************/
/*      DRIVE      */
/********************************************************************/
        S_DRIVE_SERIAL,
        S_DRIVE_ID,
        S_DRIVE_LIMIT_FLAGS,
        S_DRIVE_ERR_FLAGS,
        S_DRIVE_ACTIVE_MOTOR,
        S_DRIVE_TX_ERR_CNT,
        S_DRIVE_RX_ERR_CNT,
        S_DRIVE_BUS_VOLTAGE,
        S_DRIVE_BUS_CURRENT,
        S_DRIVE_MOTOR_VELOCITY,
        S_DRIVE_VEHICLE_VELOCITY,
        S_DRIVE_PHASE_C_CURRENT,
        S_DRIVE_PHASE_B_CURRENT,
        S_DRIVE_BEMFQ,
        S_DRIVE_BEMFD,
        S_DRIVE_15V_OFFSET,
        S_DRIVE_15V,
        S_DRIVE_1_9V,
        S_DRIVE_3_3V,
        S_DRIVE_MOTOR_TEMP,
        S_DRIVE_HEATSINK_TEMP,
        S_DRIVE_DSP_TEMP,
        S_DRIVE_ODOMETER,
        S_DRIVE_DCBUS_AMPHOUR,
/*******************************************************************/
/*      BMS      */
/********************************************************************/
        S_BMS_STATUS,
        S_BMS_OSTICK,
        S_BMS_PACK_CURRENT,
        S_BMS_PACK_VOLTAGE,
        S_BMS_SUM_VOLTAGE,
        S_BMS_AVERAGE_CELL_VOLTAGE,
        S_BMS_CELL_VOLTAGE_MAX,
        S_BMS_CELL_HIGHEST_VOLTAGE,
        S_BMS_CELL_VOLTAGE_MIN,
        S_BMS_CELL_LOWEST_VOLTAGE,
        S_BMS_HIGHEST_TEMP,
        S_BMS_LOWEST_TEMP,
        S_BMS_MASTER_TEMP,
        S_BMS_IO_STATE,
        S_BMS_SYSTEM_STATE,
        S_BMS_ERRORS_FLAGS,
        S_BMS_WARNING_FLAGS,
        S_BMS_SOC,
        S_BMS_COULOMB_SOC,
        S_BMS_AMP_H_SUM,
        S_BMS_REMAINING_ENERGY,
        S_BMS_SLAVE_COMM_WARNINGS,
        S_BMS_MASTER_POWER_UP_TIME,
/*******************************************************************/
/*      DASHBOARD      */
/********************************************************************/
        S_DASHBOARD_STATUS,
        S_DASHBOARD_OSTICK,
        S_DASHBOARD_BREAK,
        S_DASHBOARD_BUTTON,
/*******************************************************************/
/*      TELEMETRIE      */
/********************************************************************/
        S_TELEMETRIE_STATUS,
        S_TELEMETRIE_MODEM_ON,
        S_TELEMETRIE_XBEE_ON,
        S_TELEMETRIE_OSTICK,
/*******************************************************************/
/*      VOLANT      */
/********************************************************************/
        S_VOLANT_STATUS,
        S_VOLANT_OSTICK,
        S_VOLANT_OPMODE,
        S_VOLANT_BUTTON,
/*******************************************************************/
/*      POWERSUPPLY      */
/********************************************************************/
        S_POWERSUPPLY_STATUS,
        S_POWERSUPPLY_OSTICK,
        S_POWERSUPPLY_12V_CAN_COURANT,
        S_POWERSUPPLY_12V_CAN_VOLTAGE,
        S_POWERSUPPLY_12V_HP_COURANT,
        S_POWERSUPPLY_12V_HP_VOLTAGE,
        S_POWERSUPPLY_12V_AUX_COURANT,
        S_POWERSUPPLY_12V_AUX_VOLTAGE,
/*******************************************************************/
/*      IGNITION      */
/********************************************************************/
        S_IGNITION_STATUS1,
/*******************************************************************/
/*      FLASHER      */
/********************************************************************/
        S_FLASHER_1_STATUS,
        S_FLASHER_1_OSTICK,
        S_FLASHER_2_STATUS,
        S_FLASHER_2_OSTICK,
/*******************************************************************/
/*      MUPPET      */
/********************************************************************/
        S_MUPPET_FLAG_MPPT1,
        S_MUPPET_TEMP_MPPT1,
        S_MUPPET_IIN_MPPT1,
        S_MUPPET_IOUT_MPPT1,
        S_MUPPET_UIN_MPPT1,
        S_MUPPET_UOUT_MPPT1,
        S_MUPPET_FLAG_MPPT2,
        S_MUPPET_TEMP_MPPT2,
        S_MUPPET_IIN_MPPT2,
        S_MUPPET_IOUT_MPPT2,
        S_MUPPET_UIN_MPPT2,
        S_MUPPET_UOUT_MPPT2,
        S_MUPPET_FLAG_MPPT3,
        S_MUPPET_TEMP_MPPT3,
        S_MUPPET_IIN_MPPT3,
        S_MUPPET_IOUT_MPPT3,
        S_MUPPET_UIN_MPPT3,
        S_MUPPET_UOUT_MPPT3,
        S_MUPPET_FLAG_MPPT4,
        S_MUPPET_TEMP_MPPT4,
        S_MUPPET_IIN_MPPT4,
        S_MUPPET_IOUT_MPPT4,
        S_MUPPET_UIN_MPPT4,
        S_MUPPET_UOUT_MPPT4,
/*******************************************************************/
/*      TEMPLATE      */
/********************************************************************/
        S_TEMPLATE_STATUS,
        S_TEMPLATE_OSTICK,
        S_TEMPLATE_LED,

NUM_SIGNAL_IDS,};

 /*  SignalDecode struct  */
struct SignalDecode
{
        uint32_t id;
        std::string_view name;
        DATA_TYPE type;
        uint32_t byte_pos;
        uint32_t size;
        uint8_t endianness;
        float multiplier;
};

 /*  MessageDecode struct  */
struct MessageDecode
{
        uint32_t id;
        uint32_t pos;
        std::string_view name;
        uint32_t num_signals;
        SignalDecode signals[MAX_SIG_CNT];  /* Signals */
};

static constexpr std::array<std::pair<uint32_t, MessageDecode>, 47> CAN_MESSAGES 
{{
/*******************************************************************/
/*      DRIVER      */
/********************************************************************/
        {
                M_DRIVER_MOTOR_CMD, /* CAN-Identifier */
                {
                        M_DRIVER_MOTOR_CMD, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVER_MOTOR_CMD", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVER_MOTOR_VELOCITY,   /* Signal ID */
                                        "S_DRIVER_MOTOR_VELOCITY",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVER_MOTOR_CURRENT,   /* Signal ID */
                                        "S_DRIVER_MOTOR_CURRENT",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        100.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVER_POWER_CMD, /* CAN-Identifier */
                {
                        M_DRIVER_POWER_CMD, /* CAN-Identifier */
                        sizeof(uint32_t) + sizeof(float), /* DLC of Message */
                        "M_DRIVER_POWER_CMD", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVER_POWER_OFFSET,   /* Signal ID */
                                        "S_DRIVER_POWER_OFFSET",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVER_BUS_CURRENT,   /* Signal ID */
                                        "S_DRIVER_BUS_CURRENT",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(uint32_t),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        100.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      DRIVE      */
/********************************************************************/
        {
                M_DRIVE_ID, /* CAN-Identifier */
                {
                        M_DRIVE_ID, /* CAN-Identifier */
                        sizeof(uint32_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_DRIVE_ID", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_SERIAL,   /* Signal ID */
                                        "S_DRIVE_SERIAL",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_ID,   /* Signal ID */
                                        "S_DRIVE_ID",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint32_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_STATUS, /* CAN-Identifier */
                {
                        M_DRIVE_STATUS, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint16_t) + sizeof(uint16_t) + sizeof(uint8_t) + sizeof(uint8_t), /* DLC of Message */
                        "M_DRIVE_STATUS", /* Name of Message */
                        5, /* No. of Links */
                        {
                                {
                                        S_DRIVE_LIMIT_FLAGS,   /* Signal ID */
                                        "S_DRIVE_LIMIT_FLAGS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_ERR_FLAGS,   /* Signal ID */
                                        "S_DRIVE_ERR_FLAGS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_ACTIVE_MOTOR,   /* Signal ID */
                                        "S_DRIVE_ACTIVE_MOTOR",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_TX_ERR_CNT,   /* Signal ID */
                                        "S_DRIVE_TX_ERR_CNT",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint16_t) + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_RX_ERR_CNT,   /* Signal ID */
                                        "S_DRIVE_RX_ERR_CNT",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint16_t) + sizeof(uint16_t) + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_BUS, /* CAN-Identifier */
                {
                        M_DRIVE_BUS, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVE_BUS", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_BUS_VOLTAGE,   /* Signal ID */
                                        "S_DRIVE_BUS_VOLTAGE",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_BUS_CURRENT,   /* Signal ID */
                                        "S_DRIVE_BUS_CURRENT",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_VELOCITY, /* CAN-Identifier */
                {
                        M_DRIVE_VELOCITY, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVE_VELOCITY", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_MOTOR_VELOCITY,   /* Signal ID */
                                        "S_DRIVE_MOTOR_VELOCITY",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_VEHICLE_VELOCITY,   /* Signal ID */
                                        "S_DRIVE_VEHICLE_VELOCITY",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        3.6f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_PHASE_CURRENT, /* CAN-Identifier */
                {
                        M_DRIVE_PHASE_CURRENT, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVE_PHASE_CURRENT", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_PHASE_C_CURRENT,   /* Signal ID */
                                        "S_DRIVE_PHASE_C_CURRENT",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_PHASE_B_CURRENT,   /* Signal ID */
                                        "S_DRIVE_PHASE_B_CURRENT",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_BEMF, /* CAN-Identifier */
                {
                        M_DRIVE_BEMF, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVE_BEMF", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_BEMFQ,   /* Signal ID */
                                        "S_DRIVE_BEMFQ",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_BEMFD,   /* Signal ID */
                                        "S_DRIVE_BEMFD",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_15V, /* CAN-Identifier */
                {
                        M_DRIVE_15V, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVE_15V", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_15V_OFFSET,   /* Signal ID */
                                        "S_DRIVE_15V_OFFSET",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_15V,   /* Signal ID */
                                        "S_DRIVE_15V",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_33V_19V, /* CAN-Identifier */
                {
                        M_DRIVE_33V_19V, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVE_33V_19V", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_1_9V,   /* Signal ID */
                                        "S_DRIVE_1_9V",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_3_3V,   /* Signal ID */
                                        "S_DRIVE_3_3V",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_HEATSINK_MOTOR_TEMP, /* CAN-Identifier */
                {
                        M_DRIVE_HEATSINK_MOTOR_TEMP, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVE_HEATSINK_MOTOR_TEMP", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_MOTOR_TEMP,   /* Signal ID */
                                        "S_DRIVE_MOTOR_TEMP",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_HEATSINK_TEMP,   /* Signal ID */
                                        "S_DRIVE_HEATSINK_TEMP",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_DSP_TEMP, /* CAN-Identifier */
                {
                        M_DRIVE_DSP_TEMP, /* CAN-Identifier */
                        sizeof(float), /* DLC of Message */
                        "M_DRIVE_DSP_TEMP", /* Name of Message */
                        1, /* No. of Links */
                        {
                                {
                                        S_DRIVE_DSP_TEMP,   /* Signal ID */
                                        "S_DRIVE_DSP_TEMP",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DRIVE_ODOMETER_AMPHOUR, /* CAN-Identifier */
                {
                        M_DRIVE_ODOMETER_AMPHOUR, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_DRIVE_ODOMETER_AMPHOUR", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DRIVE_ODOMETER,   /* Signal ID */
                                        "S_DRIVE_ODOMETER",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DRIVE_DCBUS_AMPHOUR,   /* Signal ID */
                                        "S_DRIVE_DCBUS_AMPHOUR",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        L_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      BMS      */
/********************************************************************/
        {
                M_BMS_STATUS, /* CAN-Identifier */
                {
                        M_BMS_STATUS, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_BMS_STATUS", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_BMS_STATUS,   /* Signal ID */
                                        "S_BMS_STATUS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_OSTICK,   /* Signal ID */
                                        "S_BMS_OSTICK",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_BMS_CURRENT, /* CAN-Identifier */
                {
                        M_BMS_CURRENT, /* CAN-Identifier */
                        sizeof(int32_t), /* DLC of Message */
                        "M_BMS_CURRENT", /* Name of Message */
                        1, /* No. of Links */
                        {
                                {
                                        S_BMS_PACK_CURRENT,   /* Signal ID */
                                        "S_BMS_PACK_CURRENT",   /* Signal Name */
                                        TYPE_int32_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(int32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_BMS_VOLTAGE, /* CAN-Identifier */
                {
                        M_BMS_VOLTAGE, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint16_t) + sizeof(uint16_t), /* DLC of Message */
                        "M_BMS_VOLTAGE", /* Name of Message */
                        3, /* No. of Links */
                        {
                                {
                                        S_BMS_PACK_VOLTAGE,   /* Signal ID */
                                        "S_BMS_PACK_VOLTAGE",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.1f,   /* Multiplier */
                                },
                                {
                                        S_BMS_SUM_VOLTAGE,   /* Signal ID */
                                        "S_BMS_SUM_VOLTAGE",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.1f,   /* Multiplier */
                                },
                                {
                                        S_BMS_AVERAGE_CELL_VOLTAGE,   /* Signal ID */
                                        "S_BMS_AVERAGE_CELL_VOLTAGE",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_BMS_CELL_VOLTAGE, /* CAN-Identifier */
                {
                        M_BMS_CELL_VOLTAGE, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint8_t) + sizeof(uint16_t) + sizeof(uint8_t), /* DLC of Message */
                        "M_BMS_CELL_VOLTAGE", /* Name of Message */
                        4, /* No. of Links */
                        {
                                {
                                        S_BMS_CELL_VOLTAGE_MAX,   /* Signal ID */
                                        "S_BMS_CELL_VOLTAGE_MAX",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_CELL_HIGHEST_VOLTAGE,   /* Signal ID */
                                        "S_BMS_CELL_HIGHEST_VOLTAGE",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_CELL_VOLTAGE_MIN,   /* Signal ID */
                                        "S_BMS_CELL_VOLTAGE_MIN",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_CELL_LOWEST_VOLTAGE,   /* Signal ID */
                                        "S_BMS_CELL_LOWEST_VOLTAGE",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint8_t) + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_BMS_TEMP, /* CAN-Identifier */
                {
                        M_BMS_TEMP, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint16_t) + sizeof(uint16_t), /* DLC of Message */
                        "M_BMS_TEMP", /* Name of Message */
                        3, /* No. of Links */
                        {
                                {
                                        S_BMS_HIGHEST_TEMP,   /* Signal ID */
                                        "S_BMS_HIGHEST_TEMP",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.1f,   /* Multiplier */
                                },
                                {
                                        S_BMS_LOWEST_TEMP,   /* Signal ID */
                                        "S_BMS_LOWEST_TEMP",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.1f,   /* Multiplier */
                                },
                                {
                                        S_BMS_MASTER_TEMP,   /* Signal ID */
                                        "S_BMS_MASTER_TEMP",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.1f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_BMS_STATE, /* CAN-Identifier */
                {
                        M_BMS_STATE, /* CAN-Identifier */
                        sizeof(uint8_t) + sizeof(uint8_t), /* DLC of Message */
                        "M_BMS_STATE", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_BMS_IO_STATE,   /* Signal ID */
                                        "S_BMS_IO_STATE",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_SYSTEM_STATE,   /* Signal ID */
                                        "S_BMS_SYSTEM_STATE",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_BMS_ERRORS, /* CAN-Identifier */
                {
                        M_BMS_ERRORS, /* CAN-Identifier */
                        sizeof(uint32_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_BMS_ERRORS", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_BMS_ERRORS_FLAGS,   /* Signal ID */
                                        "S_BMS_ERRORS_FLAGS",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_WARNING_FLAGS,   /* Signal ID */
                                        "S_BMS_WARNING_FLAGS",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint32_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_BMS_CAPACITY, /* CAN-Identifier */
                {
                        M_BMS_CAPACITY, /* CAN-Identifier */
                        sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint16_t) + sizeof(uint16_t), /* DLC of Message */
                        "M_BMS_CAPACITY", /* Name of Message */
                        4, /* No. of Links */
                        {
                                {
                                        S_BMS_SOC,   /* Signal ID */
                                        "S_BMS_SOC",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_COULOMB_SOC,   /* Signal ID */
                                        "S_BMS_COULOMB_SOC",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_AMP_H_SUM,   /* Signal ID */
                                        "S_BMS_AMP_H_SUM",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint8_t) + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_REMAINING_ENERGY,   /* Signal ID */
                                        "S_BMS_REMAINING_ENERGY",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_BMS_DATA, /* CAN-Identifier */
                {
                        M_BMS_DATA, /* CAN-Identifier */
                        sizeof(uint32_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_BMS_DATA", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_BMS_SLAVE_COMM_WARNINGS,   /* Signal ID */
                                        "S_BMS_SLAVE_COMM_WARNINGS",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_BMS_MASTER_POWER_UP_TIME,   /* Signal ID */
                                        "S_BMS_MASTER_POWER_UP_TIME",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint32_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      DASHBOARD      */
/********************************************************************/
        {
                M_DASHBOARD_STATUS, /* CAN-Identifier */
                {
                        M_DASHBOARD_STATUS, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_DASHBOARD_STATUS", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DASHBOARD_STATUS,   /* Signal ID */
                                        "S_DASHBOARD_STATUS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DASHBOARD_OSTICK,   /* Signal ID */
                                        "S_DASHBOARD_OSTICK",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_DASHBOARD_CTRL, /* CAN-Identifier */
                {
                        M_DASHBOARD_CTRL, /* CAN-Identifier */
                        sizeof(uint8_t) + sizeof(uint8_t), /* DLC of Message */
                        "M_DASHBOARD_CTRL", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_DASHBOARD_BREAK,   /* Signal ID */
                                        "S_DASHBOARD_BREAK",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_DASHBOARD_BUTTON,   /* Signal ID */
                                        "S_DASHBOARD_BUTTON",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      TELEMETRIE      */
/********************************************************************/
        {
                M_TELEMETRIE_STATUS, /* CAN-Identifier */
                {
                        M_TELEMETRIE_STATUS, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint8_t) + sizeof(uint8_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_TELEMETRIE_STATUS", /* Name of Message */
                        4, /* No. of Links */
                        {
                                {
                                        S_TELEMETRIE_STATUS,   /* Signal ID */
                                        "S_TELEMETRIE_STATUS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_TELEMETRIE_MODEM_ON,   /* Signal ID */
                                        "S_TELEMETRIE_MODEM_ON",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_TELEMETRIE_XBEE_ON,   /* Signal ID */
                                        "S_TELEMETRIE_XBEE_ON",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_TELEMETRIE_OSTICK,   /* Signal ID */
                                        "S_TELEMETRIE_OSTICK",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint8_t) + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      VOLANT      */
/********************************************************************/
        {
                M_VOLANT_STATUS, /* CAN-Identifier */
                {
                        M_VOLANT_STATUS, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_VOLANT_STATUS", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_VOLANT_STATUS,   /* Signal ID */
                                        "S_VOLANT_STATUS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_VOLANT_OSTICK,   /* Signal ID */
                                        "S_VOLANT_OSTICK",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_VOLANT_CTRL, /* CAN-Identifier */
                {
                        M_VOLANT_CTRL, /* CAN-Identifier */
                        sizeof(uint8_t) + sizeof(uint16_t), /* DLC of Message */
                        "M_VOLANT_CTRL", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_VOLANT_OPMODE,   /* Signal ID */
                                        "S_VOLANT_OPMODE",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_VOLANT_BUTTON,   /* Signal ID */
                                        "S_VOLANT_BUTTON",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0 + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      POWERSUPPLY      */
/********************************************************************/
        {
                M_POWERSUPPLY_STATUS, /* CAN-Identifier */
                {
                        M_POWERSUPPLY_STATUS, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_POWERSUPPLY_STATUS", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_POWERSUPPLY_STATUS,   /* Signal ID */
                                        "S_POWERSUPPLY_STATUS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                },
                                {
                                        S_POWERSUPPLY_OSTICK,   /* Signal ID */
                                        "S_POWERSUPPLY_OSTICK",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_POWERSUPPLY_CAN, /* CAN-Identifier */
                {
                        M_POWERSUPPLY_CAN, /* CAN-Identifier */
                        sizeof(int16_t) + sizeof(int16_t), /* DLC of Message */
                        "M_POWERSUPPLY_CAN", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_POWERSUPPLY_12V_CAN_COURANT,   /* Signal ID */
                                        "S_POWERSUPPLY_12V_CAN_COURANT",   /* Signal Name */
                                        TYPE_int16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(int16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                },
                                {
                                        S_POWERSUPPLY_12V_CAN_VOLTAGE,   /* Signal ID */
                                        "S_POWERSUPPLY_12V_CAN_VOLTAGE",   /* Signal Name */
                                        TYPE_int16_t,   /* Signal Type */
                                        0 + sizeof(int16_t),   /* Byte Position */
                                        sizeof(int16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_POWERSUPPLY_HP, /* CAN-Identifier */
                {
                        M_POWERSUPPLY_HP, /* CAN-Identifier */
                        sizeof(int16_t) + sizeof(int16_t), /* DLC of Message */
                        "M_POWERSUPPLY_HP", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_POWERSUPPLY_12V_HP_COURANT,   /* Signal ID */
                                        "S_POWERSUPPLY_12V_HP_COURANT",   /* Signal Name */
                                        TYPE_int16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(int16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                },
                                {
                                        S_POWERSUPPLY_12V_HP_VOLTAGE,   /* Signal ID */
                                        "S_POWERSUPPLY_12V_HP_VOLTAGE",   /* Signal Name */
                                        TYPE_int16_t,   /* Signal Type */
                                        0 + sizeof(int16_t),   /* Byte Position */
                                        sizeof(int16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_POWERSUPPLY_AUX, /* CAN-Identifier */
                {
                        M_POWERSUPPLY_AUX, /* CAN-Identifier */
                        sizeof(int16_t) + sizeof(int16_t), /* DLC of Message */
                        "M_POWERSUPPLY_AUX", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_POWERSUPPLY_12V_AUX_COURANT,   /* Signal ID */
                                        "S_POWERSUPPLY_12V_AUX_COURANT",   /* Signal Name */
                                        TYPE_int16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(int16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                },
                                {
                                        S_POWERSUPPLY_12V_AUX_VOLTAGE,   /* Signal ID */
                                        "S_POWERSUPPLY_12V_AUX_VOLTAGE",   /* Signal Name */
                                        TYPE_int16_t,   /* Signal Type */
                                        0 + sizeof(int16_t),   /* Byte Position */
                                        sizeof(int16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        0.001f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      IGNITION      */
/********************************************************************/
        {
                M_IGNITION_ID, /* CAN-Identifier */
                {
                        M_IGNITION_ID, /* CAN-Identifier */
                        sizeof(uint8_t), /* DLC of Message */
                        "M_IGNITION_ID", /* Name of Message */
                        1, /* No. of Links */
                        {
                                {
                                        S_IGNITION_STATUS1,   /* Signal ID */
                                        "S_IGNITION_STATUS1",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      FLASHER      */
/********************************************************************/
        {
                M_FLASHER_TOP, /* CAN-Identifier */
                {
                        M_FLASHER_TOP, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_FLASHER_TOP", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_FLASHER_1_STATUS,   /* Signal ID */
                                        "S_FLASHER_1_STATUS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_FLASHER_1_OSTICK,   /* Signal ID */
                                        "S_FLASHER_1_OSTICK",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_FLASHER_BOT, /* CAN-Identifier */
                {
                        M_FLASHER_BOT, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint32_t), /* DLC of Message */
                        "M_FLASHER_BOT", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_FLASHER_2_STATUS,   /* Signal ID */
                                        "S_FLASHER_2_STATUS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_FLASHER_2_OSTICK,   /* Signal ID */
                                        "S_FLASHER_2_OSTICK",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      MUPPET      */
/********************************************************************/
        {
                M_MUPPET_STATUS_MPPT1, /* CAN-Identifier */
                {
                        M_MUPPET_STATUS_MPPT1, /* CAN-Identifier */
                        sizeof(uint8_t) + sizeof(uint8_t), /* DLC of Message */
                        "M_MUPPET_STATUS_MPPT1", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_FLAG_MPPT1,   /* Signal ID */
                                        "S_MUPPET_FLAG_MPPT1",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_TEMP_MPPT1,   /* Signal ID */
                                        "S_MUPPET_TEMP_MPPT1",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_I_MPPT1, /* CAN-Identifier */
                {
                        M_MUPPET_I_MPPT1, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_MUPPET_I_MPPT1", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_IIN_MPPT1,   /* Signal ID */
                                        "S_MUPPET_IIN_MPPT1",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_IOUT_MPPT1,   /* Signal ID */
                                        "S_MUPPET_IOUT_MPPT1",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_U_MPPT1, /* CAN-Identifier */
                {
                        M_MUPPET_U_MPPT1, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_MUPPET_U_MPPT1", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_UIN_MPPT1,   /* Signal ID */
                                        "S_MUPPET_UIN_MPPT1",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_UOUT_MPPT1,   /* Signal ID */
                                        "S_MUPPET_UOUT_MPPT1",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_STATUS_MPPT2, /* CAN-Identifier */
                {
                        M_MUPPET_STATUS_MPPT2, /* CAN-Identifier */
                        sizeof(uint8_t) + sizeof(uint8_t), /* DLC of Message */
                        "M_MUPPET_STATUS_MPPT2", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_FLAG_MPPT2,   /* Signal ID */
                                        "S_MUPPET_FLAG_MPPT2",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_TEMP_MPPT2,   /* Signal ID */
                                        "S_MUPPET_TEMP_MPPT2",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_I_MPPT2, /* CAN-Identifier */
                {
                        M_MUPPET_I_MPPT2, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_MUPPET_I_MPPT2", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_IIN_MPPT2,   /* Signal ID */
                                        "S_MUPPET_IIN_MPPT2",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_IOUT_MPPT2,   /* Signal ID */
                                        "S_MUPPET_IOUT_MPPT2",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_U_MPPT2, /* CAN-Identifier */
                {
                        M_MUPPET_U_MPPT2, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_MUPPET_U_MPPT2", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_UIN_MPPT2,   /* Signal ID */
                                        "S_MUPPET_UIN_MPPT2",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_UOUT_MPPT2,   /* Signal ID */
                                        "S_MUPPET_UOUT_MPPT2",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_STATUS_MPPT3, /* CAN-Identifier */
                {
                        M_MUPPET_STATUS_MPPT3, /* CAN-Identifier */
                        sizeof(uint8_t) + sizeof(uint8_t), /* DLC of Message */
                        "M_MUPPET_STATUS_MPPT3", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_FLAG_MPPT3,   /* Signal ID */
                                        "S_MUPPET_FLAG_MPPT3",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_TEMP_MPPT3,   /* Signal ID */
                                        "S_MUPPET_TEMP_MPPT3",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_I_MPPT3, /* CAN-Identifier */
                {
                        M_MUPPET_I_MPPT3, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_MUPPET_I_MPPT3", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_IIN_MPPT3,   /* Signal ID */
                                        "S_MUPPET_IIN_MPPT3",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_IOUT_MPPT3,   /* Signal ID */
                                        "S_MUPPET_IOUT_MPPT3",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_U_MPPT3, /* CAN-Identifier */
                {
                        M_MUPPET_U_MPPT3, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_MUPPET_U_MPPT3", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_UIN_MPPT3,   /* Signal ID */
                                        "S_MUPPET_UIN_MPPT3",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_UOUT_MPPT3,   /* Signal ID */
                                        "S_MUPPET_UOUT_MPPT3",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_STATUS_MPPT4, /* CAN-Identifier */
                {
                        M_MUPPET_STATUS_MPPT4, /* CAN-Identifier */
                        sizeof(uint8_t) + sizeof(uint8_t), /* DLC of Message */
                        "M_MUPPET_STATUS_MPPT4", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_FLAG_MPPT4,   /* Signal ID */
                                        "S_MUPPET_FLAG_MPPT4",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_TEMP_MPPT4,   /* Signal ID */
                                        "S_MUPPET_TEMP_MPPT4",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint8_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_I_MPPT4, /* CAN-Identifier */
                {
                        M_MUPPET_I_MPPT4, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_MUPPET_I_MPPT4", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_IIN_MPPT4,   /* Signal ID */
                                        "S_MUPPET_IIN_MPPT4",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_IOUT_MPPT4,   /* Signal ID */
                                        "S_MUPPET_IOUT_MPPT4",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
        {
                M_MUPPET_U_MPPT4, /* CAN-Identifier */
                {
                        M_MUPPET_U_MPPT4, /* CAN-Identifier */
                        sizeof(float) + sizeof(float), /* DLC of Message */
                        "M_MUPPET_U_MPPT4", /* Name of Message */
                        2, /* No. of Links */
                        {
                                {
                                        S_MUPPET_UIN_MPPT4,   /* Signal ID */
                                        "S_MUPPET_UIN_MPPT4",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_MUPPET_UOUT_MPPT4,   /* Signal ID */
                                        "S_MUPPET_UOUT_MPPT4",   /* Signal Name */
                                        TYPE_float,   /* Signal Type */
                                        0 + sizeof(float),   /* Byte Position */
                                        sizeof(float),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
/*******************************************************************/
/*      TEMPLATE      */
/********************************************************************/
        {
                TEMPLATE_STATUS, /* CAN-Identifier */
                {
                        TEMPLATE_STATUS, /* CAN-Identifier */
                        sizeof(uint16_t) + sizeof(uint32_t) + sizeof(uint8_t), /* DLC of Message */
                        "TEMPLATE_STATUS", /* Name of Message */
                        3, /* No. of Links */
                        {
                                {
                                        S_TEMPLATE_STATUS,   /* Signal ID */
                                        "S_TEMPLATE_STATUS",   /* Signal Name */
                                        TYPE_uint16_t,   /* Signal Type */
                                        0,   /* Byte Position */
                                        sizeof(uint16_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_TEMPLATE_OSTICK,   /* Signal ID */
                                        "S_TEMPLATE_OSTICK",   /* Signal Name */
                                        TYPE_uint32_t,   /* Signal Type */
                                        0 + sizeof(uint16_t),   /* Byte Position */
                                        sizeof(uint32_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                },
                                {
                                        S_TEMPLATE_LED,   /* Signal ID */
                                        "S_TEMPLATE_LED",   /* Signal Name */
                                        TYPE_uint8_t,   /* Signal Type */
                                        0 + sizeof(uint16_t) + sizeof(uint32_t),   /* Byte Position */
                                        sizeof(uint8_t),   /* sizeof */
                                        B_ENDIAN,   /* Endianness */
                                        1.0f,   /* Multiplier */
                                }
                        }
                }
        },
}};

#endif
