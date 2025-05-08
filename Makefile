run:
	g++ -g bai39.cpp -o bin/bai39
	./bin/bai39

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