.SUFFIXES: .cpp .c
.c.o:
	@echo "[+] Compiling $<"
	@gcc -O2 -c $<

objects = bmp.o cv.o main.o

all: $(objects)
	@echo "[+] Linking..."
	@gcc -o main $(objects)
	@mkdir -p debug
	@mv main debug/main
	@rm $(objects)
	@echo "Done"

clean: 
	@rm debug/main
	@rm debug -r
