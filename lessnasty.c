/*
 * lessnasty.c
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
 * constant pi & fixed params beta, omega_0
 */
#define pi 18.84955592153876/6
#define beta 0.25
#define omega_0 1.0

/*
 * slove ODE via Eular foward mathod
 */
double solve(double omega, int Nsteps)
{
  double t = 0;
  double dt = 6*pi / Nsteps;
  double x = 0;
  double dx =0;
  int i;
  
  printf("%15.8f %15.8f %15.8f\n", t, x, dx);
  
  /*
   * update in each timestep
   */
  for (i=0; i < Nsteps; ++i)
  {
    double xold = x;
    double dxold = dx;
    
    x += dt * dxold;
    dx += dt * (cos(omega*t) - pow(omega_0, 2)*xold - 2*beta*dxold);
    t += dt;
    printf("%15.8f %15.8f %15.8f\n", t, x, dx);
  }
  printf("\n");

  return 0;
}


int main(int argc, char* argv[])
{
  solve(atof(argv[1]), (int) atof(argv[2]));
  return 0;
}
