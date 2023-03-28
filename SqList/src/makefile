TARGET=libSqList.so
OBJ=SqList.o
CFLAGS=-fPIC
LDFLAGS=-shared

$(TARGET):$(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@ 
	@echo "build success!"

clean:
	$(RM) $(TARGET) $(OBJ)
.PHONY:clean
