CC=/usr/local/Cellar/llvm/8.0.0_1/bin/clang++

all:
	$(CC) -o dbl_gauss -L/usr/local/include/root/ dbl_gauss.cc `root-config --cflags --libs`
