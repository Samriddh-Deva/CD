
#include<stdio.h>
void main(){
    int dbmsT,dbmsA, cdT,cdA, cgT,cgA, ascT,ascA, cileT,cileA, daaT, daaA;

    float dbms_percentage,cd_percentage,daa_percentage,cg_percentage,asc_percentage,cile_percentage, total_classes, total_attended, total_percentage;
//NOW CALCULATING ATTENDANCE FOR DBMS
    printf("Enter total number of classes then enter the total classes you have attended.");
    printf("\n\tEnter the total classes held in DBMS\n");
    scanf("%d",&dbmsT);
    printf("Enter the total classes you have attended out of %d\n", dbmsT);
    scanf("\n\t%d",&dbmsA);
    dbms_percentage = (float)dbmsA/dbmsT * 100.0;
    printf("Your attendance in DBMS is = %f", dbms_percentage);

// NOW CALCULATING ATTENDANCE FOR Cmpiler design
   printf("\n\tEnter the total classes held in Compiler Design\n");
   scanf("\n\t%d",&cdT);
   printf("Enter the total classes you have attended out of %d\n", cdT);
    scanf("\n\t%d",&cdA);
    cd_percentage = (float)cdA/cdT*100;
    printf("Your attendace in CD is = %f", cd_percentage);

// NOW CALCULATING ATTENDANCE FOR DAA
   printf("\n\tEnter the total classes held in DAA\n");
   scanf("\n\t%d",&daaT);
   printf("\n\tEnter the total number of classes you have attended out of %d\n", daaT);
   scanf("\n\t%d",&daaA);
   daa_percentage= (float)daaA/daaT*100;
   printf("Your total attendance in DAA is %f", daa_percentage );

// NOW CALCULATING ATTENDANCE FOR Computer Graphics
    printf("\n\tEnter the total classes held in computer graphics\n");
    scanf("\n\t%d", &cgT);

    printf("\n\tEnter the total classes you have attended in CG out of %d\n", cgT);
    scanf("\n\t%d",&cgA);
    cg_percentage= (float)cgA/cgT*100;
    printf("Your attendace in Computer graphics is %f\n", cg_percentage);

// NOW CALCULATING ATTENDANCE OF Constitution

    printf("\n\tEnter the total classes held in Constitution\n");
    scanf("\n\t%d",&cileT);
    printf("\n\tEnter the number of classes you have attended out of %d\n",cileT);
    scanf("\n\t%d",&cileA);
    cile_percentage= (float)cileA/cileT*100;
    printf("\n\tYour attendance in Constitution is = %f\n", cile_percentage);

//NOW CALCULATING ATTENDACE OF ASC
    printf("\n\tEnter the total classes held in Soft computing\n");
    scanf("\n\t%d",&ascT);
    printf("\n\tEnter the total number of classes you have attended ot of %d\n",ascT);
    scanf("\n\t%d",&ascA);
    asc_percentage=(float)ascA/ascT*100;
    printf("\n\tYour attendance in Soft computing is = %f\n",asc_percentage);
    total_classes = dbmsT+cdT+daaT+ascT+cgT+cileT;
    total_attended = dbmsA+cdA+daaA+ascA+cgA+cileA;
    total_percentage = (float)total_attended/total_classes*100;
    printf("\n\tYour overall attendace is %f\n", total_percentage);

    printf("Please note this attendance is excluding LAB CLASSES");


}
