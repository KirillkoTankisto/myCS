СOMPILER = musl-clang
C_ARGS = -O3 -pedantic -static -Wall -Wextra -Wno-unused-command-line-argument -Iinclude
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

$(LIB_DIR)/libmyCS.a: src/myCS/myCS.c include/myCS.h
	$L
	mkdir $(LIB_DIR) $(BUILD_DIR)
	$L
	$(СOMPILER) $(C_ARGS) -c src/myCS/myCS.c -o $(BUILD_DIR)/myCS.o
	$L
	$(AR) $(AR_ARGS) $@ $(BUILD_DIR)/myCS.o

$(OUT_DIR)/main: src/example/main.c  $(LIB_DIR)/libmyCS.a
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

install: $(LIB_DIR)/libmyCS.a
	cp $(LIB_DIR)/libmyCS.a /usr/local/lib/
	cp include/myCS.h /usr/local/include/

uninstall: /usr/local/lib/libmyCS.a /usr/local/include/myCS.h
	sudo rm /usr/local/lib/libmyCS.a /usr/local/include/myCS.h