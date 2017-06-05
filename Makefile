PROGRAMS=$(wildcard programs/*)
MODE = release
PLATFORM = arduino
SCONS = /usr/bin/scons
SCONS += mode=$(MODE) platform=$(PLATFORM)

.PHONY: all clean install $(EXAMPLES)

default: all

all:
	@echo "== Building in mode $(MODE) =="
	$(SCONS)
	
clean:
	@echo "== Cleaning mode $(MODE) =="
	$(SCONS) --clean

install:
	@echo "== Installing in mode $(MODE) =="
	$(SCONS) install

programs: $(PROGRAMS)

$(PROGRAMS): all
	@echo "== Building example $@ in mode $(MODE) =="
	@cd $@ && $(SCONS)
