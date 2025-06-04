CXX = g++
CXXFLAGS = -Wall -Wextra -O2
TARGET = monkey
SRC = monkey_q_learning.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

check:
	@echo "Running tests (dummy)"
	@./$(TARGET)

distcheck: check
	@echo "Running distcheck (dummy)"

clean:
	rm -f $(TARGET)
