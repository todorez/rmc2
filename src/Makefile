CXX=g++
RM=rm -f
CPPFLAGS=-Iincludes/
LDFLAGS=-Wl,-Bstatic
LDLIBS=-lcrypto

SRCS=Smbios.cpp BiosEntry.cpp RmcFingerprint.cpp RmcTool.cpp Globals.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
DEPS = $(wildcard includes/*.h)

all: rmc-tool

debug: DFLAGS = -g -O0 -DDBG
debug: clean rmc-tool

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(DFLAGS)

rmc-tool: $(OBJS)
	$(CXX) -o $@ $^ $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -Wl,-Bdynamic

clean:
	$(RM) $(OBJS) rmc-tool
