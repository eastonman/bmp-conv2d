.SUFFIXES: .cpp .c
.c.o:
	@echo "[+] Compiling $<"
	@gcc -g -c $<

objects = bmp.o cv.o main.o

all: $(objects)
	@echo "[+] Linking..."
	@gcc -O3 -o main $(objects)
	@mkdir -p debug
	@mv main debug/main
	@rm $(objects)
	@echo "Done"

debug: $(objects)
	@echo "[+] Linking..."
	@gcc -g -o main $(objects)
	@mkdir -p debug
	@mv main debug/main
	@rm $(objects)
	@echo "Done"

clean: 
	@rm debug/main
	@rm debug -r
