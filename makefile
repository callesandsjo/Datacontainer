ifeq ($(OS), Windows_NT)
	
	BIN := Bin\\
	BUILD := Build\\
	INCLUDES := Includes\\
	SOURCE := Source\\
	EXECUTABLE := $(BIN)Laboration_4.exe
	DELETE := del
else
	BIN := Bin/
	BUILD := Build/
	INCLUDES := Includes/
	SOURCE := Source/
	EXECUTABLE := $(BIN)/Laboration_4
	DELETE := rm
endif

all: $(EXECUTABLE)

$(EXECUTABLE): $(BUILD)Main.o 
	g++ -g -std=c++11 $(BUILD)Main.o -o $(EXECUTABLE)


$(BUILD)Main.o: $(SOURCE)Main.cpp
	g++ -g -c -std=c++11 $(SOURCE)Main.cpp -I$(INCLUDES) -o $(BUILD)Main.o


clean:
	-$(DELETE) $(BUILD)Main.o $(EXECUTABLE)
