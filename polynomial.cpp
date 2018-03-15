# Auto detect text files and perform LF normalization
* text=auto
#include <stdio.h>
#include <malloc.h>
typedef struct poly {
	int a[20];
	char n;
	poly* next;
}poly;
int n = 0;
poly* s;
poly ans; 

void screen(poly a) {
	printf("Ans: ");
	int i, all = 0, e = 0;
	for (i = 19; i >= 0; i--) {
		if (a.a[i] != 0) {
			if (i != 0) {
				if (a.a[i] < 0) {
					printf("%d x^%d ", a.a[i], i);
				} else {
					if (e == 0) {
						printf("%d x^%d ", a.a[i], i);
					} else {
						printf("+%d x^%d ", a.a[i], i);
					}
				}
			} else {
				
				if (a.a[i] < 0) {
					printf("%d ", a.a[i]);
				} else {
					if (e == 0) {
						printf("%d", a.a[i]);
					} else {
						printf("+%d", a.a[i]);
					}
				}
			}
			e++;
		}
	}
	printf("\n");
	
}
void clc(poly *b) {
	int i;
	for(i = 0; i < 20; i++) {
		b->a[i] = 0;
	}
}
void Input() {
	char name;
	poly* p;
	int a = 0, m, l, t;
	getchar();
	printf("Please enter a single character as name for this poly: ");
	scanf("%c", &name);
	printf("Please enter the poly: ");
	if (n == 0) {
		s = (poly*)malloc(sizeof(poly));
		p = s;
		p->n = name;
	} else {
		p = s;
		while (a < n - 1) {
			p = p->next;
			a++;
		}
		p->next = (poly*)malloc(sizeof(poly));
		p = p->next;
		p->n = name;
	}
	clc(p);
	n++;
	getchar();
	while ((t = getchar()) != '\n') {
		if (t == '(') {
			scanf("%d", &m);
			getchar();
			scanf("%d", &l);
			getchar();
			p->a[l] += m;
		}
	}
	printf("Successfully saved!\n");
}
void Add() {
	char a, b;
	int k;
	poly* i, *j;
	getchar();
	printf("Please enter the name of poly1: ");
	scanf("%c", &a);
    getchar();
	printf("Please enter the name of poly2: ");
	scanf("%c", &b);
	i = s;
	while (i->n != a) {
		i = i->next;
	}
	j=s;
	while (j->n !=b) {
		j=j->next;
	}
	for(k = 0; k<20; k++) {
		ans.a[k] = i->a[k]+j->a[k];
	}
	screen(ans);
	clc(&ans);
}
void Minus() {
	char a, b;
	int k;
	poly* i, *j;
	getchar();
	printf("Please enter the name of poly1: ");
	scanf("%c", &a);
	getchar();
	printf("Please enter the name of poly2: ");
	scanf("%c", &b);
	i = s;
	while (i->n != a) {
		i = i->next;
	}
	j=s;
	while (j->n !=b) {
		j=j->next;
	}
	for(k = 0; k<20; k++) {
		ans.a[k] = i->a[k]-j->a[k];
	}
	screen(ans);
	clc(&ans);
}
void Point() {
	char a;
	printf("Please enter the name of poly: ");
	getchar();
	scanf("%c",&a);
	int result = 0, o, k;
	poly* i;
	i = s;
	while(i->n !=a) {
		i = i->next;
	}
	printf("Please enter the number: ");
	scanf("%d", &o);
	for (k = 19; k>=0; k--) {
		result += i->a[k];
		result *= o;
	}
	result /= o;
	printf("Result: %d", result);
}
void Screenall() {
	poly* i;
	int k;
	i = s;
	for(k = 0; k <n; k++) {
		printf("Name: %c\n", i->n);
		screen(*i);
		i=i->next;
	}
	printf("\n");
}
void Derivative() {
	poly* i;
	char a;
	int k;
	printf("Please enter the name of a poly: ");
	getchar();
	scanf("%c",&a);
	i = s;
	while(i->n!= a) {
		i=i->next;
	}
	for (k = 0; k<19;k++) {
		ans.a[k] = i->a[k+1]*(k+1);
	}
	screen(ans);
	clc(&ans);
}
void Multiply() {
	poly* i, *j;
	char a, b;
	getchar();
	printf("Please enter the name of poly1: ");
	scanf("%c",&a);
	getchar();
	printf("Please enter the name of poly2: ");
	scanf("%c", &b);
	int m, l;
	i = s;
	while(i->n!=a) {
		i=i->next;
	}
	j=s;
	while(j->n!=b) {
		j=j->next;
	}
	for(m=0; m<10; m++) {
		for(l=0; l<10; l++) {
			ans.a[m+l] += i->a[m]*j->a[l];
		}
	}
	screen(ans);
	clc(&ans);
}
void Menu() {
	printf("1: Input your poly\n");
	printf("2: Add two polies\n");
	printf("3: Poly1 minus Poly2\n");
	printf("4: Calculate the value of a poly whose variable is give as number\n");
	printf("5: Multiply two polies\n");
	printf("6: Take the Derivative of a poly\n");
	printf("7: Screen all saved polies\n");
	printf("0: Show this menu again\n");
	printf("-1:Quit\n");
	printf("****Caution: All results cannot be saved automatically!****\n");
	printf("Please enter your choice:   ");
}
int main() {
	int c;
	Menu();
	scanf("%d", &c);
	while (c != -1) {
		if (c == 1) {
            Input();
        } else if (c == 2) {
            Add();
        } else if (c == 3) {
            Minus();
        } else if (c == 4) {
            Point();
        } else if (c == 5) {
            Multiply();
        } else if (c == 6) {
            Derivative();
        } else if (c == 7) {
            Screenall();
        } else if (c == 0) {
            Menu();
        } else {
            printf("Input Error! Please enter again:   ");
        }
        scanf("%d", &c);
	}
	return 0;
}
