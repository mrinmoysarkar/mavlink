// MESSAGE CUSTOM_MSG support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief CUSTOM_MSG message
 *
 * This message is a custom message
 */
struct CUSTOM_MSG : mavlink::Message {
    static constexpr msgid_t MSG_ID = 370;
    static constexpr size_t LENGTH = 4;
    static constexpr size_t MIN_LENGTH = 4;
    static constexpr uint8_t CRC_EXTRA = 85;
    static constexpr auto NAME = "CUSTOM_MSG";


    float custom_var; /*< The is a custom variable */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  custom_var: " << custom_var << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << custom_var;                    // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> custom_var;                    // offset: 0
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
