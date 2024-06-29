build:
	g++ -std=c++17 -g -Wall *.cpp -o scheme 
clean: 
	$(RM) scheme