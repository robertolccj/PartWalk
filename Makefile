HEADERS1=./headers/
LIBS1=./libs/


all: PartWalk


PartWalk: PartWalk.cpp
	c++ $^ -o $@ -I$(HEADERS1) -L$(LIBS1) -lcwalk

%.dat:%.log
	sed '/^#/ d' $< | awk '{print$$3}' > $@

run: dados_cell.txt dados_line.txt
	./PartWalk $^

.PHONY: clean
clean:
	-@rm -f *.dat
	@echo Limpeza Feita
