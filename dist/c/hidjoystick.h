// Autogenerated C header file for HID Joystick
#ifndef _JACDAC_SPEC_HID_JOYSTICK_H
#define _JACDAC_SPEC_HID_JOYSTICK_H 1

#define JD_SERVICE_CLASS_HID_JOYSTICK  0x1a112155

/**
 * Constant uint8_t. Number of button report supported
 */
#define JD_HID_JOYSTICK_REG_BUTTON_COUNT 0x180

/**
 * Constant uint32_t. A bitset that indicates which button is analog.
 */
#define JD_HID_JOYSTICK_REG_BUTTONS_ANALOG 0x181

/**
 * Constant uint8_t. Number of analog input supported
 */
#define JD_HID_JOYSTICK_REG_AXIS_COUNT 0x182

/**
 * Sets the up/down button state, one byte per button, supports analog buttons. For digital buttons, use `0` for released, `1` for pressed.
 */
#define JD_HID_JOYSTICK_CMD_SET_BUTTONS 0x80
typedef struct jd_hid_joystick_set_buttons {
    uint8_t pressure[0];  // ratio u0.8
} jd_hid_joystick_set_buttons_t;


/**
 * Sets the state of analog inputs.
 */
#define JD_HID_JOYSTICK_CMD_SET_AXIS 0x81
typedef struct jd_hid_joystick_set_axis {
    int16_t position[0];  // ratio i1.15
} jd_hid_joystick_set_axis_t;


#endif