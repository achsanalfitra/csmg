CC = emcc
CXX = em++
WEB_DIR = .
SOURCES = main.c
SOURCES += custom_lib.cpp
# OBJS = target output names, which are the source files that ends with .o
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
EMS = main.js

# run this with make PLATFORM=Windows clean to trigger the correct clean command for windows
ifeq ($(PLATFORM), Windows)
    RM = del /F
else
    RM = rm -f
endif

.PHONY: all clean

all: $(EMS)

$(EMS): $(OBJS)
	$(CXX) $(OBJS) -o $@ -std=c++17 -Wl,--no-entry

%.o: %.c
	$(CC) -c $< -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@ -std=c++17

clean:
	${RM} $(OBJS) $(EMS) $(EMS:.js=.wasm)