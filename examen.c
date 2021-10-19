#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

void Captura(int Clave[N],char Nombre[N][50],float Estatura[N],float Sueldo[N]);
int BuscaMasAlto(float Estatura[N]);
void OrdenaSueldo(int Clave[N],char Nombre[N][50],float Estatura[N],float Sueldo[N]);
void Imprime(int Clave[N],char Nombre[N][50],float Estatura[N],float Sueldo[N]);

int main()
{
    int Clave[N];
    char Nombre[N][50];
    float Estatura[N];
    float Sueldo[N];
    
    Captura(Clave,Nombre,Estatura,Sueldo);
    BuscaMasAlto(Estatura);
    OrdenaSueldo(Clave,Nombre,Estatura,Sueldo);
    Imprime(Clave,Nombre,Estatura,Sueldo);
}

void Captura(int Clave[N],char Nombre[N][50],float Estatura[N],float Sueldo[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("Empleado numero %d\n",i+1);
        printf("Ingrese la clave: ");
        scanf("%d",&Clave[i]);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(Nombre[i]);
        printf("\nIngrese la estatura: ");
        scanf("%f",&Estatura[i]);
        printf("Ingrese el sueldo: ");
        scanf("%f",&Sueldo[i]);
    }
}
int BuscaMasAlto(float Estatura[N])
{
    int i,PosAlto;
    float EstaturaAlto=0;
    for(i=0;i<N;i++)
    {
        if(Estatura[i]>EstaturaAlto)
        {
            EstaturaAlto=Estatura[i];
            PosAlto=i;
        }
    }
    printf("El empleado mas alto es el %d que ingreso",PosAlto+1);
    return PosAlto;
}

void OrdenaSueldo(int Clave[N],char Nombre[N][50],float Estatura[N],float Sueldo[N])
{
    int i,j,TempClave;
    char TempNombre[50];
    float TempEstatura,TempSueldo;
    
    for(i=0;i<N-1;i++)
    {
    for(j=0;j<N-1;j++)
    {
        if(Sueldo[j]>Sueldo[j+1])
        {
            TempSueldo=Sueldo[j];
            Sueldo[j]=Sueldo[j+1];
            Sueldo[j+1]=TempSueldo;TempClave=Clave[j];
            Clave[j]=Clave[j+1];
            Clave[j+1]=TempClave;
            strcpy(TempNombre,Nombre[j]);
            strcpy(Nombre[j],Nombre[j+1]);
            strcpy(Nombre[j+1],TempNombre);TempEstatura=Estatura[j];
            Estatura[j]=Estatura[j+1];
            Estatura[j+1]=TempEstatura;
        }
    }
    }
}

void Imprime(int Clave[N],char Nombre[N][50],float Estatura[N],float Sueldo[N])
{
    int i;
    printf("\nClave\tNombre\tEstatura\tSueldo");
    for(i=0;i<N;i++)
    {
        printf("\n%i\t%s\t%.02f\t\t%.02f",Clave[i],Nombre[i],Estatura[i],Sueldo[i]);
    }
}


