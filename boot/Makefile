# Copyright [2020] [Project Vault Team]
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# you may obtain a copy of the License at
# 
#   http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Architecture-dependend files build
X86_PATH	= x86_64
ARM_PATH	= arm
ARM64_PATH	= arm64

# Build the project for x86_64
ifeq ($(ARCH), x86_64)
BOOT_PATH 	= $(X86_PATH)
endif

# Build the project for arm
ifeq ($(ARCH), arm)
BOOT_PATH 	= $(ARM_PATH)
endif

# Build the project for arm64
ifeq ($(ARCH), arm64)
BOOT_PATH 	= $(ARM64_PATH)
endif

# Disable preinstalled suffixes
.SUFFIXES:

# Declare phony targets
.PHONY : all boot

# The main target
all : boot

# Build the target
boot :
	cd $(BOOT_PATH) && $(MAKE)