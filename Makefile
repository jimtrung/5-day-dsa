run:
	g++ -g bai40.cpp -o bin/bai40
	./bin/bai40

CPP_FILES := $(shell find . -name "*.cpp")

.PHONY: count_lines

count_lines:
	@echo "Counting lines in .cpp files:"
	@total=0; \
	for file in $(CPP_FILES); do \
		lines=$$(wc -l < $$file); \
		echo "$$file: $$lines lines"; \
		total=$$((total + lines)); \
	done; \
	echo "----------------------------"; \
	echo "Total lines: $$total"