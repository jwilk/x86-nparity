# Copyright © 2023 Jakub Wilk <jwilk@jwilk.net>
# SPDX-License-Identifier: MIT

CFLAGS = -g -O2 -Wall

.PHONY: all
all: nparity

.PHONY: test
test: nparity
	./nparity

.PHONY: clean
clean:
	rm -f nparity

# vim:ts=4 sts=4 sw=4 noet
