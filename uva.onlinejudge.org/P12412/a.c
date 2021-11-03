#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EPS 1e-5
#define REMOVE 1
#define QUERY 0
#define show_class_subject(subject, xxx) \
	do { \
		tot = 0, passed = 0, failed = 0; \
		for (i = 0; i < top; ++i) \
		if (!removed[i] && (a[i].CID == CID || CID == 0)) { \
			tot += a[i].xxx; \
			if (a[i].xxx >= 60) ++passed; \
			else ++failed; \
		} \
		printf( \
				subject "\n" \
				"Average Score: %.2f\n" \
				"Number of passed students: %d\n" \
				"Number of failed students: %d\n" \
				"\n", \
				(passed + failed == 0) ? 0 : (double)tot / (passed + failed) + EPS, \
				passed, \
				failed \
		      ); \
	} \
	while (0) 

void Add(void);
void Remove(void);
void Query(void);
void Show_ranking(void);
void Show_Statistics(void);

int want_to_exit(char* SID);
int same_SID(char* SID);
void process_remove_query(int type);

void print_student_info(int idx);
void print_main_menu(void);
int get_rank(int score);

typedef struct {
	char SID[19], name[19];
	int CID, C, M, E, P;
} student;
student a[209];
int removed[209], top = 0;

int main(void)
{
	for (; ; ) {
		int choose;
		print_main_menu();
		scanf("%d", &choose);
		switch (choose) {
			case 1: { Add(); break; }
			case 2: { Remove(); break; }
			case 3: { Query(); break; }
			case 4: { Show_ranking(); break; }
			case 5: { Show_Statistics(); break; }
			case 0: { return 0; break; }
		}
	}
	return 0;
}

void Add(void)
{
	for (; ; ) {
		puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
		scanf("%s", a[top].SID);
		if (want_to_exit(a[top].SID)) return;

		scanf(
				"%d%s%d%d%d%d",
				&a[top].CID,
				a[top].name,
				&a[top].C,
				&a[top].M,
				&a[top].E,
				&a[top].P
		     );

		if (same_SID(a[top].SID)) {
			puts("Duplicated SID.");
		} else {
			++top;
		}
	}
}

void Remove(void)
{
	process_remove_query(REMOVE);
}

void Query(void)
{
	process_remove_query(QUERY);
}

void Show_ranking(void)
{
	puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
}

void Show_Statistics(void)
{
	int CID, i, tot, passed, failed, totpass[6];
	puts("Please enter class ID, 0 for the whole statistics.");
	scanf("%d", &CID);

	show_class_subject("Chinese", C);
	show_class_subject("Mathematics", M);
	show_class_subject("English", E);
	show_class_subject("Programming", P);

	memset(totpass, 0, 6 * sizeof(int));
	for (i = 0; i < top; ++i)
		if (!removed[i] && (a[i].CID == CID || CID == 0)) {
			int pass = 0;
			if (a[i].C >= 60) ++pass;
			if (a[i].M >= 60) ++pass;
			if (a[i].E >= 60) ++pass;
			if (a[i].P >= 60) ++pass;
			++totpass[pass];
		}
	printf(
			"Overall:\n"
			"Number of students who passed all subjects: %d\n"
			"Number of students who passed 3 or more subjects: %d\n"
			"Number of students who passed 2 or more subjects: %d\n"
			"Number of students who passed 1 or more subjects: %d\n"
			"Number of students who failed all subjects: %d\n"
			"\n",
			totpass[4],
			totpass[3] + totpass[4],
			totpass[2] + totpass[3] + totpass[4],
			totpass[1] + totpass[2] + totpass[3] + totpass[4],
			totpass[0]
	      );
}

void print_main_menu(void)
{
	printf(
			"Welcome to Student Performance Management System (SPMS).\n"
			"\n"
			"1 - Add\n"
			"2 - Remove\n"
			"3 - Query\n"
			"4 - Show ranking\n"
			"5 - Show Statistics\n"
			"0 - Exit\n"
			"\n"
	      );
}

int want_to_exit(char* SID)
{
	if (atoi(SID) == 0) return 1;
	return 0;
}

int same_SID(char* SID)
{
	int i;
	for (i = 0; i < top; ++i)
		if (!removed[i] && strcmp(a[i].SID, SID) == 0)
			return 1;
	return 0;
}

void process_remove_query(int type)
{
	for (; ; ) {
		char buf[19];
		int i, cnt = 0;

		puts("Please enter SID or name. Enter 0 to finish.");
		scanf("%s", buf);
		if (isdigit(buf[0]))
			if (want_to_exit(buf))
				break;
		for (i = 0; i < top; ++i)
			if (!removed[i] && (
						(strcmp(a[i].SID , buf) == 0)|| 
						(strcmp(a[i].name, buf) == 0))
					) {
				if (type == REMOVE) {
					removed[i] = 1;
					++cnt;
				} else {
					print_student_info(i);
					++cnt;
				}
			}
		if (type == REMOVE) printf("%d student(s) removed.\n", cnt);
	}
}

void print_student_info(int i)
{
	int tot = a[i].C + a[i].M + a[i].E + a[i].P;
	printf(
			"%d %s %d %s %d %d %d %d %d %.2f\n",
			get_rank(tot),
			a[i].SID,
			a[i].CID,
			a[i].name,
			a[i].C,
			a[i].M,
			a[i].E,
			a[i].P,
			tot,
			(double)tot / 4 + EPS
	      );
}

int get_rank(int score)
{
	int i, rank = 1;
	for (i = 0; i < top; ++i)
		if (!removed[i] && a[i].C + a[i].M + a[i].E + a[i].P > score)
			++rank;
	return rank;
}
