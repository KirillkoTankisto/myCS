СOMPILER = musl-clang
C_ARGS = -O3 -pedantic -static -Wno-unused-command-line-argument -mtune=skylake -march=skylake -Iinclude
AR = ar
AR_ARGS = rcs
LIB_DIR = lib
BUILD_DIR = build
OUT_DIR = out
SRC_DIR = src

STRIP = strip --strip-all
GETSIZE = @du --bytes

C_prefix = ":CC: "
C = @echo -n $(C_prefix)

L_PREFIX = ":LL: "
L = @echo -n $(L_PREFIX)

all: $(LIB_DIR)/libmyCS.a out/main

$(LIB_DIR)/libmyCS.a: src/myCS/myCS.c include/myCS.h
	$L
	mkdir $(LIB_DIR) $(BUILD_DIR)
	$L
	$(СOMPILER) $(C_ARGS) -c src/myCS/myCS.c -o $(BUILD_DIR)/myCS.o
	$L
	$(AR) $(AR_ARGS) $@ $(BUILD_DIR)/myCS.o

out/main: src/example/main.c  $(LIB_DIR)/libmyCS.a
	$C
	mkdir $(OUT_DIR)
	$C	
	$(СOMPILER) $(C_ARGS) src/example/main.c -L$(LIB_DIR) -lmyCS -o $@
	$C
	$(STRIP) $@
	$C
	$(GETSIZE) $@

clean:
	rm -rf $(LIB_DIR) $(BUILD_DIR) $(OUT_DIR)