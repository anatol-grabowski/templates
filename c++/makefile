#================GENERAL==============
TARGET=_-new-proj-_
TARGEX=.ex_app
TARGETEX=$(TARGET)$(TARGEX)

CPPSRCS=$(TARGET).cpp
CSRCS=
OBJS=$(patsubst %.cpp,%.o,$(CPPSRCS)) $(patsubst %.c,%.o,$(CSRCS))
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

CC=gcc$(EXEEX)
CPPC=g++$(EXEEX)
RM=del
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

%.d: %.cpp
	$(CPPC) $< -MD -o $@

%.d: %.c
	$(CC) $< -MD -o $@

