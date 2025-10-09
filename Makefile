output_file = wifi_collector
compile: 
	gcc main.c main_functions.c  helper_functions.c cell.c -o output_file

run: compile
	./output_file

clean:
	rm -f output_file