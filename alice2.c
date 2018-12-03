#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
int	N; 
int	K;
int	t;
typedef unsigned long set;
char	word[1024];
#define	first(n)	((set) ((1U << (n)) -1U))

set nextset(set x)
{
		set smallest,ripple,new_smallest,ones;

	smallest = x & -x;
	ripple = x +smallest;
	new_smallest = ripple & -ripple;
	ones =((new_smallest /smallest) >>1)-1;
	return ripple| ones;
}
void printset(set s)
{
	int	i;

	for(i=1;i<=N;i++) {
	if (s & 1) printf("%c",word[i-1]);
	s>>=1;
	}
	printf("\n");
}

void conv()
{
	int i;
	set x;

	x=first(K);
	while(! (x&~first(N))) {
		printf("%5d :",t); printset(x);
		x=nextset(x); t++;
	}
}
void	main(int argc,char *argv[]) {

	if (argc!=2) {
		fprintf(stderr,"Usage convs word\n");
		exit(0);
		}

	sscanf(*(++argv),"%s",word);
	N=strlen(word);
	t=1;
	for(K=1;K<=N;K++) {
		conv();
		}
}
	
