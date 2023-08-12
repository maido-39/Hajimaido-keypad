# MCU name
MCU = atmega32u4

# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency in Hz. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
#
#     This will be an integer division of F_USB below, as it is sourced by
#     F_USB after it has run through any CPU prescalers. Note that this value
#     does not *change* the processor frequency - it should merely be updated to
#     reflect the processor speed set externally so that the code can use accurate
#     software delays.
F_CPU = 16000000

#
# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
ARCH = AVR8

# Input clock frequency.
#     This will define a symbol, F_USB, in all source code files equal to the
#     input clock frequency (before any prescaling is performed) in Hz. This value may
#     differ from F_CPU if prescaling is used on the latter, and is required as the
#     raw input clock is fed directly to the PLL sections of the AVR for high speed
#     clock generation for the USB and other AVR subsections. Do NOT tack on a 'UL'
#     at the end, this will be done automatically to create a 32-bit value in your
#     source code.
#
#     If no clock division is performed on the input clock inside the AVR (via the
#     CPU clock adjust registers or the clock division fuses), this will be equal to F_CPU.
F_USB = $(F_CPU)

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT


# Boot Section Size in *bytes*
OPT_DEFS += -DBOOTLOADER_SIZE=4096


# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE ?= yes	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes	# Audio control and System control(+450)
# CONSOLE_ENABLE ?= yes	# Console for debug(+400)
# COMMAND_ENABLE ?= yes    # Commands for debug and configuration
SLEEP_LED_ENABLE ?= no  # Breathing sleep LED during USB suspend
NKRO_ENABLE ?= yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE ?= no  # Enable keyboard backlight functionality
AUDIO_ENABLE ?= no
RGBLIGHT_ENABLE ?= no

# https://docs.qmk.fm/#/feature_encoders11265751245631234561234561234564516721234256
ENCODER_ENABLE = yes  # USE Encoder!
#     https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md
# ENCODER_MAP_ENABLE = yes  # replicates the normal keyswitch layer handling functionality, but with encoders

## Enable OLED

OLED_ENABLE = yes #  enable the OLED feature
OLED_DRIVER = SSD1306 # OLED type
OLED_TRANSPORT = i2c

# 펌웨어의 컴파일된 크기를 줄여야 하는 경우 가장 중요한 것은 링크 시간 최적화를 활성화하는 것
LTO_ENABLE = yes


# WPM 기능 활성화 
WPM_ENABLE = no

# The Send String API is part of QMK's macro system. It allows for sequences of keystrokes to be sent automatically.
SEND_STRING_ENABLE = yes

