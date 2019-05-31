#include "Plex.h"
#include <iostream>

int main()
{
  std::cout << "Creating plex...\n";
  TPlex plex;
  TPoint point1(1, 2);
  TPoint point2(2, 3);
  TPoint point3(3, 1);

  std::cout << "Add line (1,2)-(2,3) to plex...\n";
  plex.Add(&point1,&point2);
  std::cout << "Add line (2,3)-(3,1) to plex...\n";
  plex.Add(&point2, &point3);
  std::cout << "Plex: \n";
  plex.Show();

  return 0;
}