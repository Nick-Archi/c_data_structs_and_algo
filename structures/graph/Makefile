# Variables

OUT_DIR := output/
OUT_O_DIR := obj/
PROJ = proj
CFLAGS = -I include
CC = gcc
SOURCE = $(wildcard src/*.c)
INC = $(wildcard include/*.h)
$(info "inc = " $(INC))
# convert .cpp to .o and place in obj dir
OBJS = $(SOURCE:src/%.c=$(OUT_O_DIR)%.o) 

.PHONY: directories dot

all :	directories $(OUT_DIR)$(PROJ)

directories:	$(OUT_DIR) $(OUT_O_DIR)

dot: $(OUT_DIR)$(PROJ)
	$(info "HI") 
#command to use a .dot file to generate a pdf of the graph
# need to run the main program to generate the dot struct and copy and paste... 
#dot example.dot -Tpdf > graph.pdf

# Rules

$(OUT_DIR)$(PROJ) :	$(OBJS)
	$(CC) -o $@ $(OBJS)

# for any object file, look for corresponding cpp
${OUT_O_DIR}%.o: src/%.c $(INC)
	$(CC) -c $(CFLAGS) $< -o $@	

clean :
	rm -rf $(OUT_DIR)
	rm -rf $(OUT_O_DIR)

$(OUT_DIR) :	
	mkdir -p $(OUT_DIR)

$(OUT_O_DIR) :
	mkdir -p $(OUT_O_DIR)
