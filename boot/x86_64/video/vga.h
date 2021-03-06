/**
 * Copyright [2020] [Project Vault Team]
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * you may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef VGA_H
#define VGA_H

#include "misc/types/types.h"

// VGA mode screen parameters (default)
#define VGA_ROW_COUNT 					25
#define VGA_COLUMN_COUNT 				85

// VGA register and memory addresses
#define VGA_MEM_ADDR					0xb8000
#define VGA_CRTC_ADDR					0x3d4
#define VGA_CRTC_DATA_ADDR				0x3d5
#define VGA_GRAPH_ADDR					0x3ce
#define VGA_GRAPH_DATA_ADDR				0x3cf

// VGA indexes
#define VGA_CRTC_CURSOR_START			0x0A
#define VGA_CRTC_CURSOR_END				0x0B

// Colors
#define VGA_COLOR_BLACK   				0x0
#define VGA_COLOR_BLUE    				0x1
#define VGA_COLOR_GREEN   				0x2
#define VGA_COLOR_CYAN   				0x3
#define VGA_COLOR_RED     				0x4
#define VGA_COLOR_MAGENTA 				0x5
#define VGA_COLOR_BROWN   				0x6
#define VGA_COLOR_WHITE   				0x7

// Print manipulation
#define VGA_SET_BG(bg)				(bg << 4)
#define VGA_SET_COLOR_PARAM(bg,fg)	(VGA_SET_BG(bg) | fg)
#define VGA_SET_COLOR(sym,param) 	((param << 8) | sym)
#define VGA_GET_SYM(block)			(block | 0xFF00)
#define VGA_GET_COLOR(block)		(block >> 8)
#define VGA_GET_BG(block)			(VGA_GET_COLOR(block) >> 4)
#define VGA_GET_FG(block)			(VGA_GET_COLOR(block) | 0xF0)

/**
 * Holding VGA state data
 */
struct vga_state_struct {
	uint16_t* mem;
	uint16_t mem_index;
	uint8_t param;
};

void vga_init(const uint8_t param);
void vga_set_param(const uint8_t param);
void vga_clear_screen(void);
void vga_print_character(const uint8_t character);
void vga_print_string(const uint8_t *string);

static void __vga_scroll(void);
static void __vga_set_cursor(bool is_enabled);

static inline uint8_t _inb(uint16_t port);
static inline void _outb(uint16_t port, uint8_t value);

#endif // VGA_H