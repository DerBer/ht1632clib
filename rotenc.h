//
// Read rotary encoder.
//

#ifndef ROTENC_H
#define ROTENC_H

typedef void (*rotenc_callback_t)(int value);

int rotenc_init(int pinEnc0, int pinEnc1, int pinBtn, rotenc_callback_t callback);
int rotenc_wait();

#endif
