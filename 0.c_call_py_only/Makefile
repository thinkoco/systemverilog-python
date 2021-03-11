
all:	clean comp run

clean:
	rm -rf main __pycache__
comp:
	gcc c_call_py.c -o main -I/usr/include/python3.6m -lpython3.6m -lpthread -ldl -lutil -lm
run:
	export PYTHONPATH=. && ./main
