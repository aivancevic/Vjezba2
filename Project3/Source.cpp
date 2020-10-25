#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_LENGTH 256

struct Osoba;
typedef struct Osoba* Pozicija;

int UpisPocetak(Pozicija);
int UpisKraj(Pozicija);
int Ispis(Pozicija);
Pozicija Trazi(Pozicija);
Pozicija TraziPrethodni(Pozicija);
int Brisi(Pozicija);
int OslobadanjeMemorije(Pozicija);

struct Osoba {
	char ime[BUFFER_LENGTH];
	char prezime[BUFFER_LENGTH];
	int godRodenja;
	Pozicija next;
};

int main()
{
	struct Osoba head;
	head.next = NULL;
	int unos;
	
	unos = 0;

	while (unos != 6) {
		printf("1-->Dodavanje elementa na pocetak!\n2-->Dodavanje elementa na kraj!\n3-->Ispis elemenata!\n4-->Trazi element po prezimenu!\n5-->Brisanje odredenog elementa po prezimenu!\n6-->Izlaz!!!");
		printf("Unesite broj: ");
		scanf_s("%d", &unos);
		switch (unos){
		case 1:
			printf("Dodajte element(ime,prezime,god rodenja) na pocetak liste!\n");
			UpisPocetak(&head);
			break;
		case 2:
			printf("Dodajte element(ime,prezime,god rodenja) na kraj liste!\n");
			UpisKraj(&head);
			break;
		case 3:
			printf("Ispis elemenata!\n");
			Ispis(head.next);
			break;
		case 4:
			printf("Trazi element(ime,prezime,god rodenja) po prezimenu!\n");
			Trazi(head.next);
			break;
		case 5 :
			printf("Brisi element(ime,prezime,god rodenja) po prezuimenu!\n");
			Brisi(&head);
			break;
		case 6:
			OslobadanjeMemorije(&head);
			printf("IZLAZ!!!");
				break;
		default:
			printf("Pogresan unos!!!");
			break;
		}
	}
	return 0;
}

	int UpisPocetak(Pozicija P){

		Pozicija q;

		q = (Pozicija)malloc(sizeof(struct Osoba));

		if (q == NULL) {
			printf("Neuspjesna alokacija");
			return 1;
		}
		
		printf("Unesite ime: ");
		scanf(" %s", q->ime);
		printf("Unesite prezime: ");
		scanf(" %s", q->prezime);
		printf("Unesite godina rodenja: ");
		scanf_s(" %d", &q->godRodenja);

		q->next = P->next;
		P->next = q;

	return 0;
}

	int UpisKraj(Pozicija P)
	{
		while (P->next != NULL) {
			P = P->next;
		}
		UpisPocetak(P);
		return 0;
	}

	int Ispis(Pozicija P)
	{
		if (P == NULL) {
			printf("Lista je prazna!\n");
		}
		else
		{
			while (P != NULL) {
				printf("%s %s %d\n", P->ime, P->prezime, P->godRodenja);
				P = P->next;
			}
		}
		
		return 0;
	}

	Pozicija Trazi(Pozicija P)
	{
		char temp[BUFFER_LENGTH];

		printf("Unesite prezime: ");
		scanf(" %s", temp);

		while (P!=NULL && strcmp(temp,P->prezime)!=0)
		{
			P = P->next;
		}

		if (P == NULL) {
			printf("Prezime nije pronadeno!\n");
			return NULL;
		}

		printf(" %s %s %d\n", P->ime, P->prezime, P->godRodenja);
		return P;
	}

	Pozicija TraziPrethodni(Pozicija P)
	{
		char temp[BUFFER_LENGTH];

		printf("Unesite trazeno prezime: ");
		scanf(" %s", &temp);

		while (P->next != NULL && strcmp(temp, P->next->prezime) != 0) {
			P = P->next;
		}

		if (P->next == NULL) {
			printf("Nema elementa sa navedenim prezimenom\n");
			return NULL;
		}
		else {
			printf("Pronadjen element\n");
			return P;
		}
	}

	int Brisi(Pozicija P)
	{
		P = TraziPrethodni(P);
		Pozicija temp;

		if (P == NULL) {
			printf("Nije moguce brisanje!\n");
			return 1;
		}
		else {
			temp = P->next;
			P->next = temp->next;
			printf("Brisanje elementa %s %s %d\n", temp->ime, temp->prezime, temp->godRodenja);
			free(temp);
		}
		return 0;
	}

	int OslobadanjeMemorije(Pozicija P)
	{
		if (P->next == NULL) {
			free(P);
			return 0;
		}
		else {
			P = P->next;
			OslobadanjeMemorije(P);
		}
		return 0;
	}


