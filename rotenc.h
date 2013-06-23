//
// Read rotary encoder.
//

#ifndef ROTENC_H
#define ROTENC_H

typedef void (*rotenc_callback_t)(int value);

int rotenc_init(int pin0, int pin1, rotenc_callback_t callback);

#endif
