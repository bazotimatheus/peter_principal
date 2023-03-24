CC=gcc
CFLAGS=-O1
LIBS=-lm -g

RM=rm -fr

# Diretorios
SDIR=src
LDIR=lib
ODIR=obj

# Seta os arquivos fontes e gera os objetos
_SRCS=peter.c random.c observaveis.c simples.c main.c 
SRCS=$(patsubst %,$(SDIR)/%,$(_SRCS))

_DEPS=peter.h random.h observaveis.h simples.h
DEPS=$(patsubst %,$(LDIR)/%,$(_DEPS))

_OBJS=$(_SRCS:.c=.o)
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o:$(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

peter: $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	$(RM) $(OBJS) peter *~ *.out