/*------------------------------------------------------------------------------
UniKey - Vietnamese Keyboard for Windows
Copyright (C) 1998-2001 Pham Kim Long
Contact: longp@cslab.felk.cvut.cz

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
--------------------------------------------------------------------------------*/
#ifndef __KEY_CONS_H
#define __KEY_CONS_H

// Character sets
#define TOTAL_CHARSET 10
#define TCVN3_CHARSET		0
#define UNICODE_CHARSET		0x101
#define VIQR_CHARSET		0x100
//#define VNI_CHARSET			0x102   // Every 2-byte charset must be placed after VNI_CHARSET


// Input methods
#define INPUT_METHODS 2		// Currently supports 2 input methods, TELEX & VNI
#define TELEX_INPUT 0
#define VNI_INPUT	1



/*
Explanation of ecoding in DT table:
In DT:
- Bits 0-4: index of vowels
- Bits 5-8: index of macro keys (e.g. TELEX: w, W, [, ]
- Bits 9-13: index of double characters (including: a, d, e, o, a^, dd, e^, o^, a(, u+...)
- Bits 14-17: index of tone marks
- Bits 18-21: determines the index of the tone associated with a character, e.g tone_index(a') = 1.
- Bit 22: is set if this character is used to type a breve. (in texlex, they are w, W)
- Bit 24: soft separator. Soft separators don't cause the buffer to be cleared.
- Bit 25: separator flag. Buffer must be cleared when separator character is encountered.
- Bit 26-28: index of VNI double marks ('6', '7', '8', '9')
*/

// Macros for entries in DT table
#define ATTR_VOWEL_INDEX(x) (x & 0x1F)
#define ATTR_IS_BREVE(x) ((x >> 22) & 0x1)
#define ATTR_TONE_INDEX(x) ((x >> 14) & 0xF)
#define ATTR_IS_SOFT_SEPARATOR(x) ((x >> 24) & 0x1)
#define ATTR_DBCHAR_INDEX(x) ((x >> 9) & 0x1F)
#define ATTR_MACRO_INDEX(x) ((x >> 5) & 0xF)
#define ATTR_IS_SEPARATOR(x) (x & 0x2000000)
#define ATTR_VNI_DOUBLE_INDEX(x) ((x >> 26) & 0x7)
#define ATTR_CURRENT_TONE(x) ((x >> 18) & 0xF)

#endif