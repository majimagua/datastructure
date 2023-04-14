TARGET=main.exe
OBJ=main.o
CFLAGS=-I../src
LDFLAGS=-L../src
LIBS=-lLink

$(TARGET):$(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)

clean:
	$(RM) $(TARGET) $(OBJ)

.PHONY: clean
