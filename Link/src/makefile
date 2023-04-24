TARGET=libLink.so
OBJ=Link.o
CFLAGS=-fPIC
LDFLAGS=-shared -L../src
LIBS=-lLink

$(TARGET):$(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)
	@echo "build success!"

clean:
	$(RM) $(TARGET) $(OBJ)
.PHONY: clean

