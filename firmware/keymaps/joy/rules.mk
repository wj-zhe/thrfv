# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
NKRO_ENABLE = yes           # Enable N-Key Rollover

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

ENCODER_ENABLE = yes

POINTING_DEVICE_ENABLE = yes
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	POINTING_DEVICE_DRIVER = analog_joystick
	THUMBSTICK_ENABLE = yes
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = analog_joystick
	OPT_DEFS += -DTHUMBSTICK_ENABLE
	# SRC += analog.c
	SRC += thumbstick.c

	MOUSEKEY_ENABLE = yes
endif

# idea borrowed from here:
#   https://git.alt-tek.com/nathan/qmk-fw/commit/4057d44989e2ee83ca3b171bdb1a29bc9f3ae0cd#:~:text=ifeq%20(%24(strip%20%24(THUMBSTICK_ENABLE,endif

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no
# RGB_MATRIX_DRIVER = WS2812
# RGBLIGHT_SUPPORTED = yes
# RGB_MATRIX_SUPPORTED = yes

TAP_DANCE_ENABLE = yes      # Enable Tap-Dance feature
COMBO_ENABLE = yes          # Enable COMBO feature

# Debug Options
CONSOLE_ENABLE = no
