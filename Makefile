CC=/usr/local/Cellar/llvm/8.0.0_1/bin/clang++
INCL=/usr/local/include/root/

all:
	$(CC) -o dbl_gauss -L$(INCL) dbl_gauss.cc `root-config --cflags --libs`
