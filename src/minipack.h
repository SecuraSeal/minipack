#ifndef _minipack_h
#define _minipack_h

#include <stdio.h>
#include <stddef.h>
#include <inttypes.h>
#include <stdbool.h>

#define MSGPACK_VERSION_MAJOR    5
#define MSGPACK_VERSION_MINOR    7


//==============================================================================
//
// General
//
//==============================================================================

size_t minipack_sizeof_elem_and_data(void *ptr);


//==============================================================================
//
// Fixnum
//
//==============================================================================

//======================================
// Positive Fixnum
//======================================

bool minipack_is_pos_fixnum(void *ptr);

uint8_t minipack_unpack_pos_fixnum(void *ptr, size_t *sz);

void minipack_pack_pos_fixnum(void *ptr, uint8_t value, size_t *sz);


//======================================
// Negative Fixnum
//======================================

bool minipack_is_neg_fixnum(void *ptr);

int8_t minipack_unpack_neg_fixnum(void *ptr, size_t *sz);

void minipack_pack_neg_fixnum(void *ptr, int8_t value, size_t *sz);



//==============================================================================
//
// Unsigned Integers
//
//==============================================================================

//======================================
// Unsigned Int
//======================================

size_t minipack_sizeof_uint(uint64_t value);

size_t minipack_sizeof_uint_elem(void *ptr);

uint64_t minipack_unpack_uint(void *ptr, size_t *sz);

void minipack_pack_uint(void *ptr, uint64_t value, size_t *sz);

uint64_t minipack_fread_uint(FILE *file, size_t *sz);

int minipack_fwrite_uint(FILE *file, uint64_t value, size_t *sz);


//======================================
// Unsigned Int (8-bit)
//======================================

bool minipack_is_uint8(void *ptr);

uint8_t minipack_unpack_uint8(void *ptr, size_t *sz);

void minipack_pack_uint8(void *ptr, uint8_t value, size_t *sz);


//======================================
// Unsigned Int (16-bit)
//======================================

bool minipack_is_uint16(void *ptr);

uint16_t minipack_unpack_uint16(void *ptr, size_t *sz);

void minipack_pack_uint16(void *ptr, uint16_t value, size_t *sz);


//======================================
// Unsigned Int (32-bit)
//======================================

bool minipack_is_uint32(void *ptr);

uint32_t minipack_unpack_uint32(void *ptr, size_t *sz);

void minipack_pack_uint32(void *ptr, uint32_t value, size_t *sz);


//======================================
// Unsigned Int (64-bit)
//======================================

bool minipack_is_uint64(void *ptr);

uint64_t minipack_unpack_uint64(void *ptr, size_t *sz);

void minipack_pack_uint64(void *ptr, uint64_t value, size_t *sz);



//==============================================================================
//
// Signed Integers
//
//==============================================================================

//======================================
// Signed Int
//======================================

size_t minipack_sizeof_int(int64_t value);

size_t minipack_sizeof_int_elem(void *ptr);

int64_t minipack_unpack_int(void *ptr, size_t *sz);

void minipack_pack_int(void *ptr, int64_t value, size_t *sz);

int64_t minipack_fread_int(FILE *file, size_t *sz);

int minipack_fwrite_int(FILE *file, int64_t value, size_t *sz);


//======================================
// Signed Int (8-bit)
//======================================

bool minipack_is_int8(void *ptr);

int8_t minipack_unpack_int8(void *ptr, size_t *sz);

void minipack_pack_int8(void *ptr, int8_t value, size_t *sz);


//======================================
// Signed Int (16-bit)
//======================================

bool minipack_is_int16(void *ptr);

int16_t minipack_unpack_int16(void *ptr, size_t *sz);

void minipack_pack_int16(void *ptr, int16_t value, size_t *sz);


//======================================
// Signed Int (32-bit)
//======================================

bool minipack_is_int32(void *ptr);

int32_t minipack_unpack_int32(void *ptr, size_t *sz);

void minipack_pack_int32(void *ptr, int32_t value, size_t *sz);


//======================================
// Signed Int (64-bit)
//======================================

bool minipack_is_int64(void *ptr);

int64_t minipack_unpack_int64(void *ptr, size_t *sz);

void minipack_pack_int64(void *ptr, int64_t value, size_t *sz);

//==============================================================================
//
// Nil
//
//==============================================================================

//======================================
// Nil
//======================================

size_t minipack_sizeof_nil(void);

bool minipack_is_nil(void *ptr);

void minipack_pack_nil(void *ptr, size_t *sz);

void minipack_unpack_nil(void *ptr, size_t *sz);

void minipack_fread_nil(FILE *file, size_t *sz);

int minipack_fwrite_nil(FILE *file, size_t *sz);


//==============================================================================
//
// Boolean
//
//==============================================================================

//======================================
// Bool
//======================================

size_t minipack_sizeof_bool(void);

bool minipack_is_bool(void *ptr);

bool minipack_is_true(void *ptr);

bool minipack_is_false(void *ptr);

bool minipack_unpack_bool(void *ptr, size_t *sz);

void minipack_pack_bool(void *ptr, bool value, size_t *sz);

bool minipack_fread_bool(FILE *file, size_t *sz);

int minipack_fwrite_bool(FILE *file, bool value, size_t *sz);


//==============================================================================
//
// Floating-point
//
//==============================================================================

//======================================
// Float
//======================================

size_t minipack_sizeof_float(void);

bool minipack_is_float(void *ptr);

float minipack_unpack_float(void *ptr, size_t *sz);

void minipack_pack_float(void *ptr, float value, size_t *sz);

float minipack_fread_float(FILE *file, size_t *sz);

int minipack_fwrite_float(FILE *file, float value, size_t *sz);


//======================================
// Double
//======================================

size_t minipack_sizeof_double(void);

bool minipack_is_double(void *ptr);

double minipack_unpack_double(void *ptr, size_t *sz);

void minipack_pack_double(void *ptr, double value, size_t *sz);

double minipack_fread_double(FILE *file, size_t *sz);

int minipack_fwrite_double(FILE *file, double value, size_t *sz);


//==============================================================================
//
// Strings
//
//==============================================================================

//======================================
// General
//======================================

bool minipack_is_str(void *ptr);

size_t minipack_sizeof_str(uint32_t length);

size_t minipack_sizeof_str_elem(void *ptr);

uint32_t minipack_unpack_str(void *ptr, size_t *sz);

void minipack_pack_str(void *ptr, uint32_t length, size_t *sz);

uint32_t minipack_fread_str(FILE *file, size_t *sz);

int minipack_fwrite_str(FILE *file, uint32_t length, size_t *sz);


//======================================
// Fix str
//======================================

bool minipack_is_fixstr(void *ptr);

uint8_t minipack_unpack_fixstr(void *ptr, size_t *sz);

void minipack_pack_fixstr(void *ptr, uint8_t length, size_t *sz);

//======================================
// Str 8
//======================================

bool minipack_is_str8(void *ptr);

uint8_t minipack_unpack_str8(void *ptr, size_t *sz);

void minipack_pack_str8(void *ptr, uint8_t length, size_t *sz);

//======================================
// Str 16
//======================================

bool minipack_is_str16(void *ptr);

uint16_t minipack_unpack_str16(void *ptr, size_t *sz);

void minipack_pack_str16(void *ptr, uint16_t length, size_t *sz);


//======================================
// str 32
//======================================

bool minipack_is_str32(void *ptr);

uint32_t minipack_unpack_str32(void *ptr, size_t *sz);

void minipack_pack_str32(void *ptr, uint32_t length, size_t *sz);

//==============================================================================
//
// Bin
//
//==============================================================================

//======================================
// General
//======================================

bool minipack_is_bin(void *ptr);

size_t minipack_sizeof_bin(uint32_t length);

size_t minipack_sizeof_bin_elem(void *ptr);

uint32_t minipack_unpack_bin(void *ptr, size_t *sz);

void minipack_pack_bin(void *ptr, uint32_t length, size_t *sz);

//======================================
// Bin 8
//======================================

bool minipack_is_bin8(void *ptr);

uint8_t minipack_unpack_bin8(void *ptr, size_t *sz);

void minipack_pack_bin8(void *ptr, uint8_t length, size_t *sz);


//======================================
// Bin 16
//======================================

bool minipack_is_bin16(void *ptr);

uint16_t minipack_unpack_bin16(void *ptr, size_t *sz);

void minipack_pack_bin16(void *ptr, uint16_t length, size_t *sz);


//======================================
// Bin 32
//======================================

bool minipack_is_bin32(void *ptr);

uint32_t minipack_unpack_bin32(void *ptr, size_t *sz);

void minipack_pack_bin32(void *ptr, uint32_t length, size_t *sz);


//==============================================================================
//
// Array
//
//==============================================================================

//======================================
// General
//======================================

bool minipack_is_array(void *ptr);

size_t minipack_sizeof_array(uint32_t count);

size_t minipack_sizeof_array_elem(void *ptr);

uint32_t minipack_unpack_array(void *ptr, size_t *sz);

void minipack_pack_array(void *ptr, uint32_t count, size_t *sz);

uint32_t minipack_fread_array(FILE *file, size_t *sz);

int minipack_fwrite_array(FILE *file, uint32_t length, size_t *sz);


//======================================
// Fix array
//======================================

bool minipack_is_fixarray(void *ptr);

uint8_t minipack_unpack_fixarray(void *ptr, size_t *sz);

void minipack_pack_fixarray(void *ptr, uint8_t count, size_t *sz);


//======================================
// Array 16
//======================================

bool minipack_is_array16(void *ptr);

uint16_t minipack_unpack_array16(void *ptr, size_t *sz);

void minipack_pack_array16(void *ptr, uint16_t count, size_t *sz);


//======================================
// Array 32
//======================================

bool minipack_is_array32(void *ptr);

uint32_t minipack_unpack_array32(void *ptr, size_t *sz);

void minipack_pack_array32(void *ptr, uint32_t count, size_t *sz);



//==============================================================================
//
// Map
//
//==============================================================================

//======================================
// General
//======================================

bool minipack_is_map(void *ptr);

size_t minipack_sizeof_map(uint32_t count);

size_t minipack_sizeof_map_elem(void *ptr);

uint32_t minipack_unpack_map(void *ptr, size_t *sz);

void minipack_pack_map(void *ptr, uint32_t count, size_t *sz);

uint32_t minipack_fread_map(FILE *file, size_t *sz);

int minipack_fwrite_map(FILE *file, uint32_t length, size_t *sz);


//======================================
// Fix map
//======================================

bool minipack_is_fixmap(void *ptr);

uint8_t minipack_unpack_fixmap(void *ptr, size_t *sz);

void minipack_pack_fixmap(void *ptr, uint8_t count, size_t *sz);


//======================================
// Map 16
//======================================

bool minipack_is_map16(void *ptr);

uint16_t minipack_unpack_map16(void *ptr, size_t *sz);

void minipack_pack_map16(void *ptr, uint16_t count, size_t *sz);


//======================================
// Map 32
//======================================

bool minipack_is_map32(void *ptr);

uint32_t minipack_unpack_map32(void *ptr, size_t *sz);

void minipack_pack_map32(void *ptr, uint32_t count, size_t *sz);



#endif
