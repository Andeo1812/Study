.PHONY: all build clear launch build_int

all: clear build launch

TARGET_DZ = 2

TARGET_RK = A

TARGET_MODULE = module_1

build_dz:
	g++ --std=gnu++20 -Wall -Wextra -Werror -Wpedantic $(TARGET_MODULE)/$(TARGET_DZ).cpp -o task

build_rk:
	g++ --std=gnu++20 -Wall -Wextra -Werror -Wpedantic $(TARGET_MODULE)/RK/$(TARGET_RK).cpp -o task

check:
	./run_linters.sh

launch:
	./task