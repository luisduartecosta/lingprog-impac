CPP=g++
CPPFLAGS=$(shell perl -MExtUtils::Embed -e ccopts -I ../perl/)
LD=g++
LDFLAGS=$(shell perl -MExtUtils::Embed -e ldopts -I ../perl/)

all: programa

.cpp.o:
	$(CPP) $(CPPFLAGS) -o $@ -c $<

programa: main.o p2cpp.o mainfunctions.o sensor.o util.o alarm.o
	$(LD) -o $@ $? $(LDFLAGS)

clean:
	rm -rf programa *.o