TARGET=libLink_Reverse.so
OBJ=Link_Reverse.o
CFLAGS=-fPIC -I../../Link/src
LDFLAGS=-shared -L../../Link/src
LIBS=-lLink

$(TARGET):$(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)
	@echo "Build success!"

clean:
	$(RM) $(TARGET) $(OBJ)
.PHONY: clean

