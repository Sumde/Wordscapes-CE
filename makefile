# ----------------------------
# Makefile Options
# ----------------------------

NAME = WRDSCAPE
ICON = icon.png
DESCRIPTION = "Wordscapes for the TI-84 Plus CE"
COMPRESSED = NO
ARCHIVED = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
