# MCU
MCU = atmega32u4

# Bootloader
BOOTLOADER = caterina

# Encoder config
ENCODER_ENABLE = yes
# ENCODER_MAP_ENABLE = yes

# Tap-dance config
OLED_ENABLE = yes
OLED_DRIVER = ssd1306

# Backlight config
BACKLIGHT_ENABLE = no      # keyboard RGB per key backlight
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	BACKLIGHT_DRIVER = software
endif

# RGBLIGHT config
RGBLIGHT_ENABLE = no       # keyboard RGB underglow
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	RGB_DRIVER = WS2812
	RGBLIGHT_SUPPORTED = yes
	RGB_MATRIX_DRIVER = WS2812
	RGB_MATRIX_SUPPORTED = yes
endif

# Tap-dance config
TAP_DANCE_ENABLE = yes      # Enable Tap-Dance feature

# Combo config
COMBO_ENABLE = yes          # Enable COMBO feature
VPATH += keyboards/gboards

# Mousekey config
MOUSEKEY_ENABLE = yes

# Debug Options
CONSOLE_ENABLE = no
