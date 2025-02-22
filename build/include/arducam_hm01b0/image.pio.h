// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ----- //
// image //
// ----- //

#define image_wrap_target 0
#define image_wrap 3

static const uint16_t image_program_instructions[] = {
            //     .wrap_target
    0x20a9, //  0: wait   1 pin, 9                   
    0x20a8, //  1: wait   1 pin, 8                   
    0x4001, //  2: in     pins, 1                    
    0x2028, //  3: wait   0 pin, 8                   
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program image_program = {
    .instructions = image_program_instructions,
    .length = 4,
    .origin = -1,
};

static inline pio_sm_config image_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + image_wrap_target, offset + image_wrap);
    return c;
}

void image_program_init(PIO pio, uint sm, uint offset, uint pin_base) {
	pio_sm_set_consecutive_pindirs(pio, sm, pin_base, 1, false);
	pio_sm_config c = image_program_get_default_config(offset);
	sm_config_set_in_pins(&c, pin_base);
	sm_config_set_in_shift(&c, false, true, 8);
	sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
	pio_sm_init(pio, sm, offset, &c);
	//pio_sm_set_enabled(pio, sm, true);
}

#endif

