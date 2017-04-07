CC ?= gcc
CFLAGS_common ?= -g -Wall -std=gnu99

EXEC = matrix
SRCS = main.c

GIT_HOOKS := .git/hooks/applied

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

.PHONY: all
all: $(GIT_HOOKS) $(EXEC)

matrix: $(SRCS) matrix.c matrix.h
	$(CC) $(CFLAGS_common) \
		-o $@ \
		$(SRCS) $@.c


.PHONY: clean
clean:
	rm -rf $(EXEC)
