.PHONY: all build clear launch

all: clear build launch

build:
	g++ --std=gnu++20 2/training/2.cpp -o task

launch:
	./task