CC=clang++
CPPFLAGS=-Wall -g
CFLAGS=-c $(CPPFLAGS)
LD=clang++
LDFLAGS=
LDLIBS=
CLASSES=card.cpp hand.cpp
OBJECTS=$(CLASSES:.cpp=.o)


all: testhand

testhand: $(OBJECTS) checktest.cpp test_hand.cpp
	$(LD) $(CPPFLAGS) $^ -o $@

%.o: %.cpp %.h
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf $(OBJECTS)
