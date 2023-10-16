#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n)
{
    int x, y, z, r, num;
    x = 0;
    y = 0;
    z = 0;
    num = 0;
    while (num < n){
        r = rand() % 6;

        if (r == 0){    
            x -= 1;    
        }
        if (r == 1){    
            x += 1;    
        }

        if (r == 2){    
            y += 1;    
        }

        if (r == 3){    
            y -= 1;    
        }

        if (r == 4){    
            z += 1;    
        }
        if (r == 5){    
            z -= 1;    
        }

        num += 1;
    }
    grid[(x*x) + (y*y) + (z*z)] += 1;
}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
    double sum = 0.0; 
    double total = 0.0;
    int dist1 = n * n + 1;
    int dist2 = r * r * n * n;
    
    for (int i = 0; i < dist1; i++){
        if (grid[i] >= 1){
            total += grid[i];
            if (i <= dist2){
                sum += grid[i];
            }
        }
    }
    
    float fract = sum / total;
    return fract;
}

//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
    int *grid;    
    grid = (int *) calloc(n * n + 1, sizeof(int));

	for (int i = 1; i <= m; i++) {
        one_particle(grid, n);
    }

	print_result(grid, n);
	//fill in some code below
    free(grid);
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}
