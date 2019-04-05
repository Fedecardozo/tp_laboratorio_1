int sumar(int x, int y)
{
    int resultado;

    resultado = x + y;

    return resultado;
}
int restar(int x, int y)
{
    int resultado;

    resultado = x - y;

    return resultado;
}
float dividir(int x, int y)
{
    float resultado;

    resultado =(float) x / y;

    return resultado;
}
int multiplicar(int x, int y)
{
    int resultado;

    resultado = x * y;

    return resultado;
}
int factorial(int x)
{
    int resultado=1;

    for(int i=1; i<=x; i++)
    {
        resultado= resultado * i;
    }
    return resultado;
}
