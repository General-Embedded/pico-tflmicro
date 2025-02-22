// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ------- //
// mic_i2s //
// ------- //

#define mic_i2s_wrap_target 0
#define mic_i2s_wrap 11

#define mic_i2s_offset_entry_point 8u

static const uint16_t mic_i2s_program_instructions[] = {
            //     .wrap_target
    0x4801, //  0: in     pins, 1         side 1     
    0x0040, //  1: jmp    x--, 0          side 0     
    0xe82d, //  2: set    x, 13           side 1     
    0xa042, //  3: nop                    side 0     
    0x0843, //  4: jmp    x--, 3          side 1     
    0xf83f, //  5: set    x, 31           side 3     
    0xb042, //  6: nop                    side 2     
    0x1846, //  7: jmp    x--, 6          side 3     
    0xb842, //  8: nop                    side 3     
    0xa042, //  9: nop                    side 0     
    0xa842, // 10: nop                    side 1     
    0xe02f, // 11: set    x, 15           side 0     
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program mic_i2s_program = {
    .instructions = mic_i2s_program_instructions,
    .length = 12,
    .origin = -1,
};

static inline pio_sm_config mic_i2s_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + mic_i2s_wrap_target, offset + mic_i2s_wrap);
    sm_config_set_sideset(&c, 2, false, false);
    return c;
}

void mic_i2s_program_init(PIO pio, uint sm, uint offset, uint8_t LRclk_pin, uint8_t clock_pin, uint data_pin) {
	pio_sm_set_consecutive_pindirs(pio, sm, data_pin, 1, false);
    pio_sm_set_consecutive_pindirs(pio, sm, clock_pin, 1, true);
	pio_sm_set_consecutive_pindirs(pio, sm, LRclk_pin, 1, true);
	pio_sm_config c = mic_i2s_program_get_default_config(offset);
	sm_config_set_in_pins(&c, data_pin);
	sm_config_set_sideset_pins(&c, clock_pin);
	sm_config_set_sideset_pins(&c, LRclk_pin);
	sm_config_set_in_shift(&c, false, true, 16);
	sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
	pio_sm_init(pio, sm, offset, &c);
	pio_sm_exec(pio, sm, pio_encode_jmp(offset + mic_i2s_offset_entry_point));
	pio_sm_set_enabled(pio, sm, true);
}

#endif

