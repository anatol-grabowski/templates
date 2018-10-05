#================GENERAL==============
TARGET=_-new-proj-_
TARGEX=.ex_app
TARGETEX=$(TARGET)$(TARGEX)

SRCS=$(TARGET).c
OBJS=$(SRCS:.c=.o)
FLAGS=
FLAGS+=-Wall
#FLAGS+=-v
#FLAGS+=-w
#FLAGS+=-Wl,-subsystem,windows

#================COMPILER=============
DEFINES=-D FREEGLUT_STATIC
INCDIRS=-I. -I$(TOT_LIB)\freeglut\include
CFLAGS=$(DEFINES) $(INCDIRS)

#================LINKER===============
LIBDIRS=-L. -L$(TOT_LIB)\freeglut\lib
LIBS=-lfreeglut_static -lopengl32 -lwinmm -lgdi32
LFLAGS=$(LIBDIRS) $(LIBS)
LFLAGS+=-Wl,--subsystem,windows

#================TOOLS================
EXEEX=.exe

CC=gcc$(EXEEX)
RM=del
SIZE=size$(EXEEX)

#================TARGETS==============
build: $(TARGETEX)

%$(TARGEX): $(OBJS)
	$(CC) $^ \
$(FLAGS) \
$(LFLAGS) \
-o $@
	$(SIZE) $@

%.o: %.c
	$(CC) $< \
$(FLAGS) \
$(CFLAGS) \
-c -o $@

%.d: %.c
	$(CC) $< -MD -o $@

clean:
	$(RM) $(TARGETEX)
	$(RM) $(OBJS)

deps: $(TARGET).d

.PHONY: build clean deps
.PRECIOUS: %.o
