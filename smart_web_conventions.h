#pragma once
#include <stdint.h>

namespace SmartWeb
{
    enum E_MessageFormat : uint8_t
    {
        MF_FORMAT_0,
        MF_LONG,
    };

    enum E_ProgramType : uint8_t
    {
        PT_CAN_PROGRAM_TYPE_UNDEFINED = 0,
        PT_PROGRAM = 1,
        PT_OUTDOOR_SENSOR = 2,
        PT_CONSUMER = 3,
        PT_CASCADE_MANAGER = 4,
        PT_ROOM_DEVICE = 5,
        PT_TEMPERATURE_SOURCE = 6,
        PT_HEAT_ACCUMULATOR = 7,
        PT_EXTENDED_CONTROLLER = 8,
        PT_EXTENSION_CONTROLLER = 9,
        PT_MONITORING_DEVICE = 10,
        PT_CONTROLLER = 11,
        PT_CIRCUIT = 12,
        PT_SCHEDULE = 13,
        PT_HEATING_CIRCUIT = 14,
        PT_DIRECT_CIRCUIT = 15,
        PT_DHW = 16,
        PT_FLOW_THROUGH_DHW = 17,
        PT_TEMPERATURE_GENERATOR = 18,
        PT_POOL = 19,
        PT_THERMOSTAT = 20,
        PT_SNOWMELT = 21,
        PT_REMOTE_CONTROL = 22,
        PT_BOILER = 23,
        PT_CHILLER = 24,
        PT_SOLAR_COLLECTOR = 25,
        PT_VENTILATION = 26,
        PT_GENERIC_RELAY = 27,
        PT_ALARM = 28,
    };

    enum E_MessageType : uint8_t
    {
        MT_MSG_REQUEST = 0,
        MT_RESERVED = 1,
        MT_MSG_RESPONSE = 2,
        MT_MSG_ERROR = 3,
    };

    namespace Controller
    {
        namespace Function
        {
            enum CANFunction
            {
                I_AM_HERE = 1,
                GET_CONTROLLER,
                GET_ACTIVE_PROGRAMS_LIST,
                ADD_NEW_PROGRAM,
                REMOVE_PROGRAM,
                GET_SYSTEM_DATE_TIME,
                SET_SYSTEM_DATE_TIME,
                GET_CONTROLLER_TYPE,
                GET_PROGRAM_VERSION,
                GET_CHANNEL_NUMBER,
                GET_OUTPUT_TYPE,
                GET_INPUT_TYPE,
                GET_CHANNEL_BINDING,
                GET_INPUT_VALUE,
                SET_OUTPUT_VALUE,
                HAS_ERROR,
                GET_CONTROLLER_MASKS,
                GET_CHANNELS_INFO,
                GET_OUTPUT_VALUE,
                TIME_MASTER_IS_ACTIVE,
                JOURNAL,
                GET_VARIABLE,
                SET_VARIABLE,
                GET_RELAY_MAPPING,
                SET_RELAY_MAPPING,
                RESET_TO_DEFAULTS,
                RESET_PROGRAMS,

                //add new functions here
            };
        }

        namespace Parameters
        {
            enum enumParameterID
            {
                SENSOR = 1,
                OUTPUT,
                USED_SENSORS_MASK,
                USED_RELAYS_MASK,
                TITLE,
                CONTROLLER_TYPE,
                REVISION,
                INPUTS_MASK,
                OUTPUTS_MASK,
                ANALOG_INPUT_SIGNAL_TYPE,
                ANALOG_INPUT_SENSOR_TYPE,
                ANALOG_INPUT_POINT_X1,
                ANALOG_INPUT_POINT_Y1,
                ANALOG_INPUT_POINT_X2,
                ANALOG_INPUT_POINT_Y2,
                ANALOG_OUTPUT_PROFIL,
                ANALOG_OUTPUT_SIGNAL_FORM,
                ANALOG_OUTPUT_SIGNAL_AUS,
                ANALOG_OUTPUT_SIGNAL_EIN,
                ANALOG_OUTPUT_SIGNAL_MAX,
                ANALOG_OUTPUT_DREHZAH_BEI_EIN,
                ANALOG_OUTPUT_TYP,
                NETWORK_INPUT_CONFIG,
                NETWORK_VAR_INPUT_CONFIG,
                NETWORK_OUTPUT_CONFIG,
                VARIABLE_TYPE,
                OUTPUT_TO_VARIABLE_MAPPING,
                DATE,
                TIME,
                SENSOR_CALIBRATION,
                DISCRETTE_OUTPUT_SIGNAL_FORM,

                //add new parameters here
            };
        }
    }

    namespace RemoteControl
    {
        namespace Function
        {
            enum CANFunction
            {
                GET_PARAMETER_VALUE = 1,
                SET_PARAMETER_VALUE,
                GET_PARAMETER_NAME,
                GET_PARAMETER_DESCRIPTION,
                GET_PARAMETER_MINIMUM,
                GET_PARAMETER_MAXIMUM,
                GET_PARAMETER_DEFAULT,
                GET_PARAMETER_UNIT,
            };
        }
    }

    union TCanHeader {
        uint32_t raw;
        struct
        {
            uint8_t program_type : 8,
                program_id : 8,
                function_id : 8;
            union {
                struct
                {
                    uint8_t reserve : 3,
                        exception_flag : 1,
                        response_flag : 1,
                        tra : 3;
                };

                struct
                {
                    uint8_t message_format : 3,
                        message_type : 2,
                        trash : 3;
                };
            };
        } rec;
    };
}
