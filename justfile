alias t := test
source := "main.cpp sim.cpp cli.cpp"

build:
	mkdir -p build
	g++ -std=c++26 {{source}} -o build/nbody

test: build
	./build/nbody < tests/test1.in
