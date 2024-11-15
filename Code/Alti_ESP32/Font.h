#ifndef FONT_H
#define FONT_H

// ibm 8x8 font, vertical-slicing, page1
const uint8_t Font8x8_ [][8] PROGMEM = {
  {0x00, 0x06, 0x0F, 0x09, 0x0F, 0x06, 0x00, 0x00},  // 00b0 (degree)
  {0x66, 0x36, 0x18, 0x6C, 0x66, 0x00, 0x00, 0x00},  // small percent (custom)
  {0x7F, 0x09, 0x09, 0x09, 0x00, 0x00, 0x3F, 0x40},  // "FULL" in 3 custom chars
  {0x40, 0x40, 0x3F, 0x00, 0x00, 0x7F, 0x40, 0x40},  // very fudgee fix
  {0x40, 0x00, 0x7F, 0x40, 0x40, 0x40, 0x00, 0x00},  //
  {0x18, 0xBA, 0xFF, 0xFF, 0xFF, 0xBA, 0x18, 0x00},  // 0005 (uni0005)
  {0x10, 0xB8, 0xFC, 0xFF, 0xFC, 0xB8, 0x10, 0x00},  // 0006 (uni0006)
  {0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00},  // 0007 (uni0007)
  {0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF},  // 0008 (uni0008)
  {0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00},  // 0009 (uni0009)
  {0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF},  // 000a (uni000A)
  {0x70, 0xF8, 0x88, 0x88, 0xFD, 0x7F, 0x07, 0x0F},  // 000b (uni000B)
  {0x00, 0x4E, 0x5F, 0xF1, 0xF1, 0x5F, 0x4E, 0x00},  // 000c (uni000C)
  {0xC0, 0xE0, 0xFF, 0x7F, 0x05, 0x05, 0x07, 0x07},  // 000d (uni000D)
  {0xC0, 0xFF, 0x7F, 0x05, 0x05, 0x65, 0x7F, 0x3F},  // 000e (uni000E)
  {0x99, 0x5A, 0x3C, 0xE7, 0xE7, 0x3C, 0x5A, 0x99},  // 000f (uni000F)
  {0x7F, 0x3E, 0x3E, 0x1C, 0x1C, 0x08, 0x08, 0x00},  // 0010 (uni0010)
  {0x08, 0x08, 0x1C, 0x1C, 0x3E, 0x3E, 0x7F, 0x00},  // 0011 (uni0011)
  {0x00, 0x24, 0x66, 0xFF, 0xFF, 0x66, 0x24, 0x00},  // 0012 (uni0012)
  {0x00, 0x5F, 0x5F, 0x00, 0x00, 0x5F, 0x5F, 0x00},  // 0013 (uni0013)
  {0x06, 0x0F, 0x09, 0x7F, 0x7F, 0x01, 0x7F, 0x7F},  // 0014 (uni0014)
  {0x40, 0xDA, 0xBF, 0xA5, 0xFD, 0x59, 0x03, 0x02},  // 0015 (uni0015)
  {0x00, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x00},  // 0016 (uni0016)
  {0x80, 0x94, 0xB6, 0xFF, 0xFF, 0xB6, 0x94, 0x80},  // 0017 (uni0017)
  {0x00, 0x04, 0x06, 0x7F, 0x7F, 0x06, 0x04, 0x00},  // 0018 (uni0018)
  {0x00, 0x10, 0x30, 0x7F, 0x7F, 0x30, 0x10, 0x00},  // 0019 (uni0019)
  {0x08, 0x08, 0x08, 0x2A, 0x3E, 0x1C, 0x08, 0x00},  // 001a (uni001A)
  {0x08, 0x1C, 0x3E, 0x2A, 0x08, 0x08, 0x08, 0x00},  // 001b (uni001B)
  {0x3C, 0x3C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00},  // 001c (uni001C)
  {0x08, 0x1C, 0x3E, 0x08, 0x08, 0x3E, 0x1C, 0x08},  // 001d (uni001D)
  {0x30, 0x38, 0x3C, 0x3E, 0x3E, 0x3C, 0x38, 0x30},  // 001e (uni001E)
  {0x06, 0x0E, 0x1E, 0x3E, 0x3E, 0x1E, 0x0E, 0x06},  // 001f (uni001F)
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // 0020 (space)
  {0x00, 0x06, 0x5F, 0x5F, 0x06, 0x00, 0x00, 0x00},  // 0021 (exclam)
  {0x00, 0x07, 0x07, 0x00, 0x07, 0x07, 0x00, 0x00},  // 0022 (quotedbl)
  {0x14, 0x7F, 0x7F, 0x14, 0x7F, 0x7F, 0x14, 0x00},  // 0023 (numbersign)
  {0x24, 0x2E, 0x6B, 0x6B, 0x3A, 0x12, 0x00, 0x00},  // 0024 (dollar)
  {0x46, 0x66, 0x30, 0x18, 0x0C, 0x66, 0x62, 0x00},  // 0025 (percent)
  {0x30, 0x7A, 0x4F, 0x5D, 0x37, 0x7A, 0x48, 0x00},  // 0026 (ampersand)
  {0x04, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00},  // 0027 (quotesingle)
  {0x00, 0x1C, 0x3E, 0x63, 0x41, 0x00, 0x00, 0x00},  // 0028 (parenleft)
  {0x00, 0x41, 0x63, 0x3E, 0x1C, 0x00, 0x00, 0x00},  // 0029 (parenright)
  {0x08, 0x2A, 0x3E, 0x1C, 0x1C, 0x3E, 0x2A, 0x08},  // 002a (asterisk)
  {0x08, 0x08, 0x3E, 0x3E, 0x08, 0x08, 0x00, 0x00},  // 002b (plus)
  {0x00, 0x80, 0xE0, 0x60, 0x00, 0x00, 0x00, 0x00},  // 002c (comma)
  {0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00},  // 002d (hyphen)
  {0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00},  // 002e (period)
  {0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00},  // 002f (slash)
  {0x3E, 0x7F, 0x71, 0x59, 0x4D, 0x7F, 0x3E, 0x00},  // 0030 (zero)
  {0x40, 0x42, 0x7F, 0x7F, 0x40, 0x40, 0x00, 0x00},  // 0031 (one)
  {0x62, 0x73, 0x59, 0x49, 0x4F, 0x66, 0x00, 0x00},  // 0032 (two)
  {0x22, 0x63, 0x49, 0x49, 0x7F, 0x36, 0x00, 0x00},  // 0033 (three)
  {0x18, 0x1C, 0x16, 0x53, 0x7F, 0x7F, 0x50, 0x00},  // 0034 (four)
  {0x27, 0x67, 0x45, 0x45, 0x7D, 0x39, 0x00, 0x00},  // 0035 (five)
  {0x3C, 0x7E, 0x4B, 0x49, 0x79, 0x30, 0x00, 0x00},  // 0036 (six)
  {0x03, 0x03, 0x71, 0x79, 0x0F, 0x07, 0x00, 0x00},  // 0037 (seven)
  {0x36, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00, 0x00},  // 0038 (eight)
  {0x06, 0x4F, 0x49, 0x69, 0x3F, 0x1E, 0x00, 0x00},  // 0039 (nine)
  {0x00, 0x00, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00},  // 003a (colon)
  {0x00, 0x40, 0x76, 0x36, 0x00, 0x00, 0x00, 0x00},  // 003b (semicolon)
  {0x08, 0x1C, 0x36, 0x63, 0x41, 0x00, 0x00, 0x00},  // 003c (less)
  {0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x00, 0x00},  // 003d (equal)
  {0x00, 0x41, 0x63, 0x36, 0x1C, 0x08, 0x00, 0x00},  // 003e (greater)
  {0x02, 0x03, 0x51, 0x59, 0x0F, 0x06, 0x00, 0x00},  // 003f (question)
  {0x3E, 0x7F, 0x41, 0x5D, 0x5D, 0x1F, 0x1E, 0x00},  // 0040 (at)
  {0x7C, 0x7E, 0x13, 0x13, 0x7E, 0x7C, 0x00, 0x00},  // 0041 (A)
  {0x41, 0x7F, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00},  // 0042 (B)
  {0x1C, 0x3E, 0x63, 0x41, 0x41, 0x63, 0x22, 0x00},  // 0043 (C)
  {0x41, 0x7F, 0x7F, 0x41, 0x63, 0x3E, 0x1C, 0x00},  // 0044 (D)
  {0x41, 0x7F, 0x7F, 0x49, 0x5D, 0x41, 0x63, 0x00},  // 0045 (E)
  {0x41, 0x7F, 0x7F, 0x49, 0x1D, 0x01, 0x03, 0x00},  // 0046 (F)
  {0x1C, 0x3E, 0x63, 0x41, 0x51, 0x73, 0x72, 0x00},  // 0047 (G)
  {0x7F, 0x7F, 0x08, 0x08, 0x7F, 0x7F, 0x00, 0x00},  // 0048 (H)
  {0x00, 0x41, 0x7F, 0x7F, 0x41, 0x00, 0x00, 0x00},  // 0049 (I)
  {0x30, 0x70, 0x40, 0x41, 0x7F, 0x3F, 0x01, 0x00},  // 004a (J)
  {0x41, 0x7F, 0x7F, 0x08, 0x1C, 0x77, 0x63, 0x00},  // 004b (K)
  {0x41, 0x7F, 0x7F, 0x41, 0x40, 0x60, 0x70, 0x00},  // 004c (L)
  {0x7F, 0x7F, 0x0E, 0x1C, 0x0E, 0x7F, 0x7F, 0x00},  // 004d (M)
  {0x7F, 0x7F, 0x06, 0x0C, 0x18, 0x7F, 0x7F, 0x00},  // 004e (N)
  {0x1C, 0x3E, 0x63, 0x41, 0x63, 0x3E, 0x1C, 0x00},  // 004f (O)
  {0x41, 0x7F, 0x7F, 0x49, 0x09, 0x0F, 0x06, 0x00},  // 0050 (P)
  {0x1E, 0x3F, 0x21, 0x71, 0x7F, 0x5E, 0x00, 0x00},  // 0051 (Q)
  {0x41, 0x7F, 0x7F, 0x09, 0x19, 0x7F, 0x66, 0x00},  // 0052 (R)
  {0x26, 0x6F, 0x4D, 0x59, 0x73, 0x32, 0x00, 0x00},  // 0053 (S)
  {0x03, 0x41, 0x7F, 0x7F, 0x41, 0x03, 0x00, 0x00},  // 0054 (T)
  {0x7F, 0x7F, 0x40, 0x40, 0x7F, 0x7F, 0x00, 0x00},  // 0055 (U)
  {0x1F, 0x3F, 0x60, 0x60, 0x3F, 0x1F, 0x00, 0x00},  // 0056 (V)
  {0x7F, 0x7F, 0x30, 0x18, 0x30, 0x7F, 0x7F, 0x00},  // 0057 (W)
  {0x43, 0x67, 0x3C, 0x18, 0x3C, 0x67, 0x43, 0x00},  // 0058 (X)
  {0x07, 0x4F, 0x78, 0x78, 0x4F, 0x07, 0x00, 0x00},  // 0059 (Y)
  {0x47, 0x63, 0x71, 0x59, 0x4D, 0x67, 0x73, 0x00},  // 005a (Z)
  {0x00, 0x7F, 0x7F, 0x41, 0x41, 0x00, 0x00, 0x00},  // 005b (bracketleft)
  {0x01, 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x00},  // 005c (backslash)
  {0x00, 0x41, 0x41, 0x7F, 0x7F, 0x00, 0x00, 0x00},  // 005d (bracketright)
  {0x08, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x08, 0x00},  // 005e (asciicircum)
  {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},  // 005f (underscore)
  {0x00, 0x00, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00},  // 0060 (grave)
  {0x20, 0x74, 0x54, 0x54, 0x3C, 0x78, 0x40, 0x00},  // 0061 (a)
  {0x41, 0x7F, 0x3F, 0x48, 0x48, 0x78, 0x30, 0x00},  // 0062 (b)
  {0x38, 0x7C, 0x44, 0x44, 0x6C, 0x28, 0x00, 0x00},  // 0063 (c)
  {0x30, 0x78, 0x48, 0x49, 0x3F, 0x7F, 0x40, 0x00},  // 0064 (d)
  {0x38, 0x7C, 0x54, 0x54, 0x5C, 0x18, 0x00, 0x00},  // 0065 (e)
  {0x48, 0x7E, 0x7F, 0x49, 0x03, 0x02, 0x00, 0x00},  // 0066 (f)
  {0x98, 0xBC, 0xA4, 0xA4, 0xF8, 0x7C, 0x04, 0x00},  // 0067 (g)
  {0x41, 0x7F, 0x7F, 0x08, 0x04, 0x7C, 0x78, 0x00},  // 0068 (h)
  {0x00, 0x44, 0x7D, 0x7D, 0x40, 0x00, 0x00, 0x00},  // 0069 (i)
  {0x60, 0xE0, 0x80, 0x80, 0xFD, 0x7D, 0x00, 0x00},  // 006a (j)
  {0x41, 0x7F, 0x7F, 0x10, 0x38, 0x6C, 0x44, 0x00},  // 006b (k)
  {0x00, 0x41, 0x7F, 0x7F, 0x40, 0x00, 0x00, 0x00},  // 006c (l)
  {0x7C, 0x7C, 0x18, 0x38, 0x1C, 0x7C, 0x78, 0x00},  // 006d (m)
  {0x7C, 0x7C, 0x04, 0x04, 0x7C, 0x78, 0x00, 0x00},  // 006e (n)
  {0x38, 0x7C, 0x44, 0x44, 0x7C, 0x38, 0x00, 0x00},  // 006f (o)
  {0x84, 0xFC, 0xF8, 0xA4, 0x24, 0x3C, 0x18, 0x00},  // 0070 (p)
  {0x18, 0x3C, 0x24, 0xA4, 0xF8, 0xFC, 0x84, 0x00},  // 0071 (q)
  {0x44, 0x7C, 0x78, 0x4C, 0x04, 0x1C, 0x18, 0x00},  // 0072 (r)
  {0x48, 0x5C, 0x54, 0x54, 0x74, 0x24, 0x00, 0x00},  // 0073 (s)
  {0x00, 0x04, 0x3E, 0x7F, 0x44, 0x24, 0x00, 0x00},  // 0074 (t)
  {0x3C, 0x7C, 0x40, 0x40, 0x3C, 0x7C, 0x40, 0x00},  // 0075 (u)
  {0x1C, 0x3C, 0x60, 0x60, 0x3C, 0x1C, 0x00, 0x00},  // 0076 (v)
  {0x3C, 0x7C, 0x70, 0x38, 0x70, 0x7C, 0x3C, 0x00},  // 0077 (w)
  {0x44, 0x6C, 0x38, 0x10, 0x38, 0x6C, 0x44, 0x00},  // 0078 (x)
  {0x9C, 0xBC, 0xA0, 0xA0, 0xFC, 0x7C, 0x00, 0x00},  // 0079 (y)
  {0x4C, 0x64, 0x74, 0x5C, 0x4C, 0x64, 0x00, 0x00},  // 007a (z)
  {0x08, 0x08, 0x3E, 0x77, 0x41, 0x41, 0x00, 0x00},  // 007b (braceleft)
  {0x00, 0x00, 0x00, 0x77, 0x77, 0x00, 0x00, 0x00},  // 007c (bar)
  {0x41, 0x41, 0x77, 0x3E, 0x08, 0x08, 0x00, 0x00},  // 007d (braceright)
  {0x02, 0x03, 0x01, 0x03, 0x02, 0x03, 0x01, 0x00},  // 007e (asciitilde)
  {0x70, 0x78, 0x4C, 0x46, 0x4C, 0x78, 0x70, 0x00},  // 007f (uni007F)
};

#endif
