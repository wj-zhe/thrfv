# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
NKRO_ENABLE = no           # N-Key Rollover

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

ENCODER_ENABLE = yes

BACKLIGHT_ENABLE = no      # keyboard RGB per key backlight
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	BACKLIGHT_DRIVER = software
endif

RGBLIGHT_ENABLE = no       # keyboard RGB underglow
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	RGB_DRIVER = WS2812
	RGBLIGHT_SUPPORTED = yes
	RGB_MATRIX_DRIVER = WS2812
	RGB_MATRIX_SUPPORTED = yes
endif

TAP_DANCE_ENABLE = yes      # Enable Tap-Dance feature
COMBO_ENABLE = yes          # Enable COMBO feature

MOUSEKEY_ENABLE = yes


# Debug Options
CONSOLE_ENABLE = no
