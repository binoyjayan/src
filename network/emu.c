
#include<stdio.h>
#define SIZE 100

char arr[100][50];
int sno, rno;

void readline(char *s)
{
        int i=0;
        while((s[i]=getchar())!='\n')
        {
                i++;
        }
        s[i] = 0;
}

int Send(FILE *fd, int size)
{
	int r;
	memset(arr[sno], 0, 50);
	r = fread(arr[sno], 1, size,  fd);
	printf("%s\n", arr[sno]);
	sno++;
	return r;
}

int Recv(FILE *fd, int size)
{
	int r;
	r = fwrite(arr[rno], 1, size, fd);
	rno++;
	return r;
}

int Connect(char *f1, char * f2, FILE **fp1, FILE **fp2)
{
	sno = rno = 0;
	*fp1 = fopen(f1, "r");
	if(*fp1 == NULL)
		return -1;
	*fp2 = fopen(f2, "w");
	if(*fp2 == NULL)
		return -2;
	return 0;
}
int Close(FILE *fp1, FILE *fp2)
{
	fclose(fp1);
	fclose(fp2);
}
main()
{
	FILE *fp1, *fp2;
	int r, psize;
	Connect("in", "out", &fp1, &fp2);
	printf("Enter packet size :");
	scanf("%d", &psize);

	while((r=Send(fp1, psize)) > 0)
	{
		Recv(fp2, r);
	}

	Close(fp1, fp2);
}
