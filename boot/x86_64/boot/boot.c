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

#include "../video/vga.h"

void kmain(void) {
	const char *name = KERNEL_NAME;
	const char *version = KERNEL_VERSION;
	uint16_t param = VGA_SET_COLOR_PARAM(VGA_COLOR_BLACK,VGA_COLOR_GREEN);

	// Print kernel info
	vga_init(param);
	vga_clear_screen();
	vga_print_string(name);
	vga_print_character(' ');
	vga_print_string(version);

	return;
}