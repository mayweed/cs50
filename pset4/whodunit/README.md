# Questions

## What's `stdint.h`?
The <stdint.h> header declares sets of integer types having
specified widths, and defines corresponding sets of macros. It
also defines macros that specify limits of integer types
corresponding to types defined in other standard headers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?
It creates exact fixed-sized integers. It enhances the portability
of a program: when used, the type sizes are no more implementation-defined. A
int8_t will always be 8 bits whatever the implementation is.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
BYTE is 8 bits, DWORD and LONG are 32 bits and WORD is 16 bits.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."
The first two bytes contain bfType: 0x42 in decimal, 0x4D in hexadecimal, BM in ASCII

## What's the difference between `bfSize` and `biSize`?
bfSize is the the size of the BMP file in bytes, whereas biSize is the size of BITMAPINFOHEADER.

## What does it mean if `biHeight` is negative?

For uncompressed RGB bitmaps, if biHeight is positive, the bitmap is
a bottom-up DIB with the origin at the lower left corner. If biHeight is
negative, the bitmap is a top-down DIB with the origin at the upper leftcorner.
For compressed formats, biHeight must be positive, regardless of
image orientation.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

It yields NULL if the prog can't create/open the outfile.

## Why is the third argument to `fread` always `1` in our code?

On  success,fread() returns the number of items read or written.
This number equals the number of bytes transferred only when size is 1

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO

## What does `fseek` do?

The  fseek() function sets the file position indicator for a stream
(pass as a pointer to the function). The new position, measured in bytes,
is obtained by adding offset bytes to the position specified  by
whence, the last argument of fseek(). It's like a cursor: you got a
stream, a first position and a offset to indicate the new position
in the file the program should use.

## What is `SEEK_CUR`?

SEEK_CUR is a predefined position indicator of fseek(). It is
relative to the current position indicator.

## Whodunit?
It was Professor Plum with the candlestick in the library.

