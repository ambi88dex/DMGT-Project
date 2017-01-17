#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *f;
    int n;
    f= fopen("matrix.txt","r");
    fscanf(f,"%d",&n);
    printf("Enter the length of the reflexive matrix\n");
    int i,j,x,col,hor,k;
    int refl=1,symm=1,trans=1,antisymm=1,poset=0,lattice=0,ct;
    int ls_up_bd=0,gr_lw_bd=0;
    //scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(f,"%d",&a[i][j]);
        }
    }
    //checking reflexivity
    for(i=0;i<n&&refl==1;i++)
    {
        if(a[i][i]==0)
        {
            refl=0;
        }
    }
	if(refl==1)
	{
		printf("Reflexive relation\n");
	}
	else
	{
		printf("Not Reflexive relation\n");
	}
    //checking symmetricity
    for(i=0;i<n&&symm==1;i++)
    {
        for(j=i+1;j<n&&symm==1;j++)
        {
            if(a[i][j]!=a[j][i])
            {
                symm=0;
            }
        }
    }
    for(i=0;i<n&&antisymm==1;i++)
    {
        for(j=i+1;j<n&&symm==1;j++)
        {
            if((a[i][j]==a[j][i])&& (a[i][j]==1))
            {
                antisymm=0;
            }
        }
    }
	if(symm==1)
	{
		printf("Symmetric relation\n");
	}
	else if(antisymm==1)
	{
		printf("AntiSymmetric relation\n");
	}
    //checking transitivity
    for(i=0;i<n&&trans==1;i++)
    {
        for(j=0;j<n&&trans==1;j++)
        {
            if((a[i][j]==1)&&(i!=j))
            {
                for(k=0 ; k < n;k++)
                {
                    if((a[j][k] == 1) && (j!=k))
                    {
                        if(a[j][k]==0)
                        {
                            trans = 0;
                        }
                    }
                }
            }
        }
    }
	if(trans==1)
	{
		printf("Transitive relation\n");
	}
	else
	{
		printf("Not Transitive relation\n");
	}
	if( refl==1 && symm==1 && trans ==1)
	{

		printf("Equivalence Relation\n");
	}
	else if( refl==1 && antisymm==1 && trans ==1)
	{
		poset=1;
	}

	if(poset ==1 )
	{
        printf("Poset\n");
        ct=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j;k < n;k++)
                {
                    if(a[i][k] + a[j][k]==2)
                    {
                        ct++;
                    }
                }
                if(ct)
                {
                    ls_up_bd++;
                }
                ct=0;
                for(k=i;k>=0;k--)
                {
                    if(a[k][i] + a[k][j]==2)
                    {
                        gr_lw_bd++;
                    }
                }
            }
        }
        if((gr_lw_bd == ls_up_bd)&& (gr_lw_bd == (n*(n-1))/2))
        {
            lattice=1;
        }
	}
	if(lattice==1)
	{
        printf("Lattice\n");
	}

    return 0;
}
