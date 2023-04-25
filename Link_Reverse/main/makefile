TARGET=main.exe
OBJ=main.o
CFLAGS=-I../src -I../../Link/src
LDFLAGS=-L../src -L../../Link/src
LIBS=-lLink -lLink_Reverse

$(TARGET):$(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)
	@echo "Build success!"

clean:
	$(RM) $(TARGET) $(OBJ)

.PHONY: clean
