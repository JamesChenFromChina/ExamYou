all:ExamYou


ExamYou: ExamYou.c
	gcc -g ExamYou.c -o ExamYou

clean:
	rm ExamYou