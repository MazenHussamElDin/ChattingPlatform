CXX = g++


SOURCES = Hmap.cpp main.cpp  LinkedList.cpp Message.cpp User.cpp Chat.cpp SystemManager.cpp
HEADERS = Hmap.hpp LinkedList.hpp Message.hpp User.hpp Chat.hpp SystemManager.hpp
TARGET = Hmap


$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(SOURCES) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)
	
.PHONY: run
run: $(TARGET)
	./$(TARGET)