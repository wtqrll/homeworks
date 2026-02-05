#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(){
    double x1, y1, r1;
    double x2, y2, r2;

    printf("Zadejte parametry kruznice #1:\n");
    if (scanf("%lf %lf %lf", &x1, &y1, &r1) != 3 || r1 <= 0){
        printf("Nespravny vstup.\n");
        return 0;
    }
   
    printf("Zadejte parametry kruznice #2:\n");
    if (scanf("%lf %lf %lf", &x2, &y2, &r2) != 3 || r2 <= 0){
        printf("Nespravny vstup.\n");
        return 0;
    }
    

    double R, r;
    if (r1 > r2) {
        R = r1;
        r = r2;
    } else {
        R = r2;
        r = r1;
    }
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx * dx + dy * dy);
 
        
    if (r1 + r2 == d) {
        printf("Vnejsi dotyk, zadny prekryv.\n");
        return 0;
    }

    if (d == 0 && r1 == r2) {
        printf("Kruznice splyvaji, prekryv: %.6f\n", PI * r1 * r1);
        return 0;
    }

    if (d + r < R) {
        printf("Jedna kružnice leží zcela uvnitř druhé, prekryv: %.6f\n", PI * r * r);
        return 0;
    }

    if (d + r <= R) {
        printf("Vnitrni dotyk, kruznice #2 lezi uvnitr kruznice #1, prekryv: %.6f\n", PI * r * r);
        return 0;
    }

    if (d > R + r) {
        printf("Kruznice lezi vne sebe, zadny prekryv.\n");
        return 0;
    }
    
    if (d > (R - r) && d < (r + R)) {
        printf("Kruznice se protinaji, prekryv: %.6f\n", 
        r*r * acos((d*d + r*r - R*R) / (2.0 * d * r)) + R*R * acos((d*d + R*R - r*r) / (2.0 * d * R))
      - 0.5 * sqrt((-d + r + R) * ( d + r - R) * ( d - r + R) * ( d + r + R)));
      return 0;
    }

return 0;
}