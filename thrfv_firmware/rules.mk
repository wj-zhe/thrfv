# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Bootmagic Lite
NKRO_ENABLE = no            # N-Key Rollover

MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control

CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

BACKLIGHT_ENABLE = no       # keyboard backlight functionality
RGBLIGHT_ENABLE = no        # keyboard RGB underglow

ENCODER_ENABLE = no         # encoder
OLED_ENABLE = no            # oled

UNICODE_ENABLE = no         # Unicode
AUDIO_ENABLE = no           # Audio output

SPLIT_KEYBOARD = yes        # Use shared split_common code

VIA_ENABLE = no             # Disable VIA support to avoid key setting conflicts

