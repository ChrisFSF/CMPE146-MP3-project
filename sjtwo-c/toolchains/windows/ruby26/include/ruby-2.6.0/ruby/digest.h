/************************************************

  digest.h - header file for ruby digest modules

  $Author: nobu $
  created at: Fri May 25 08:54:56 JST 2001


  Copyright (C) 2001-2006 Akinori MUSHA

  $RoughId: digest.h,v 1.3 2001/07/13 15:38:27 knu Exp $
  $Id: digest.h 49564 2015-02-11 02:09:23Z nobu $

************************************************/

#include "ruby.h"

#define RUBY_DIGEST_API_VERSION	3

typedef int (*rb_digest_hash_init_func_t)(void *);
typedef void (*rb_digest_hash_update_func_t)(void *, unsigned char *, size_t);
typedef int (*rb_digest_hash_finish_func_t)(void *, unsigned char *);

typedef struct {
    int api_version;
    size_t digest_len;
    size_t block_len;
    size_t ctx_size;
    rb_digest_hash_init_func_t init_func;
    rb_digest_hash_update_func_t update_func;
    rb_digest_hash_finish_func_t finish_func;
} rb_digest_metadata_t;

#define DEFINE_UPDATE_FUNC_FOR_UINT(name) \
void \
rb_digest_##name##_update(void *ctx, unsigned char *ptr, size_t size) \
{ \
    const unsigned int stride = 16384; \
 \
    for (; size > stride; size -= stride, ptr += stride) { \
	name##_Update(ctx, ptr, stride); \
    } \
    if (size > 0) name##_Update(ctx, ptr, size); \
}

#define DEFINE_FINISH_FUNC_FROM_FINAL(name) \
int \
rb_digest_##name##_finish(void *ctx, unsigned char *ptr) \
{ \
    return name##_Final(ptr, ctx); \
}
