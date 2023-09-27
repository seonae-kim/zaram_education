
cal.o : cal.c
	gcc -c cal.c

mode1.o : mode1.c cal.h
	gcc -c mode1.c

mode2.o : mode2.c cal.h
	gcc -c mode2.c

cal_num.o : cal_num.c cal.h
	gcc -c cal_num.c

mode3.o : mode3.c cal.h cal_num.h
	gcc -c mode3.c

top_mode.o : top_mode.c cal.h mode1.h mode2.h mode3.h 
	gcc -c top_mode.c

TOP : mode1.o mode2.o mode3.o cal_num.o cal.o top_mode.o 
	gcc mode1.o mode2.o mode3.o cal_num.o cal.o top_mode.o -o TOP

