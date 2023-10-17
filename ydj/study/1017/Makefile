program_func.o : program_func.c
	gcc -c -o program_func.o program_func.c

re_1_prob.o : re_1_prob.c
	gcc -c -o re_1_prob.o re_1_prob.c

re_1_prob : re_1_prob.o program_func.o
	gcc program_func.o re_1_prob.o -o re_1_prob

clean : 
	rm *.o
	rm member_info.txt
	rm re_1_prob
