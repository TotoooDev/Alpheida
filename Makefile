.PHONY: linux switch clean

linux:
	make -f Makefile.linux

switch:
	@mkdir -p bin
	@mkdir -p obj
	make -f Makefile.switch

wii:
	@mkdir -p bin
	@mkdir -p obj
	make -f Makefile.wii

clean:
	@echo "Cleaning..."
	@rm -r obj/*
	@rm -r bin/*
