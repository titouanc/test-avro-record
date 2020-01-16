CFLAGS := -std=c99 -Wall -Wextra -Werror

CFLAGS += $(shell pkg-config --cflags avro-c)
LDFLAGS += $(shell pkg-config --libs avro-c)

SRC = $(wildcard test-*.c)
RUN = $(patsubst %.c,%.run,$(SRC))
OK = $(patsubst %.c,%.ok,$(SRC))

all: $(OK)

%.run: %.c main.c
	@$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

%.ok: %.run
	@echo -e "\033[1mRunning $<...\033[0m"
	@./$< && touch $@ && echo -e "\033[32;1m$< OK\033[0m"\
	                  || echo -e "\033[31;1m$< FAIL\033[0m"
	@echo "--------------------------------------------------"

clean:
	rm -f *.avro *.ok *.run

.PRECIOUS: $(RUN)
