# C Programming Handbook — Makefile
# Build all demos, a single topic, or clean artifacts.
#
# Usage:
#   make          — build every program into bin/
#   make 01       — build only topic 01
#   make run-01   — build and run topic 01
#   make clean    — remove binaries

CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -Wpedantic -O2
SRCDIR  = src
BINDIR  = bin

SOURCES = $(wildcard $(SRCDIR)/*.c)
TARGETS = $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%,$(SOURCES))

.PHONY: all clean run-% help

all: $(BINDIR) $(TARGETS)
	@echo "Built $(words $(TARGETS)) programs into $(BINDIR)/"

$(BINDIR):
	mkdir -p $(BINDIR)

$(BINDIR)/%: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $<

# Short aliases: make 01, make 02, ...
01 02 03 04 05 06 07 08 09 10 11:
	@file=$$(ls $(SRCDIR)/$@_*.c 2>/dev/null | head -1); \
	if [ -z "$$file" ]; then echo "No source for topic $@"; exit 1; fi; \
	base=$$(basename $$file .c); \
	$(CC) $(CFLAGS) -o $(BINDIR)/$$base $$file && echo "Built $(BINDIR)/$$base"

run-%: %
	@file=$$(ls $(SRCDIR)/$*_*.c 2>/dev/null | head -1); \
	base=$$(basename $$file .c); \
	./$(BINDIR)/$$base

clean:
	rm -rf $(BINDIR)
	rm -f *.tmp sample_*.txt demo_*.bin data.txt output.txt

help:
	@echo "Targets: all | 01..11 | run-01..run-11 | clean"
