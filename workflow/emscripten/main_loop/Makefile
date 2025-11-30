CC = emcc
WEB_DIR = .
SOURCES = main.c
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
EMS = main.html
EMS_FLAG = 

ifeq ($(PLATFORM), Windows)
    RM = del /F
else
    RM = rm -f
endif

.PHONY: all clean

all: $(EMS)

$(EMS): $(OBJS)
	$(CC) $(OBJS) -o $@ $(EMS_FLAG) -Wl,--no-entry

%.o: %.c
	$(CC) -c $< -o $@

clean:
	${RM} $(OBJS) $(EMS) $(EMS:.js=.wasm)

