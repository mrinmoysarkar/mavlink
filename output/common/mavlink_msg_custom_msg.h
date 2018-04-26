#pragma once
// MESSAGE CUSTOM_MSG PACKING

#define MAVLINK_MSG_ID_CUSTOM_MSG 370

MAVPACKED(
typedef struct __mavlink_custom_msg_t {
 float custom_var; /*< The is a custom variable*/
}) mavlink_custom_msg_t;

#define MAVLINK_MSG_ID_CUSTOM_MSG_LEN 4
#define MAVLINK_MSG_ID_CUSTOM_MSG_MIN_LEN 4
#define MAVLINK_MSG_ID_370_LEN 4
#define MAVLINK_MSG_ID_370_MIN_LEN 4

#define MAVLINK_MSG_ID_CUSTOM_MSG_CRC 85
#define MAVLINK_MSG_ID_370_CRC 85



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CUSTOM_MSG { \
    370, \
    "CUSTOM_MSG", \
    1, \
    {  { "custom_var", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_custom_msg_t, custom_var) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CUSTOM_MSG { \
    "CUSTOM_MSG", \
    1, \
    {  { "custom_var", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_custom_msg_t, custom_var) }, \
         } \
}
#endif

/**
 * @brief Pack a custom_msg message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param custom_var The is a custom variable
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_msg_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float custom_var)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_MSG_LEN];
    _mav_put_float(buf, 0, custom_var);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_MSG_LEN);
#else
    mavlink_custom_msg_t packet;
    packet.custom_var = custom_var;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_MSG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_MSG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CUSTOM_MSG_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_CRC);
}

/**
 * @brief Pack a custom_msg message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param custom_var The is a custom variable
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_msg_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float custom_var)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_MSG_LEN];
    _mav_put_float(buf, 0, custom_var);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_MSG_LEN);
#else
    mavlink_custom_msg_t packet;
    packet.custom_var = custom_var;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_MSG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_MSG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CUSTOM_MSG_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_CRC);
}

/**
 * @brief Encode a custom_msg struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param custom_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_msg_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_custom_msg_t* custom_msg)
{
    return mavlink_msg_custom_msg_pack(system_id, component_id, msg, custom_msg->custom_var);
}

/**
 * @brief Encode a custom_msg struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param custom_msg C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_msg_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_custom_msg_t* custom_msg)
{
    return mavlink_msg_custom_msg_pack_chan(system_id, component_id, chan, msg, custom_msg->custom_var);
}

/**
 * @brief Send a custom_msg message
 * @param chan MAVLink channel to send the message
 *
 * @param custom_var The is a custom variable
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_custom_msg_send(mavlink_channel_t chan, float custom_var)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_MSG_LEN];
    _mav_put_float(buf, 0, custom_var);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MSG, buf, MAVLINK_MSG_ID_CUSTOM_MSG_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_CRC);
#else
    mavlink_custom_msg_t packet;
    packet.custom_var = custom_var;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MSG, (const char *)&packet, MAVLINK_MSG_ID_CUSTOM_MSG_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_CRC);
#endif
}

/**
 * @brief Send a custom_msg message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_custom_msg_send_struct(mavlink_channel_t chan, const mavlink_custom_msg_t* custom_msg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_custom_msg_send(chan, custom_msg->custom_var);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MSG, (const char *)custom_msg, MAVLINK_MSG_ID_CUSTOM_MSG_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_CRC);
#endif
}

#if MAVLINK_MSG_ID_CUSTOM_MSG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_custom_msg_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float custom_var)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, custom_var);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MSG, buf, MAVLINK_MSG_ID_CUSTOM_MSG_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_CRC);
#else
    mavlink_custom_msg_t *packet = (mavlink_custom_msg_t *)msgbuf;
    packet->custom_var = custom_var;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_MSG, (const char *)packet, MAVLINK_MSG_ID_CUSTOM_MSG_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_LEN, MAVLINK_MSG_ID_CUSTOM_MSG_CRC);
#endif
}
#endif

#endif

// MESSAGE CUSTOM_MSG UNPACKING


/**
 * @brief Get field custom_var from custom_msg message
 *
 * @return The is a custom variable
 */
static inline float mavlink_msg_custom_msg_get_custom_var(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a custom_msg message into a struct
 *
 * @param msg The message to decode
 * @param custom_msg C-struct to decode the message contents into
 */
static inline void mavlink_msg_custom_msg_decode(const mavlink_message_t* msg, mavlink_custom_msg_t* custom_msg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    custom_msg->custom_var = mavlink_msg_custom_msg_get_custom_var(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CUSTOM_MSG_LEN? msg->len : MAVLINK_MSG_ID_CUSTOM_MSG_LEN;
        memset(custom_msg, 0, MAVLINK_MSG_ID_CUSTOM_MSG_LEN);
    memcpy(custom_msg, _MAV_PAYLOAD(msg), len);
#endif
}
