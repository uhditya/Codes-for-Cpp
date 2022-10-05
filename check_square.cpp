#include<bits/stdc++.h>
using namespace std;

struct Point {
   int x, y;
};

int Dist(Point p, Point q) {
   return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}

bool check_square(Point p1, Point p2, Point p3, Point p4) {     
   int dist12 = Dist(p1, p2);     
   int dist13 = Dist(p1, p3);     
   int dist14 = Dist(p1, p4);     

   //Here since the point are not given in any order, we check all possible combinations;

   //By laws of geometry, the sqaure of distance of the diagonal should be twice the square of distance between any 2 sides.
   //And we also check if the distance of a point from 2 possible sides is same or not, if not, we move to the next combination.

   if (dist12 == dist13 && 2*dist12 == dist14) {
      int dist = Dist(p2, p4);
      return (dist == Dist(p3, p4) && dist == dist12);
   }

   //same condition for all other combinations
   if (dist13 == dist14 && 2*dist13 == dist12) {
      int dist = Dist(p2, p3);
      return (dist == Dist(p2, p4) && dist == dist13);
   }

   if (dist12 == dist14 && 2*dist12 == dist13) {
      int dist = Dist(p2, p3);
      return (dist == Dist(p3, p4) && dist == dist12);
  }
  return false;
}

int main() {
   Point p1 = {20, 10}, p2 = {10, 20}, p3 = {20, 20}, p4 = {10, 10};
   if(check_square(p1, p2, p3, p4))
      cout << "True";
   else
      cout << "False";
}
