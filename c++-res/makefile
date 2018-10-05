#================GENERAL==============
TARGET=main
TARGEX=.ex_app
TARGETEX=$(TARGET)$(TARGEX)

CPPSRCS=$(TARGET).cpp
CSRCS=
RSRCS=resources.rc
OBJS=$(patsubst %.cpp,%.o,$(CPPSRCS))
OBJS+=$(patsubst %.c,%.o,$(CSRCS))
OBJS+=$(patsubst %.rc,%.o,$(RSRCS))
FLAGS=
FLAGS+=-Wall
#FLAGS+=-v
#FLAGS+=-w
#FLAGS+=-Wl,-subsystem,windows

#================COMPILER=============
DEFINES=
INCDIRS=-I.
CFLAGS=$(DEFINES) $(INCDIRS)

#================LINKER===============
LIBDIRS=-L.
LIBS=
LFLAGS=$(LIBDIRS) $(LIBS)

#================TOOLS================
EXEEX=

RM=rm$(EXEEX) -f
CC=gcc$(EXEEX)
CPPC=g++$(EXEEX)
WINDRES=windres$(EXEEX)
SIZE=size$(EXEEX)

#================TARGETS==============
build: $(TARGETEX)

clean:
	$(RM) $(TARGETEX)
	$(RM) $(OBJS)

deps: $(TARGET).d

.PHONY: build clean deps
.PRECIOUS: %.o

#-------------------------------------
%$(TARGEX): $(OBJS)
	$(CPPC) $^ \
$(FLAGS) \
$(LFLAGS) \
-o $@
	$(SIZE) $@

%.o: %.cpp
	$(CPPC) $< \
$(FLAGS) \
$(CFLAGS) \
-c -o $@

%.o: %.c
	$(CC) $< \
$(FLAGS) \
$(CFLAGS) \
-c -o $@

%.o: %.rc
	$(WINDRES) $< $@

%.d: %.cpp
	$(CPPC) $< -MD -o $@

%.d: %.c
	$(CC) $< -MD -o $@

