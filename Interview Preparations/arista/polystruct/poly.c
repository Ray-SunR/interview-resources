#include <stdlib.h>
#include <math.h>
#include "poly.h"
struct poly* polyCreate()
{
	struct poly* p;
    p = malloc(sizeof(struct poly));
    p->a = malloc(sizeof(double));
    p -> length = 0;
    p -> size = 1;
	return p;
}
struct poly* polyDelete(struct poly* p)
{
		free(p->a);
		free(p);
	return 0;
}
struct poly *polySetCoefficient(struct poly *p, int i, double value)
{
//	printf("i = %d", i);
	if(p==(struct poly*)0)
		return 0;
	if(i>= p->size)
	{
		do
		{
			p->size *= 2;
		}while(i>=p->size);
		p->a = realloc(p->a, p->size*sizeof(double));
	}
	while(i>=p->length)
	{
		p->a[p->length] = 0;
		p->length++;
	}
	p->a[i] = value;
	return p;
}
double polyGetCoefficient(struct poly* p, int i)
{
	if(i>p->length)
		return 0;
	else
	return p->a[i];
}
int polyDegree(struct poly* p)
{
	return ((p->length)-1);
}
void polyPrint(struct poly *p)
{
	int i = 0, flag, b = 0;
			flag=0;
			for(i=p->length-1;i>=0;i--)
			{
			    if(p->a[i]-(int)p->a[i]!=0)
					flag++;
			}
			int pos=0;
			for(i=p->length-1;i>=0;i--)
			{
				if(p->a[i]!=0)
				{
			    	pos = i;
			    	break;
				}
			}
			for(i=p->length-1;i>=pos;i--)
			{
					if(p->a[i]==0)
						b++;
			}
			int y=0;
			if(b==p->length || p->length==0)
			{
		     printf("%d\n", y);
			 return;
			}
			//y = 6;
			for(i=p->length-1;i>=0;i--)
			{
					if(p->a[i]==0)
						continue;
					if(i!=pos)
					{
						if(p->a[i]>0)
							printf(" + ");
						else
							printf(" - ");
					}
					if(i==p->length-1)
					{
					    if(p->a[i]==1)
					    	printf("x^%d", i);
					    else if(p->a[i]==-1)
					    	printf("-x^%d", i);
					    else if(p->a[i]>0)
							printf("%gx^%d", p->a[i], i);
						else
							printf("-%gx^%d", p->a[i]*-1.0, i);
					}
					else if(i>1)
					{
						if(p->a[i]==1)
							printf("x^%d", i);
						else if(p->a[i]==-1)
					    	printf("x^%d", i);
						else if(p->a[i]>0)
							printf("%gx^%d", p->a[i], i);
						else
							printf("%gx^%d", p->a[i]*-1.0, i);
					}
					else if(i==1)
					{
						if(p->a[i]==1)
					    	printf("x");
					    else if(p->a[i]==-1)
					    	printf("x");
	  			        else if(p->a[i]>0)
							printf("%gx", p->a[i]);
						else
							printf("%gx", -1.0*p->a[i]);
					}
					else if(i==0)
					{
						if(p->a[i]>0)
					    	printf("%g", p->a[i]);
					    else
					    	printf("%g", -1.0*p->a[i]);
					}
				}
			printf("\n");
}
struct poly* polyCopy(struct poly* p)
{
	struct poly* copy = polyCreate();
	int i;
	for(i=0;i<p->length;i++)
		copy = polySetCoefficient(copy,i,p->a[i]);
	return copy;
}
struct poly* polyAdd(struct poly *p0, struct poly* p1)
{
	struct poly* sum = polyCreate();
	int i, max;
	if(p0->length > p1->length)
		max = p0->length;
	else
		max = p1 -> length;
	for(i=0;i<max; i++)
	{
		if(p1->length-1>=i && p0->length-1 >=i)
		{
			sum= polySetCoefficient(sum,i,(p1->a[i]+p0->a[i]));
		}
		else if(p1->length-1 >=i)
			sum = polySetCoefficient(sum,i,(p1->a[i]));
		else
			sum = polySetCoefficient(sum,i,(p0->a[i]));
	}
	return sum;
}
struct poly* polyMultiply(struct poly* p0, struct poly* p1)
{
	struct poly* product = polyCreate();
	int i,max, y=0;
	max = (p0->length)-2+(p1->length);
	int m = p0->length;
	struct poly* sum = malloc(m*sizeof(struct poly));
	for(i=0;i<p0->length;i++)
	{
		 sum[i]= polyCreate();
		 sum[i] = polySetCoefficient(sum[i], (i), 0);
	}
	for(i=0;i<p0->length;i++)
	{
	    	if(p0->a[i]==0)
	    	{
	        	continue;
	    	}
			while(y<p1->length)
			{
				if(p1->a[y]==0)
					sum[i] = polySetCoefficient(sum[i], (i+y), 0);
				else
					sum[i] = polySetCoefficient(sum[i], (i+y), (p0->a[i]) *( p1->a[y]));
				y++;
			}
			y = 0;
	}
	y=0;
	/*for(i=0;i<p0->length;i++)
	//(5x^2 + 4x + 1) * (3x^2 + 2x + 1) = 15x^4 + 12x^3 + 3x^2 + 10x^3 + 8x^2 + 2x + 5x^2 + 4x + 1 = 15x^4 + 22x^3 + 16x^2 + 6x + 1
	{
		product = polyCopy(polyAdd(sum[i], product));
		sum[i] = polyDelete(sum[i]);
	}
	return product;*/
	return sum;
}
struct poly* polyPrime(struct poly* p)
{
	struct poly* der = polyCreate();
	int i;
	for(i=1;i<p->length;i++)
	{
		double x = i*(p->a[i]);
		if(p->a[i]!=0)
		der = polySetCoefficient(der,i-1,x);
	}
	return der;
}
double polyEval(struct poly*p, double x)
{
	double sum=0;
	int i;
	for(i=0;i<p->length;i++)
	{
		sum += (p->a[i])*pow(x,i);
	}
	return sum;
}
